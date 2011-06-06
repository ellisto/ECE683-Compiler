#include "token.h"
#include<cstring>
#include<cstdlib>

using namespace std;

token::token(){
  this->type = new int();
  this->value = "";
}

token::token(int type, const char* val){
  this->type = new int(type);
  this->set_value(val);
}

void token::set_value(const char* val){
  //  cout << "setting value of token to: " << val << endl;
  int len = strlen(val);
  this->value = (char*) malloc (len+1);
  strncpy(this->value,val,len);
  this->value[len+1] = '\0';
  return;
}

void token::set_type(int t){
  this->type = new int(t);
  return;
}

int token::get_type(){
  return *this->type;
}

char* token::get_value(){
  return this->value;
}

ostream& operator<<(ostream& out, const token& t){
  out << "<" << *t.type << "," << t.value << ">";
  return out;
}

bool operator<(const token& t1, const token& t2){
  cout << " Comparing tokens: " << t1 << "," << t2 << endl;
  int maxlen = max(strlen(t1.value),strlen(t2.value));
  cout << "maxlen: " << maxlen << endl;
  int cmp = strncmp(t1.value,t2.value,maxlen);
  if(cmp < 0){
    return true;
  }
  return false;
}
