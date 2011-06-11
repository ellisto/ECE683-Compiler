#include "symboltable.h"
#include "report_error.h"
#include <sstream>

symboltable::symboltable(){
  table = unordered_set<symboltableentry>();
  prev = NULL;
  
  ftoken = new token(-1,"");
  // token globaltoken(-1,"_GLOBAL");
  // st->add(globaltoken);
  // st->set_function(globaltoken,vector<pair<token*,int> >());
  // st->set_ftoken(globaltoken);
  //void scanner::initST(){
  
  add(token(FUNCTION,string("function")));
  add(token(BEGIN,string("begin")));
  add(token(END,string("end")));
  add(token(TYPE,string("integer")));
  add(token(TYPE,string("boolean")));
  add(token(TYPE,string("string")));
  add(token(IF,string("if")));
  add(token(THEN,string("then")));
  add(token(ELSE,string("else")));
  add(token(WHILE,string("while")));
  add(token(CASE,string("case")));
  add(token(IS,string("is")));
  add(token(WHEN,string("when")));
  add(token(DEFAULT,string("default")));
  add(token(AND,string("and")));
  add(token(OR,string("or")));
  add(token(NOT,string("not")));
  
  token* t = add(token(ID, "getBool"));
  set_tokentype(*t,BOOLEANTYPE);
  set_function(*t,vector<pair<token*,int> >());
  set_label(*t,"GETBOOL");

  t = add(token(ID, "getInt"));
  set_tokentype(*t,INTEGERTYPE);
  set_function(*t,vector<pair<token*,int> >());
  set_label(*t,"GETINT");

  t = add(token(ID, "getString"));
  set_tokentype(*t,STRINGTYPE);
  set_function(*t,vector<pair<token*,int> >());
  set_label(*t,"GETSTRING");

  t = add(token(ID, "putBool"));
  set_tokentype(*t,INTEGERTYPE);
  set_function(*t,vector<pair<token*,int> >(1,pair<token*,int>(new token(),BOOLEANTYPE)));
  set_label(*t,"PUTBOOL");

  t = add(token(ID, "putInt"));
  set_tokentype(*t,INTEGERTYPE);
  set_function(*t,vector<pair<token*,int> >(1,pair<token*,int>(new token(),INTEGERTYPE)));
  set_label(*t,"PUTINT");

  t = add(token(ID, "putString"));
  set_tokentype(*t,INTEGERTYPE);
  set_function(*t,vector<pair<token*,int> >(1,pair<token*,int>(new token(),STRINGTYPE)));
  set_label(*t,"PUTSTRING");

  t = add(token(ID, "sqrt"));
  set_tokentype(*t,INTEGERTYPE);
  set_function(*t,vector<pair<token*,int> >(1,pair<token*,int>(new token(),INTEGERTYPE)));
  set_label(*t,"SQRT");

  t = add(token(ID, "int2bool"));
  set_tokentype(*t,BOOLEANTYPE);
  set_function(*t,vector<pair<token*,int> >(1,pair<token*,int>(new token(),INTEGERTYPE)));
  set_label(*t,"INT2BOOL");

  t = add(token(ID, "bool2int"));
  set_tokentype(*t,INTEGERTYPE);
  set_function(*t,vector<pair<token*,int> >(1,pair<token*,int>(new token(),BOOLEANTYPE)));
  set_label(*t,"BOOL2INT");

  /*  boolean getBool()

      integer getInt()

      string getString()

      integer putBool(boolean)

      integer putInt(integer)

      integer putString(string)

      integer sqrt(integer)

      boolean int2bool(integer)

      integer bool2int(boolean)*/
}

symboltable::~symboltable(){
  
}

token * symboltable::add(token t){
  //  cout << this << " adding token " << t << endl;
  
  pair<unordered_set<symboltableentry>::iterator,bool> ret;
  ret = table.insert(symboltableentry(t));
  unordered_set<symboltableentry>::iterator retit = ret.first;
  return (*retit).get_token();
}

symboltableentry *symboltable::find_entry(token t){
  unordered_set<symboltableentry>::iterator it;
  symboltableentry * ret = NULL;
  it = table.find(t);
  if(it == table.end()){//if it's not found in this st, go back a level.
    if(prev)
      ret = prev->find_entry(t);
  }else{
    ret = new symboltableentry(*it);
    if(ftoken->get_type()>=0){
      //cout << t.get_value() << " declared in " << ftoken->get_value() <<endl;
      ret->set_declared_in(ftoken->get_value());
    }
  }
  return ret;
}
token * symboltable::find(token t){
  symboltableentry * entry = find_entry(t);
  token * ret = NULL;
  if(entry)
    ret = entry->get_token();
  return ret;
}

void symboltable::set_prev(symboltable* prev_st){
  this->prev = prev_st;
  return;
}

void symboltable::set_tokentype(token t, int tokentype){
  symboltableentry entry = *find_entry(t);
  entry.set_type(tokentype);
}

int symboltable::get_tokentype(token t){
  symboltableentry entry = *find_entry(t);
  int type = entry.get_token()->get_type();
  int ret =-1;

  if(type == ID){
    ret = entry.get_type();
  }
  else if(type == NUMBER){
    ret = INTEGERTYPE;
  }else if(type == STRING){
    ret = STRINGTYPE;
  }
  
  return ret;
}

void symboltable::set_arraysize(token t, int size){
  symboltableentry entry = *find_entry(t);
  entry.set_array(size);
}

bool symboltable::is_array(token t){
  symboltableentry entry = *find_entry(t);
  return entry.is_array();
}

int symboltable::get_arraysize(token t){
  symboltableentry entry = *find_entry(t);
  return entry.get_arraysize();
}

void symboltable::set_function(token t, vector<pair<token*,int> > plist){
  symboltableentry entry = *find_entry(t);
  entry.set_function(plist);
  increment_ardepth(t); //return value
  //increment_ardepth(t); //return address
  //cout << "set function " << *find_entry(t) << endl;
}

void symboltable::set_function(token t, vector<pair<token*,int > > plist, map<int,pair<int,int> > arrayparams){
  symboltableentry entry = *find_entry(t);
  entry.set_function(plist,arrayparams);
  increment_ardepth(t); //return value
  //  increment_ardepth(t); //return address
}

bool symboltable::is_function(token t){
  return find_entry(t)->is_function();
}
    
vector<pair<token*,int> >* symboltable::get_parameterlist(token t){
  return find_entry(t)->get_paramlist();
}

map<int, pair<int,int> >* symboltable::get_arrayparams(token t){
  return find_entry(t)->get_arrayparams();
}

void symboltable::set_label(token t,string lbl){
  symboltableentry entry = *find_entry(t);
  entry.set_label(lbl);
  stringstream ss;
  ss << "setting label for " << t << " to " << lbl <<endl;
  debug(ss.str());
}

string symboltable::get_label(token t){
  symboltableentry entry = *find_entry(t);
  string lbl = entry.get_label();
  stringstream ss;
  ss << "getting label for " << t << ":" << lbl <<endl;
  debug(ss.str());
  return lbl;
}

symboltable * symboltable::get_prev(){
  return prev;
}

void symboltable::increment_ardepth(token t){
  symboltableentry entry = *find_entry(t);
  entry.increment_ardepth();
  stringstream ss;
  ss <<"incrementing ardepth for " << t << "; is now " << entry.get_ardepth() <<  endl;
  debug(ss.str());
}

void symboltable::decrement_ardepth(token t){
  symboltableentry entry = *find_entry(t);
  entry.set_ardepth(entry.get_ardepth()-1);
  stringstream ss;
  ss <<"decrementing ardepth for " << t << "; is now " << entry.get_ardepth() <<  endl;
  debug(ss.str());
}

void symboltable::set_ardepth(token t, int d){
  symboltableentry entry = *find_entry(t);
  entry.set_ardepth(d);
  stringstream ss;
  ss << "setting ardepth for " << t << "; is now " << entry.get_ardepth() <<  endl;
  debug(ss.str());
}

int symboltable::get_ardepth(token t){
  //cout << "token is" << t << endl;
  symboltableentry entry = *find_entry(t);
  return entry.get_ardepth();
}

void symboltable::set_offset(token t,int os){
  symboltableentry entry = *find_entry(t);
  stringstream ss;
  ss << "setting offset for " << t << " to " << os << endl;
  debug(ss.str());
  entry.set_offset(os);
}
int symboltable::get_offset(token t){
  symboltableentry entry = *find_entry(t);
  return entry.get_offset();
}

void symboltable::set_declared_in(token t,string dec){
  symboltableentry entry = *find_entry(t);
  stringstream ss;
  ss << "setting declared_in for " << t << " to " << dec << endl;
  debug(ss.str());
  entry.set_declared_in(dec);
}
string symboltable::get_declared_in(token t){
  symboltableentry entry = *find_entry(t);
  return entry.get_declared_in();
}


token symboltable::get_ftoken(){
  return *ftoken;
}

void symboltable::set_ftoken(token t){
  stringstream ss;
  ss <<"setting ftoken to " << t << endl;
  debug(ss.str());
  ftoken = new token(t);
  //increment_ardepth(t); //return value
}

ostream& operator<<(ostream& out, const symboltable& st){
  out << "st at " << &st << endl;
  for(unordered_set<symboltableentry>::const_iterator it = st.table.begin(); it != st.table.end(); it++){
    cout << *it << endl;
  }
  return out;
}
