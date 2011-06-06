#include "parser.h"
#include "report_error.h"
#include <string>
#include <cstdlib>
#define DEBUG

using namespace std;
void parser::debug(const char* m){
#ifdef DEBUG
  cout << m << " token: " << *next_token << endl;
#endif
}

void parser::debug(const char* m,int i){
#ifdef DEBUG
  cout << m << i << endl;
#endif
}

parser::parser(){
  this->l = new line_counter();
  this->st = new symboltable();
  this->s = new scanner(*l,*st);
  error_flag=false;
}

parser::parser(scanner& s,line_counter& l,symboltable& st){
  this->s = &s;
  this->l = &l;
  this->st = &st;
  error_flag=false;
  this->next_token = new token(this->s->scan());
}

void parser::attach_scanner(scanner&s){
  this->s = &s;
  this->next_token = new token(this->s->scan());
}

void parser::reset_error(){
  error_flag= false;
}

bool parser::parse(){
  int tm;
  tm = type_mark();
  function_declaration(tm);
  return !error_flag;
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
    report_error("Type mismatch!", l->get_linenumber());
    return false;
  }
}

void parser::panic(){
  do{
    while(next_token->get_type()!=END && next_token->get_type()>0 ){
#ifdef DEBUG
      cout << "PANIC MODE! Skipping " << *next_token << endl;
#endif
      scan_next_token();
    }
    debug("last token was end, getting a new one.");
    scan_next_token();
  }while(next_token->get_type()!=FUNCTION && next_token->get_type()>0);
  debug("last token was function, getting a new one.");
  if(next_token->get_type()<0){
      debug("Panicked to end of file.");
  }else{scan_next_token();}
}

bool parser::is_error(){
  return error_flag;
}

void parser::function_declaration(int typemark){
  //  if(error_flag){error_flag=false;}
  debug("enter function_declaration");
  function_header(typemark);
  function_body();
  if(next_token->get_type() >= 0){
    reset_error();
  }
  debug("exit function_declaration");
}

void parser::function_header(int typemark){
  if(error_flag){return;}
  debug("enter function_header");
  check_token_type(FUNCTION,"'function'");
  scan_next_token();
  token ftoken = *next_token;
  //  cout << "candidate function: " << ftoken << endl;
  identifier(typemark);
  vector<int> plist = vector<int>();
  check_token_type(LPAREN,"'('");
  scan_next_token();
  if(next_token->get_type()!=RPAREN){
    parameter_list(&plist);
  }
  check_token_type(RPAREN,"')'");
  
  //st->set_function(ftoken,plist); // add function and parameterlist to symboltable
  
  /*vector<int> tmp = *(st->get_parameterlist(ftoken));
  for(vector<int>::const_iterator it = tmp.begin(); it!=tmp.end(); it++){
    cout << *it << endl;
    }*/
  scan_next_token();
  debug("exit function_header");
}
void parser::parameter_list(vector<int> * plist){
  if(error_flag){return;}
  debug("enter parameter_list");
  int ptype = parameter();
  if(ptype>=0){
    plist->push_back(ptype);
  }
  if(next_token->get_type()==COMMA){
    check_token_type(COMMA,"','");
    scan_next_token();
    parameter_list(plist);
  }
  debug("exit parameter_list");
}

int parser::parameter(){
  if(error_flag){return -1;}
  debug("enter parameter");
  int tm = type_mark();
  variable_declaration(tm);
  debug("exit parameter");
  return tm;
}
void parser::function_body(){
  //TODO: Check to ensure there is a return statement.
  if(error_flag){return;}
  debug("enter function_body");
  while(next_token->get_type()!=BEGIN){
    declaration();
    check_token_type(SEMICOLON,"';'");
    scan_next_token();
  }
  check_token_type(BEGIN,"'begin'");
  scan_next_token();
  while(next_token->get_type()!=END && next_token->get_type() >= 0){
    statement();
    check_token_type(SEMICOLON,"';'");
    scan_next_token();
  }

  check_token_type(END,"'end'");
  scan_next_token();
  check_token_type(FUNCTION,"'function'");
  scan_next_token();
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
  if(next_token->get_type() == LBRACKET){
    check_token_type(LBRACKET,"'['");
    scan_next_token();
    check_token_type(NUMBER,"array size");
    int arraysize = atoi((next_token->get_value()).c_str());
    cout << "arraysize is " << arraysize << endl;
    cout << "varid is " << varid << endl;
    //st->set_arraysize(varid,arraysize);
    scan_next_token();
    check_token_type(RBRACKET,"']'");
    scan_next_token();  
  }
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
  int tt1 = destination();
  //  cout << "t1 : " << tt1 << endl;
  check_token_type(ASSIGN,":=");
  scan_next_token();
  int tt2 = expression();
  //  cout << "t2 : " << tt2 << endl;
  //  cout <<"(t1,t2) = (" << tt1 << " , " << tt2 << ")" << endl;
  check_types(tt1,tt2);
  //cout << "parsed assignment statement" << endl;
  debug("exit assignment_statement");
}

int parser::destination(){
  if(error_flag){return -1;}
  debug("enter destination");
  int tt = identifier();
  if(next_token->get_type() == LBRACKET){
    scan_next_token();
    expression();
    check_token_type(RBRACKET,"]");
    scan_next_token();
  }
  //cout << "parsed destination" << endl;
  debug("exit destination; tt is " , tt);
  //  cout << "tt is" << tt << endl;
  return tt;
}
void parser::if_statement(){
  if(error_flag){return;}
  debug("enter if_statement");

  check_token_type(IF,"'if'");
  scan_next_token();
    
  expression();
    
  check_token_type(THEN,"'then'");
  scan_next_token();
  
  do{
    statement();
      
    check_token_type(SEMICOLON,"';'");
    scan_next_token();
  }while(next_token->get_type()!=ELSE && next_token->get_type()!=END && next_token->get_type()!=EOF  );
    

  if(next_token->get_type() == ELSE){
    scan_next_token();
    
    do{
      statement();
      
      check_token_type(SEMICOLON,"';'");
      scan_next_token();
    }while(next_token->get_type()!=END && next_token->get_type()!=EOF );
  }
  
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
  
  expression();
  
  if(next_token->get_type()!=END){
    statement();
    
    check_token_type(SEMICOLON,"';'");
    scan_next_token();
  }
  
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

  expression();
  
  check_token_type(IS,"'is'");
  scan_next_token();

  do{
    check_token_type(WHEN,"'when'");
    scan_next_token();
    
    check_token_type(NUMBER,"number");
    scan_next_token();
    
    check_token_type(THEN,"'then'");
    scan_next_token();
    
    do{
      statement();
      
      check_token_type(SEMICOLON,"';'");
      scan_next_token();
    }while(next_token->get_type()!=DEFAULT && next_token->get_type()!=END);
  }while(next_token->get_type()!=WHEN && next_token->get_type()!=DEFAULT && next_token->get_type()!=END);
  
  if(next_token->get_type()==DEFAULT){
    check_token_type(DEFAULT,"'default'");
    scan_next_token();

    check_token_type(THEN,"'then'");
    scan_next_token();
    while(next_token->get_type()!=END){
      statement();
      check_token_type(SEMICOLON,"';'");
      scan_next_token();
    }
  }
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
  int tt = st->get_tokentype(*next_token);
  //cout << "tt: " << tt << endl;
  scan_next_token();
  debug("exit identifier; tt is " , tt);
  return tt;
}
int parser::expression(){
  if(error_flag){return -1;}
  debug("enter expression");
  int tt;
  //cout << "expression(); token: " << *next_token << endl;
  if(next_token->get_type() == NOT){
    tt = BOOLEANTYPE;
    scan_next_token();
  }
  tt = arithOp();
  int tt2 = expression2();
  if(tt2>=0)
    check_types(tt,tt2);
  //cout << "parsed expression" << endl;
  debug("exit expression; tt is " , tt);
  return tt;
}
int parser::expression2(){
  if(error_flag){return -1;}
  debug("enter expression2");
  int tt = -1, tt2=-1;
  //cout << "expression2(); token: " << *next_token << endl;
  switch(next_token->get_type()){
  case AND:
    scan_next_token();
    tt = arithOp();
    tt2 = expression2();
  case OR:
    scan_next_token();
    tt = arithOp();
    tt2 = expression2();
  }
  if(tt2 >= 0){
    check_types(tt,tt2);
  }
  //cout << "parsed expression2" << endl;
  debug("exit expression2; tt is " , tt);
  return tt;
}
int parser::arithOp(){
  if(error_flag){return -1;}
  debug("enter arithOp");
  int tt =-1, tt2 = -1;
  //cout << "arithOp(); token: " << *next_token << endl;
  tt = relation();
  tt2 = arithOp2();
  if(tt2 >=0)
    check_types(tt,tt2);
  //cout << "parsed arithOp" << endl;
  debug("exit arithOp; tt is " , tt);
  return tt;
}
int parser::arithOp2(){
  if(error_flag){return -1;}
  debug("enter arithOp2");
  int tt = -1, tt2=-1;
  switch(next_token->get_type()){
  case ADD:
    scan_next_token();
    tt = relation();
    tt2 = arithOp2();
    break;
  case SUB:
    scan_next_token();
    tt = relation();
    tt2 = arithOp2();
    break;
  case BITAND:
    scan_next_token();
    tt = relation();
    tt2 = arithOp2();
    break;
  case BITOR:
    scan_next_token();
    tt = relation();
    tt2 = arithOp2();
    break;
  }
  if(tt2>=0){
    check_types(tt,tt2);
  }
  //cout << "parsed arithOp2" << endl;
  debug("exit arithOp2; tt is " , tt);
  return tt;
}
int parser::relation(){
  if(error_flag){return -1;}
  debug("enter relation");
  int tt = -1, tt2 = -1;
  //cout << "relation(); token: " << *next_token << endl;
  tt = term();
  //  cout <<"tt after term is " << tt << endl;
  tt2 = relation2();
  if(tt2>=0)
    check_types(tt,tt2);
  //cout << "parsed relation" << endl;
  debug("exit relation; tt is " , tt);
  return tt;
}
int parser::relation2(){
  if(error_flag){return -1;}
  debug("enter relation2");
  int tt=-1, tt2=-1;
  //cout << "relation2(); token: " << *next_token << endl;
  if(next_token->get_type()==RELOP){
    scan_next_token();
    tt = term();
    tt2 = relation2();
  }  
  if(tt2 >= 0){
    check_types(tt,tt2);
  }
  //cout << "parsed relation2" << endl;
  debug("exit relation2; tt is " , tt);
  return tt;
}
int parser::term(){
  if(error_flag){return -1;}
  debug("enter term");
  int tt = -1, tt2=-1;
  //cout << "term(); token: " << *next_token << endl;
  tt = factor();
  if(next_token->get_type()==TIMES || next_token->get_type()==DIVIDE){
    scan_next_token();
    tt2 = term();
  }
  if(tt2 >=0){
    check_types(tt,tt2);
  }
  //cout << "parsed term" << endl;
  debug("exit term; tt is " , tt);
  return tt;
}
int parser::factor(){
  if(error_flag){return -1;}
  debug("enter factor");
  int tt = -1;
  token ftoken = *next_token;
  //cout << "factor(); token: " << *next_token << endl;
  switch(next_token->get_type()){
  case LPAREN:
    scan_next_token();
    tt = expression();

    check_token_type(RPAREN,"')'");
    scan_next_token();

    break;
  case ID:
    tt = st->get_tokentype(ftoken);
    scan_next_token();
    name_or_function_call(ftoken);
    break;
  case NUMBER:
    tt = INTEGERTYPE;
    scan_next_token();
    break;
  case STRING:
    tt=STRINGTYPE;
    scan_next_token();
  }
  //cout << "parsed factor" << endl;
  debug("exit factor; tt is " , tt);
  return tt;
}

void parser::name_or_function_call(token t){
  if(error_flag){return;}
  debug("enter name_or_function_call");
  switch(next_token->get_type()){
  case LBRACKET: //array
    scan_next_token();
    expression();
    check_token_type(RBRACKET,"']'");
    scan_next_token();
    break;
  case LPAREN: // function
    scan_next_token();
    
    if(next_token->get_type() == RPAREN){
      scan_next_token();
      break;
    }
    argument_list(t,0);
    check_token_type(RPAREN,"')'");
    scan_next_token();
  }
  //cout << "parsed name_or_function_call" << endl;
  debug("exit name_or_function_call");
}
void parser::argument_list(token t, int argnum){
  if(error_flag){return;}
  debug("enter argument_list");
  if(!st->is_function(t)){
    report_error("Not a function!",l->get_linenumber(),t);
  }
  //  vector<int> plist = *(st->get_parameterlist(t));
  //  if(plist.size() > 0){
    /*  int tt1 = expression();
    int tt2 =  plist[argnum];
    check_types(tt1,tt2);*/
    if(next_token->get_type() == COMMA){
      scan_next_token();
      argument_list(t,++argnum);
      //  }
  }
  //cout << "parsed argument list" << endl;
  debug("exit argument_list");
}

