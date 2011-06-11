#include "symboltableentry.h"
#include "report_error.h"
#include<sstream>

symboltableentry::symboltableentry(token t){
  this->t = new token(t);
  type = new int(-1);
  arraybool = new bool(false);
  arraysize = new int(-1);
  functionbool = new bool(false);
  paramlist = new vector<pair<token*,int> >();
  arrayparams = new map<int, pair<int,int> >();
  ardepth = new int(1);
  offset =  new int(0);
  this->label = new string();
  this->declared_in = new string();
}

symboltableentry::~symboltableentry(){
  /*  delete t;
      delete type;
      delete arraybool;
      delete arraysize;
      delete functionbool;
      delete paramlist;*/
}

void symboltableentry::set_type(int type){
  *(this->type) = type;
}
void symboltableentry::set_array(int arraysize){
  *(this->arraybool) = true;
  *(this->arraysize) = arraysize;
}

void symboltableentry::set_function(vector<pair<token*,int> > param_list){
  *(this->functionbool) = true;
  *(this->paramlist) = param_list;
}
  
void symboltableentry::set_function(vector<pair<token*,int> > param_list,map<int,pair<int,int> > arrayparams){
  *(this->functionbool) = true;
  *(this->paramlist) = param_list;
  *(this->arrayparams) = arrayparams;
}

void symboltableentry::set_label(string lbl){
  *(this->label) = lbl;
}

string symboltableentry::get_label(){
  return *(this->label);
}

bool symboltableentry::is_array(){
  return *arraybool;
}
bool symboltableentry::is_function(){
  return *functionbool;
}
int symboltableentry::get_arraysize(){
  if(*arraybool){
    return *arraysize;
  }else
    return -1;
}
vector<pair<token*,int> >* symboltableentry::get_paramlist(){
  if(*functionbool)
    return paramlist;
  else
    return NULL;
}

map<int, pair<int,int> >* symboltableentry::get_arrayparams(){
  if(*functionbool)
    return arrayparams;
  else
    return NULL;
}

token * symboltableentry::get_token() const{
  return t;
}

int symboltableentry::get_type(){
  return *type;
}

void symboltableentry::increment_ardepth(){
  (*ardepth)++;
}

void symboltableentry::set_ardepth(int d){
  (*ardepth) = d;
}
int symboltableentry::get_ardepth(){
  return *ardepth;
}

void symboltableentry::set_offset(int os){
  *offset = os;
  stringstream ss;
  ss << " offset for " << t->get_value() << " is " << os << endl;
  debug(ss.str());
}
int symboltableentry::get_offset(){
  return *offset;
}


void symboltableentry::set_declared_in(string d){
  *(this->declared_in) = d;
}

string symboltableentry::get_declared_in(){
  return *(this->declared_in);
}

bool operator<(const symboltableentry& t1, const symboltableentry& t2){
  return *(t1.t) < *(t2.t);
}

bool operator==(const symboltableentry& t1, const symboltableentry& t2){
  //  return *(t1.t) == *(t2.t);
  return t1.get_token()->get_value() == t2.get_token()->get_value();
}

ostream& operator<<(ostream& o, const symboltableentry& s){
  o << *(s.t)
    << ", type: " << *(s.type)
    << ", declared in: " << *(s.declared_in)
    << ", array? " << *(s.arraybool)
    << ", arraysize: " << *(s.arraysize)
    << ", function? " << *(s.functionbool)
    << ", paramlist: " << s.paramlist;
  
  
  return o;
}
