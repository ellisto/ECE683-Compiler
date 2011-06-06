#include "token.h"
#include<string>

using namespace std;

token::token(){
  this->type = new int(-1);
  this->value = new string("");
}

token::token(int type, string val){
  this->type = new int(type);
  this->set_value(val);
}

void token::set_value(string val){
  //  cout << "setting value of token to: " << val << endl;
  this->value = new string(val);
  return;
}

void token::set_type(int t){
  this->type = new int(t);
  return;
}

int token::get_type(){
  return *this->type;
}

string token::get_value(){ 
  return *(this->value);
}

ostream& operator<<(ostream& out, const token& t){
  out << "<" << *t.type << "," << *t.value << ">";
  return out;
}

bool operator<(const token& t1, const token& t2){
  /*  cout << *t1.value << " < " << *t2.value << endl;
  cout << "t1: " << t1.value <<" " << *t1.value<< endl;
  cout << "t2: " << t2.value << endl;
  cout << *t2.value << endl;*/
  return *t1.value < *t2.value;
}

bool operator==(const token& t1, const token& t2){
  return (*t1.value ==*t2.value && *t1.type == *t2.type);
}


namespace std{
  namespace tr1{
    template <>
    struct hash<token> : public unary_function<token, size_t>
    {
      size_t operator()(token& t) const
      {
	hash<string> h;
	cout << "hashing " << t << endl;
	return h(t.get_value());
      }
    };
  }
}
