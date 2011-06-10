#include "parser.h"
#include "report_error.h"
#include <string>
#include <sstream>
#include <cstdlib>


using namespace std;

parser::parser(){
  this->l = new line_counter();
  this->st = new symboltable(); // global scope
  this->s = new scanner(*l,*st);
  error_flag=false;
  ever_error = false;
}

parser::parser(scanner& s,line_counter& l,symboltable& st, code_writer& c){
  this->s = &s;
  this->l = &l;
  this->st = &st;
  this->c = &c;
  error_flag=false;
  ever_error = false;
  this->next_token = new token(this->s->scan());
}

void parser::attach_scanner(scanner&s){
  this->s = &s;
  this->next_token = new token(this->s->scan());
}

void parser::reset_error(){
  if(error_flag){
    ever_error = true;
  }
  error_flag= false;
}

bool parser::parse(){
  int tm;
  tm = type_mark();
  //  cout << "global st: " << st << endl;
  token globaltoken(-1,"_GLOBAL");
  st->add(globaltoken);
  st->set_function(globaltoken,vector<pair<token*,int> >());
  st->set_ftoken(globaltoken);
  function_declaration(tm);
  //return !error_flag;
  return !ever_error;
}

void parser::scan_next_token(){
  if(s->good() && !error_flag){
    *next_token = s->scan();
#ifdef DEBUG
    cout << "Got new token: " << *next_token << endl;
#endif
  }
}

bool parser::check_token_type(int type, const char* expected){
  if(error_flag){return false;}
  if(next_token->get_type() != type){
    char error[255];
    sprintf(error,"Syntax Error! %s expected.",expected);
    report_error(error,l->get_linenumber(),*next_token);
    panic();
    error_flag = true;
    return false;
  }
  return true;
}

bool parser::check_types(int type1, int type2){
  if(type1 == type2){
    return true;
  }else{
    if(type1 >= 0 && type2 >= 0){
      cout << "type 1: " << type1 << "\t type2: " << type2 <<endl;
      report_error("Type mismatch ", l->get_linenumber());
      error_flag = true;
    }
    return false;
  }
}
bool parser::check_array_sizes(int s1, int s2){
  if(s1 == s2){
    return true;
  }else{
    report_error("Array size mismatch ", l->get_linenumber());
    error_flag = true;
    return false;
  }
}

void parser::panic(){
  if(error_flag)
    reset_error();
  while(next_token->get_type()!=END && next_token->get_type()!= EOFMARKER && next_token->get_type() != SEMICOLON){
#ifdef DEBUG
    cout << "PANIC MODE! Skipping " << *next_token << endl;
#endif
    scan_next_token();
  }
  if(next_token->get_type()==END){
    debug("last token was end, getting a new one.");
    scan_next_token();
  }
  if(next_token->get_type()==EOFMARKER){
    debug("Panicked to end of file.");
    return;
  }
  if(next_token->get_type() == SEMICOLON)
    return;
  scan_next_token();
}

bool parser::is_error(){
  return error_flag;
}

void parser::function_declaration(int typemark){
  //  if(error_flag){error_flag=false;}
  debug("enter function_declaration");
  string lblfunc = c->get_next_label();
  string lblendfunc = c->get_next_label();
  c->write_code("goto " + lblendfunc +";\n");
  c->write_code(lblfunc + ": ");

  token ftoken = function_header(typemark);
  
  //st->set_ftoken(ftoken);
  st->set_label(ftoken,lblfunc);
  st->get_label(ftoken);
  add_scope(ftoken);
  function_body(ftoken);
 
  c->write_code("R[2] = MM[R[0]+1];\n");
  c->write_code("goto *R[2]; //write return statement\n"); //write return statement
  c->write_code(lblendfunc + ":");
  remove_scope();
  if(next_token->get_type() != EOFMARKER){
    reset_error();
  }
  debug("exit function_declaration");
}

token parser::function_header(int typemark){
  if(error_flag){return token();}
  debug("enter function_header");
  check_token_type(FUNCTION,"'function'");
  scan_next_token();
  token ftoken = *next_token;
  //  cout << "candidate function: " << ftoken << endl;
  identifier(typemark);
  vector<pair<token*,int> > plist = vector<pair<token*,int> >();
  map<int, pair<int,int> > arrayparams = map<int, pair<int,int> >();
  check_token_type(LPAREN,"'('");
  scan_next_token();
  if(next_token->get_type()!=RPAREN){
    parameter_list(&plist,&arrayparams);
  }
  check_token_type(RPAREN,"')'");
  ftoken = *st->add(ftoken); // add to current scope if not already there
  //cout << "about to set function for ftoken " << ftoken << endl;
  st->set_function(ftoken,plist,arrayparams); // add function and parameterlist to symboltable
  st->set_offset(ftoken,0);
  /*vector<int> tmp = *(st->get_parameterlist(ftoken));
  for(vector<int>::const_iterator it = tmp.begin(); it!=tmp.end(); it++){
    cout << *it << endl;
    }*/
  scan_next_token();
  debug("exit function_header");
  return ftoken;
}
 void parser::parameter_list(vector<pair<token*,int > > * plist, map<int, pair<int,int> > *arrayparams){
  if(error_flag){return;}
  debug("enter parameter_list");
  pair<int,token> param = parameter();
  int ptype = param.first;
  token ptok = param.second;
  if(ptype>=0){
    plist->push_back(pair<token*,int>(new token(ptok),ptype));
    if(ptype == ARRAYTYPE){
      int parraysize = st->get_arraysize(ptok);
      int parraytype = st->get_tokentype(ptok);
      /*      cout << "for array parameter " << ptok << ": " << endl
	   << "parraysize: " << parraysize << endl
	   << "parraytype: " << parraytype <<endl;*/
      (*arrayparams)[plist->size()-1] = pair<int,int>(parraytype,parraysize);
    }
  }
  if(next_token->get_type()==COMMA){
    check_token_type(COMMA,"','");
    scan_next_token();
    parameter_list(plist,arrayparams);
  }
  debug("exit parameter_list");
}

pair<int,token> parser::parameter(){
  if(error_flag){return pair<int,token>(-1,token());}
  debug("enter parameter");
  int tm = type_mark();
  token paramname = *next_token;
  //variable_declaration(tm);
  //identifier(tm);
  check_token_type(ID,"identifier");
  scan_next_token();
  
  if(next_token->get_type() == LBRACKET){
    check_token_type(LBRACKET,"'['");
    scan_next_token();
    check_token_type(NUMBER,"array size");
    int arraysize = atoi((next_token->get_value()).c_str());
    st->set_arraysize(paramname,arraysize);
    scan_next_token();
    check_token_type(RBRACKET,"']'");
    scan_next_token();  

    tm = ARRAYTYPE;
  }


  debug("exit parameter");
  return pair<int,token>(tm,paramname);
}
void parser::function_body(token ftoken){
  if(error_flag){return;}
  debug("enter function_body");
  debug("adding parameters to st");
  stringstream ss;
  vector<pair<token*,int> > plist = *(st->get_parameterlist(ftoken));
  for(vector<pair<token*,int> >::iterator it = plist.begin(); it != plist.end(); it++){
    int tt = it->second;
    token argtok = *(it->first);
    //add arg to symbol table
    argtok = *st->add(argtok);
    st->set_tokentype(argtok,tt);
    st->set_offset(argtok,st->get_ardepth(st->get_ftoken()));
    if(tt == ARRAYTYPE){
      int arraysize = st->get_arraysize(argtok);
      ss << "R[1] = R[1] + " << arraysize  << "; //allocate space for array arg "  
	 << argtok.get_value()  << endl;
      st->set_ardepth(st->get_ftoken(),st->get_ardepth(st->get_ftoken()) + arraysize);
    }else if(tt == INTEGERTYPE || tt == BOOLEANTYPE || tt == STRINGTYPE){
      ss << "R[1] = R[1] + 1; //allocate space for arg " << argtok.get_value()  << endl;
      st->increment_ardepth(st->get_ftoken());
    }
  }
  c->write_code(ss.str());
  debug("done adding parameters to st");

  bool returned = false;
  while(next_token->get_type()!=BEGIN && next_token->get_type() != EOFMARKER ){
    //declarations
    declaration();
    check_token_type(SEMICOLON,"';'");
    reset_error();
    scan_next_token();
  }
  check_token_type(BEGIN,"'begin'");
  scan_next_token();
  while(next_token->get_type()!=END && next_token->get_type() != EOFMARKER){
    reset_error();
    if(next_token->get_value() == ftoken.get_value()){
      assignment_statement();
      if(!error_flag){
	returned = true;
	check_token_type(SEMICOLON,"';'");
	scan_next_token();
	break;
      }
    }
    statement();
    check_token_type(SEMICOLON,"';'");
    reset_error();
    scan_next_token();
  }

  check_token_type(END,"'end'");
  scan_next_token();
  check_token_type(FUNCTION,"'function'");
  scan_next_token();
  if(!returned){//error
    string errormsg = string("No return statement for function ").append(string(ftoken.get_value()));
    report_error(errormsg ,l->get_linenumber());
  }
  debug("exit function_body");
}

void parser::declaration(){
  if(error_flag){return;}
  debug("enter declaration");
  int tm = type_mark();
  declaration2(tm);
  debug("exit declaration");
}

void parser::declaration2(int tm){
  if(error_flag){return;}
  debug("enter declaration2");
  if(next_token->get_type()==FUNCTION){
    function_declaration(tm);
  }else{
    variable_declaration(tm);
  }
  debug("exit declaration2");
}

void parser::variable_declaration(int tm){
  if(error_flag){return;}
  debug("enter variable_declaration");
  token varid = *next_token;
  identifier(tm);
  varid = *st->add(varid); // add to current scope if not already there
  

  if(next_token->get_type() == LBRACKET){
    check_token_type(LBRACKET,"'['");
    scan_next_token();
    check_token_type(NUMBER,"array size");
    int arraysize = atoi((next_token->get_value()).c_str());
    st->set_arraysize(varid,arraysize);
    scan_next_token();
    check_token_type(RBRACKET,"']'");
    scan_next_token();  
  }

  //allocate memory for variable
  stringstream ss;
  token ftoken = st->get_ftoken();
  int ardepth = st->get_ardepth(ftoken);
  st->set_offset(varid,ardepth);

  if(st->is_array(varid)){
    int arraysize = st->get_arraysize(varid);
    ss << "R[1] = R[1] + " << arraysize << "; // allocate space for array " 
       << varid.get_value() << endl;
    st->set_ardepth(ftoken, ardepth + arraysize);
  }else if(tm == INTEGERTYPE || tm == BOOLEANTYPE || tm == STRINGTYPE){
    ss << "R[1] = R[1] + 1; //allocate space for var" << varid.get_value() << endl;
    st->increment_ardepth(ftoken);
  }if(tm == STRINGTYPE){
    //if its a string, we've already allocated space on stack for the
    //ptr, but we need to allocate room in the string table.  or maybe
    //we dont. this should be the job of whatever code assigns a value
    //to the var.
  }
  c->write_code(ss.str());
  debug("exit variable_declaration");
}
int parser::type_mark(){
  if(error_flag){return -1;}
  debug("enter type_mark");
  int tm=0;
  check_token_type(TYPE,"type mark");
  
  string val = next_token->get_value();

  switch (val[0]){
  case 'i':
    tm =  INTEGERTYPE;
    break;
  case 'b':
    tm = BOOLEANTYPE;
    break;
  case 's':
    tm = STRINGTYPE;
    break;
    }
  scan_next_token();
  debug("exit type_mark");
  return tm;
  
}

void parser::statement(){
  if(error_flag){return;}
  debug("enter statement");
  switch(next_token->get_type()){
  case IF:
    if_statement();
    break;
  case WHILE:
    while_statement();
    break;
  case CASE:
    case_statement();
    break;
  default :
    assignment_statement();
  }
  debug("exit statement");
}

void parser::assignment_statement(){
  if(error_flag){return;}
  debug("enter assignment_statement");
  stringstream ss;
  int* idxreg;
  idxreg = new int(c->get_next_free_reg());
  c->use_reg(*idxreg);
  token desttok = *next_token;

  int tt1 = destination(ss,idxreg);
  check_token_type(ASSIGN,":=");

  scan_next_token();
  
  token assgntok = *next_token;

  int* expressionreg;
  expressionreg = new int(c->get_next_free_reg());
  c->use_reg(*expressionreg);
  int tt2 = expression(expressionreg);

  check_types(tt1,tt2);

  if(tt2 == ARRAYTYPE){ 
    //it's an array, not indexed.  need to check that they are same
    //size and then copy elements
    int arraysize = st->get_arraysize(desttok);
    check_array_sizes(arraysize,st->get_arraysize(assgntok));
    int destoffset = st->get_offset(desttok);
    int assgnoffset = st->get_offset(assgntok);
    int* tmpreg = new int(c->get_next_free_reg());
    c->use_reg(*tmpreg);
    for(int i = 0; i < arraysize; i++){
      ss << "R[" << *tmpreg << "] = MM[R[0] + " << assgnoffset + i << "]; // arr " 
	 << assgntok.get_value() << " element " << i << endl
	 << "MM[R[0] + " << destoffset + i << "] = R[" << *tmpreg << "]; //dest arr " 
	 << desttok.get_value() << " element " << i << endl;
    }
    
  }else{
    ss << " = R[" << *expressionreg << "]; //assignment_statement" << endl;
  }
  c->write_code(ss.str());
  c->free_reg(*expressionreg);
  c->free_reg(*idxreg);
  debug("exit assignment_statement");
}

int parser::destination(stringstream& ss, int* idxreg){
  if(error_flag){return -1;}
  debug("enter destination");
  token potentialarraytok = *next_token;
  int tt = identifier();
  if(next_token->get_type() == LBRACKET){ //array
    if(!st->is_array(potentialarraytok)){
      report_error("Indexing a non-array: " + potentialarraytok.get_value() + " is not an array.",l->get_linenumber());
    }
    scan_next_token();

    // do we need to check the type returned for the index expression?
    // Should at least not be string...
    expression(idxreg);

    int* tmpreg = new int(c->get_next_free_reg());
    c->use_reg(*tmpreg);
    ss << "R[" << *tmpreg << "] = R[0] + R[" << *idxreg 
       << "]; // calc array offset" << endl //add index offset
       << "MM[R[" << *tmpreg << "] + " << st->get_offset(potentialarraytok) << "]";
    check_token_type(RBRACKET,"]");
    scan_next_token();
  }else{
    //if destination is an array variable, not an indexed entry of the
    //array, return ARRAYTYPE so above knows to not write code, just
    //change offset.
    if(st->is_array(potentialarraytok)){
      tt = ARRAYTYPE;
    }else{
      ss << "MM[R[0] + " << st->get_offset(potentialarraytok) << "]";
    }
  }
  debug("exit destination; tt is " , tt);
  return tt;
}
void parser::if_statement(){
  if(error_flag){return;}
  debug("enter if_statement");

  check_token_type(IF,"'if'");
  scan_next_token();
  
  stringstream ss;
  string lblelse, lblend;
  int* reg = new int(c->get_next_free_reg());
  c->use_reg(*reg);
  
  expression(reg);

  lblelse = c->get_next_label();
  lblend = c->get_next_label();

  ss << "R[" << *reg <<"] = !R[" << *reg <<"]; //if" << endl;
  ss << "if(R[" << *reg <<"]) goto " << lblelse << "; //if" << endl;

  check_token_type(THEN,"'then'");
  scan_next_token();
  c->write_code(ss.str());
  do{
    statement();
      
    check_token_type(SEMICOLON,"';'");
    reset_error();
    scan_next_token();
  }while(next_token->get_type()!=ELSE && next_token->get_type()!=END && next_token->get_type()!=EOFMARKER  );
  ss.str(""); // clear the stringstream
  ss << "goto " << lblend << "; //if" << endl
     << lblelse << ": ";
  c->write_code(ss.str());
  if(next_token->get_type() == ELSE){
    scan_next_token();
    ss.str(""); // clear the stringstream
    ss << "R[" << *reg <<"] = !R[" << *reg <<"]; //if" << endl;
    ss << "if(R[" << *reg <<"]) goto " << lblend << "; //if" << endl;
    c->write_code(ss.str());
    do{
      statement();
      
      check_token_type(SEMICOLON,"';'");
      reset_error();
      scan_next_token();
    }while(next_token->get_type()!=END && next_token->get_type()!=EOFMARKER );
  }
  c->write_code(lblend + ": ");
  
  c->free_reg(*reg);
  check_token_type(END,"'end'");
  scan_next_token();
  
  check_token_type(IF,"'if'");
  scan_next_token();

  debug("exit if_statement");
}
void parser::while_statement(){
  if(error_flag){return;}
  debug("enter while_statement");
  check_token_type(WHILE,"'while'");
  scan_next_token();

  string lblwhile, lblend;
  stringstream ss;

  lblwhile = c->get_next_label();
  lblend = c->get_next_label();
  
  c->write_code(lblwhile + ": ");
  int* reg = new int(c->get_next_free_reg());
  c->use_reg(*reg);
  
  expression(reg);

  ss << "R[" << *reg <<"] = !R[" << *reg <<"]; //while" << endl;
  ss << "if(R[" << *reg <<"]) goto " << lblend << "; //while" << endl;

  c->write_code(ss.str());

  while(next_token->get_type()!=END && !error_flag && next_token->get_type()!=EOFMARKER){
    statement();
    
    check_token_type(SEMICOLON,"';'");
    reset_error();
    scan_next_token();
  }
  c->write_code("goto " + lblwhile + ";\n");
  c->free_reg(*reg);
  c->write_code(lblend + ": ");
  check_token_type(END,"'end'");
  scan_next_token();

  check_token_type(WHILE,"'while'");
  scan_next_token();
  debug("exit while_statement");
}

void parser::case_statement(){
  if(error_flag){return;}
  debug("enter case_statement");
  check_token_type(CASE,"'case'");
  scan_next_token();
  int* exprreg = new int(c->get_next_free_reg());
  c->use_reg(*exprreg);
  expression(exprreg);

  int* casereg = new int(c->get_next_free_reg());
  c->use_reg(*casereg);
  
  check_token_type(IS,"'is'");
  scan_next_token();

  string lblendcase = c->get_next_label();
  do{
    check_token_type(WHEN,"'when'");
    scan_next_token();
  
    string num = next_token->get_value();
    check_token_type(NUMBER,"number");
    scan_next_token();
    
    check_token_type(THEN,"'then'");
    scan_next_token();
    
    string lblendwhen = c->get_next_label();
    stringstream ss;
    ss << "R[" << *casereg << "] = R[" << *exprreg << "] == " << num << "; //case" << endl
       << "R[" << *casereg << "] = !R[" << *casereg << "]; //case" << endl
       << "if(R[" << *casereg << "]) goto " << lblendwhen << "; //case" << endl;
    c->write_code(ss.str());
    do{
      statement();    
      check_token_type(SEMICOLON,"';'");
      reset_error();
      scan_next_token();
    }while(next_token->get_type()!=WHEN &&next_token->get_type()!=DEFAULT && next_token->get_type()!=END && next_token->get_type()!=EOFMARKER);
    c->write_code("goto " + lblendcase + ";\n");
    c->write_code(lblendwhen + ":");
  }while(next_token->get_type()!=DEFAULT && next_token->get_type()!=END && next_token->get_type()!=EOFMARKER);
  
  if(next_token->get_type()==DEFAULT){
    check_token_type(DEFAULT,"'default'");
    scan_next_token();

    check_token_type(THEN,"'then'");
    scan_next_token();
    while(next_token->get_type()!=END && !is_error() && next_token->get_type()!=EOFMARKER){
      statement();
      check_token_type(SEMICOLON,"';'");
      reset_error();
      scan_next_token();
    }
  }
  c->write_code(lblendcase + ":");
  check_token_type(END,"'end'");
  scan_next_token();
  
  check_token_type(CASE,"'case'");
  scan_next_token();
  debug("exit case_statement");
}
int parser::identifier(){
  return identifier(-1);
}
int parser::identifier(int typemark){
  if(error_flag){return -1;}
  debug("enter identifier");
  check_token_type(ID,"identifier");
  //cout << *next_token << endl;
  if(typemark >=0){
    st->set_tokentype(*next_token,typemark);
  }
  //cout << *st << endl;
  int tt = st->get_tokentype(*next_token);
  if( tt < 0){
    report_error("Undeclared function or variable: " + next_token->get_value(), l->get_linenumber());
    //cout << *st << endl;
    
    panic();
    error_flag = true;
  }
  scan_next_token();
  debug("exit identifier; tt is " , tt);
  return tt;
}
int parser::expression(){
  expression(new int(-1));
}
int parser::expression(int* reg){
  if(error_flag){return -1;}
  debug("enter expression");
  int tt;
  stringstream ss,ss2;
  bool neg = false;

  if(next_token->get_type() == NOT){
    neg = true;
    scan_next_token();
  }

  tt = arithOp(reg);

  int tt2 = expression2(ss2);

  if(tt2>=0){
    // if there's a tt2 then there was a logical operator, thus type
    // must be bool.
    check_types(tt,BOOLEANTYPE);
    check_types(tt,tt2);
    ss << "R[" << *reg << "] = R[" << *reg << "] " << ss2.str() << "; //expression" << endl;  
  }  
  if(neg){
    check_types(tt,BOOLEANTYPE);
    ss << "R[" << *reg << "] = !R[" << *reg << "];//expression" << endl;
  }
  c->write_code(ss.str());
  
  
  debug("exit expression; tt is " , tt);
  return tt;
}
int parser::expression2(){
  stringstream ss;
  return expression2(ss);
}
int parser::expression2(stringstream& ss){
  if(error_flag){return -1;}
  debug("enter expression2");
  int tt = -1, tt2=-1;
  string op = "";
  stringstream ss2;
  int* reg;
  reg = new int(c->get_next_free_reg());
  c->use_reg(*reg);

  switch(next_token->get_type()){
  case AND:
    op = "&&";
    scan_next_token();
    tt = arithOp(reg);
    tt2 = expression2(ss2);
    break;
  case OR:
    op = "||";
    scan_next_token();
    tt = arithOp(reg);
    tt2 = expression2(ss2);
    break;
  }
  if(tt2 >= 0){
    check_types(tt,tt2);
    ss2 << "R[" << *reg << "] = R[" << *reg << "]" << ss2.str() << "; //expr2" << endl;
    c->write_code(ss2.str());
  } if(tt >=0){
    ss << op << " R[" << *reg << "]";
  }
  c->free_reg(*reg);
  debug("exit expression2; tt is " , tt);
  return tt;
}
int parser::arithOp(){
  return arithOp(new int(-1));
}
int parser::arithOp(int * regnum){
  if(error_flag){return -1;}
  debug("enter arithOp");
  int tt =-1, tt2 = -1;
  stringstream ss, ss2;

  tt = relation(regnum);

  tt2 = arithOp2(ss2,regnum);


  if(tt2 >=0){
    // arith ops defined only on ints so must force check that they
    // are both ints.
    check_types(tt,INTEGERTYPE);
    check_types(tt,tt2);
    ss << "R[" << *regnum << "] = R[" << *regnum << "]" << ss2.str() ;//<< "; //arithop1" << endl;
    c->write_code(ss.str());
  }

  
  debug("exit arithOp; tt is " , tt);
  return tt;
}

int parser::arithOp2(stringstream & ss,int* arithreg){
  if(error_flag){return -1;}
  debug("enter arithOp2");
  int tt = -1, tt2=-1;
  bool hadOp = false;
  switch(next_token->get_type()){
  case ADD:
    ss << " + " ;
    hadOp = true;
    break;
  case SUB:
    ss << " - " ;
    hadOp = true;
    break;
  case BITAND:
    ss << " & " ;
    hadOp = true;
    break;
  case BITOR:
    ss << " | " ;
    hadOp = true;
    break;
  }
  if(hadOp){
    scan_next_token();
    int * reg; 
    reg = new int(c->get_next_free_reg());
    stringstream ss2;
    c->use_reg(*reg);
    tt = relation(reg);
    tt2 = arithOp2(ss2,arithreg);
    if(tt2>=0){
      // arith ops defined only on ints so must force check that they
      // are both ints.
      check_types(tt,INTEGERTYPE);
      check_types(tt,tt2);
      ss << "R[" << *reg << "]; //arithop 2" << endl;
      c->free_reg(*reg);

      ss << "R[" << *arithreg << "] = R[" << *arithreg << "]"<< ss2.str();//<< "; //arithop2" << endl;
    }else{
      ss << "R[" << *reg << "]; //arithop 2" << endl;
      c->free_reg(*reg);
    }
  }
  debug("exit arithOp2; tt is " , tt);
  return tt;
}

int parser::relation(int * regnum){
  if(error_flag){return -1;}
  debug("enter relation");
  int tt = -1, tt2 = -1;
  stringstream ss,ss2;

  tt = term(regnum);
  tt2 = relation2(ss2,regnum);
  if(tt2>=0){
    check_types(tt,tt2);
    ss << "R[" << *regnum << "] = R[" << *regnum << "]" << ss2.str() << "; //relation " << endl;
    c->write_code(ss.str());
    // relation ops are defined for any two operands, as long as they
    // are same type, but the op always returns bool; if in this
    // block, there is an op, so make the return type bool.
    tt = BOOLEANTYPE;
  }
  debug("exit relation; tt is " , tt);
  return tt;
}

int parser::relation2(stringstream& ss, int* reg1){
  if(error_flag){return -1;}
  debug("enter relation2");
  int tt=-1, tt2=-1;
  stringstream ss2;
  int * termreg;
  string op;
  
  if(next_token->get_type()==RELOP){
    op = next_token->get_value();
    scan_next_token();
    termreg = new int(c->get_next_free_reg());
    c->use_reg(*termreg);
    tt = term(termreg);
    tt2 = relation2(ss2,termreg);
  }
  if(tt2 >= 0){
    check_types(tt,tt2);
    stringstream ss3;

    ss3 << "R[" << *reg1  << "] = " << "R[" << *reg1  << "] " << op << " R[" << *termreg << "]; //rel2" << endl
	<< "R[" << *termreg << "] = R[" << *termreg <<"]" << ss2.str() << "; //rel2" << endl;
    c->write_code(ss3.str());
    ss << " && R[" << *termreg << "]";
  }else if(tt >=0){
    ss << " " << op << " R[" << *termreg << "]";
    c->free_reg(*termreg);
  }
  //cout << "parsed relation2" << endl;
  debug("exit relation2; tt is " , tt);
  return tt;
}
/*
int parser::term(int * regnum){
  if(error_flag){return -1;}
  debug("enter term");
  int tt = -1, tt2=-1;
  int * reg2;
  tt = factor(regnum);
  int op = next_token->get_type();
  if(op==TIMES || op==DIVIDE){
    scan_next_token();
    reg2 = new int(c->get_next_free_reg());
    c->use_reg(*reg2);
    tt2 = term(reg2);
  }
  if(tt2 >=0){
    //only defined for ints
    check_types(tt,INTEGERTYPE);
    check_types(tt,tt2);
    stringstream ss;
    ss << "R[" << *regnum << "] = " << "R[" << *regnum << "]";
    if(op==TIMES)
      ss << " * ";
    else // {op == DIVIDE}
      ss << " / ";
    ss << "R[" << *reg2 << "]; //term" << endl;
    c->write_code(ss.str());
  }
  debug("exit term; tt is " , tt);
  return tt;
  }*/

int parser::term(int* regnum){
  if(error_flag){return -1;}
  debug("enter term");
  int tt = -1, tt2=-1;
  int * reg2;
  stringstream ss, ss2;
  tt = factor(regnum);
  tt2 = term2(ss2,regnum);

  if(tt2 >= 0){ //if there is an op
    // arith ops defined only on ints so must force check that they
    // are both ints.
    check_types(tt,INTEGERTYPE);
    check_types(tt,tt2);
    ss << "R[" << *regnum << "] = R[" << *regnum << "]" << ss2.str() ;
    c->write_code(ss.str());
  }
  
  debug("exit term; tt is " , tt);
  return tt;
}

int parser::term2(stringstream& ss, int* regnum){
  if(error_flag){return -1;}
  debug("enter arithOp2");
  int tt = -1, tt2=-1;
  bool hadOp = false;
  switch(next_token->get_type()){
  case TIMES:
    ss << " * ";
    hadOp = true;
    break;
  case DIVIDE:
    ss << " / ";
    hadOp = true;
    break;
  }

  if(hadOp){
    scan_next_token();
    int * reg;
    reg = new int(c->get_next_free_reg());
    stringstream ss2;
    c->use_reg(*reg);
    tt = factor(reg);
    tt2 = term2(ss2,regnum);
    if(tt2 >=0 ){
      // arith ops defined only on ints so must force check that they
      // are both ints.
      check_types(tt,INTEGERTYPE);
      check_types(tt,tt2);
      ss << "R[" << *reg << "]; //term 2" << endl;
      c->free_reg(*reg);

      ss << "R[" << *regnum << "] = R[" << *regnum << "]"<< ss2.str();//<< "; //term2" << endl;
    }else{
      ss << "R[" << *reg << "]; //term 2" << endl;
      c->free_reg(*reg);
    }
  }
  debug("exit term2; tt is " , tt);
  return tt;
}

int parser::factor(int * regnum){
  if(error_flag){return -1;}
  debug("enter factor");
  int tt = -1;
  token ftoken = *next_token;
  stringstream ss;
  switch(next_token->get_type()){
  case LPAREN:
    {
      scan_next_token();
      tt = expression(regnum);
      check_token_type(RPAREN,"')'");
      scan_next_token();
      break;
    }
  case ID:
    {
      tt = identifier();

      int* idxreg = name_or_function_call(ftoken,regnum);

      if(!st->is_function(ftoken) && !st->is_array(ftoken)){ 
	//if it was a function, code was genned in name_or_func_call
	// if is array, code will be genned in the block below.
	ss << "R[" << *regnum << "] = MM[R[0] + " << st->get_offset(ftoken);
      }
      
      if(st->is_array(ftoken)){
	if(*idxreg < 0){
	  //if its an array without an indexing, just return
	  //arraytype, don't gen code.
	  tt = ARRAYTYPE;
	}else{
	  int* tmpreg = new int(c->get_next_free_reg());
	  c->use_reg(*tmpreg);
	  ss << "R[" << *tmpreg << "] = R[0] + R[" << *idxreg 
	     << "]; // calc array offset" << endl //add index offset
	     << "R[" << *regnum << "] = MM[R[" << *tmpreg << "] + " << st->get_offset(ftoken) 
	     << "]; // factor" << ftoken.get_value() << endl;
	}
	c->free_reg(*idxreg); //free up idx reg
      }
      if(tt!= ARRAYTYPE && !st->is_function(ftoken) && !st->is_array(ftoken)){
	ss << "];//factor " << ftoken.get_value() << endl;
      }
      c->write_code(ss.str());
      break;
    }
    
  case NUMBER:
    {
      tt = INTEGERTYPE;
      ss << "R[" << *regnum << "] = " << ftoken.get_value() << ";//factor" << endl;
      c->write_code(ss.str());
      scan_next_token();
      break;
    }
  case STRING:
    {
      tt=STRINGTYPE;
      //need to put string in string table, return address
      int straddr = c->add_string(ftoken.get_value());
      ss << "R[" << *regnum << "] = " << straddr << "; // string factor " << ftoken.get_value() << endl;
      c->write_code(ss.str());
      scan_next_token();   
    }
  }
  debug("exit factor; tt is " , tt);
  return tt;
}

//returns ptr to register number holding array idx, if t is an array.
//otherwise returns -1.
int* parser::name_or_function_call(token t,int* funcreg){
  int* expressionreg = new int(-1);
  if(error_flag){return expressionreg;}
  debug("enter name_or_function_call");
  switch(next_token->get_type()){
  case LBRACKET: //array
    {
      if(!st->is_array(t)){
	panic();
	error_flag = true;
	return expressionreg;
      }
      scan_next_token();
      expressionreg = new int(c->get_next_free_reg());
      c->use_reg(*expressionreg);
      // do we need to check the type returned for the index expression?
      // Should at least not be string...
      expression(expressionreg);
      check_token_type(RBRACKET,"']'");
      scan_next_token();
      break;
    }
  case LPAREN: // function
    {
      if(!st->is_function(t)){
	panic();
	error_flag = true;
	return expressionreg;
      }
      scan_next_token();
      string lblfunc = st->get_label(t);
      string lblreturn = c->get_next_label();
      stringstream ss;
      
      ss << "MM[R[1]] = R[0]; //store old frame ptr" << endl 
	 << "R[1] = R[1] + 1; //incrementing frm ptr storage " << endl 
	 << "R[0] = R[1]; //set frame ptr to top of stk" << endl
	 << "MM[R[0] + 1] = &&" << lblreturn << ";" << endl
	 << "R[1] = R[1] + 2; //leave room for return value and address" << endl;
      if(next_token->get_type() != RPAREN){
	argument_list(t,0,2,ss); //initial offset of 2
      }
      ss << "goto " << lblfunc << ";" << endl
	 << lblreturn << ": " 
	 << "R[" << *funcreg << "] = MM[R[0]]; //store return val" << endl
	 << "R[1] = R[0];" << endl
	 << "R[0] = MM[R[0]-1];" << endl;

      c->write_code(ss.str());
      //remove_scope();
      check_token_type(RPAREN,"')'");
      scan_next_token();
    }
  }
  debug("exit name_or_function_call");
  return expressionreg;
}
void parser::argument_list(token t, int argnum, int offset,stringstream& ss){
  if(error_flag){return;}
  debug("enter argument_list");
  vector<pair<token*,int> > plist = *(st->get_parameterlist(t));
  map<int, pair<int, int> > arrayparams = *(st->get_arrayparams(t));

  if(plist.size() > 0){
    token ptok = *next_token;

    int* expressionreg;
    expressionreg = new int(c->get_next_free_reg());
    c->use_reg(*expressionreg);
    int tt1 = expression(expressionreg);
    int tt2 =  plist[argnum].second;
    bool isarray = false;
    int arraysize = -1;
    if(tt2 == ARRAYTYPE){
      tt2 = arrayparams[argnum].first;
      arraysize = arrayparams[argnum].second;
      check_array_sizes(arraysize,st->get_arraysize(ptok));
      isarray = true;
    }

    //    cout << "tt1: " << tt1 << "\t tt2: " << tt2 << endl ; 
    if(check_types(tt1,tt2)){//if types are right, add arg to symbol table
      token argtok = *st->add(*(plist[argnum].first)); 
      if(isarray){
	for(int i = 0; i < arraysize; i++){
	  ss << "MM[R[0] + " << argnum + i +  offset << "]"  //destination
	   << " = R[" << *expressionreg << "]; //passing argument " << argtok.get_value() << endl;
	}
	offset += arraysize;
      }else{
	ss << "MM[R[0] + " << argnum + offset << "]"  //destination
	   << " = R[" << *expressionreg << "]; //passing argument " << argtok.get_value() << endl;
      }
      //c->write_code(ss.str());
      
    }

    c->free_reg(*expressionreg);

    if(next_token->get_type() == COMMA){
      scan_next_token();
      argument_list(t,++argnum,offset,ss);
    }
  }

  debug("exit argument_list");
}

void parser::add_scope(token ftoken){
  symboltable * new_st = new symboltable();
  new_st->set_prev(st);
  //new_st->set_ftoken(st->get_ftoken());
  new_st->set_ftoken(ftoken);
  st = new_st;
  //cout << "ftoken here: " << st->get_ftoken() << endl;
  s->set_st(st); //sync scanner st
  //cout << "added scope; new st is " << st << endl;
}
void parser::remove_scope(){
  //  cout << "removing scope. removing st: " << st << endl;
  symboltable* old_st = st;
  st = old_st->get_prev();
  s->set_st(st);//sync scanner st
  delete(old_st);
  //  cout << "removed scope; back to " << st << endl;
}
