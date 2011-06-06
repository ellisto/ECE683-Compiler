#ifndef TOKEN_H
#define TOKEN_H

#include<iostream>
#include<fstream>
#include<string>
#include<tr1/functional>

using namespace std;
using namespace std::tr1;

class token{
  int* type;
  string* value;
 public:
  int get_type();
  string get_value();
  void set_type(int);
  void set_value(string);
  token();
  token(int, string);
  friend ostream& operator<<(ostream& out, const token& t);
  friend bool operator<(const token& t1, const token& t2);
  friend bool operator==(const token& t1, const token& t2);
};

#endif // TOKEN_H
