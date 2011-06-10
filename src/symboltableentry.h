#ifndef SYMBOLTABLEENTRY_H
#define SYMBOLTABLEENTRY_H
#include "token.h"
#include <vector>
#include <map>

class symboltableentry{
  token* t;
  int *type; // type information for identifiers or numbers.
  //  bool function;
  bool *arraybool;
  int *arraysize;
  bool *functionbool;
  vector<pair<token*,int> > * paramlist;
  map<int,pair<int,int> > * arrayparams; // arrayparams[i] = {type,size}
  string * label;
  int* ardepth;
  int* offset;
  string * declared_in;
 public:
  symboltableentry(token);
  ~symboltableentry();
  void set_type(int);
  void set_array(int);
  void set_function(vector<pair<token*,int> >);
  void set_function(vector<pair<token*,int> >,map<int,pair<int,int> >);
  void set_label(string);
  bool is_array();
  bool is_function();
  int get_arraysize();
  string get_label();
  
  void increment_ardepth();
  int get_ardepth();
  void set_ardepth(int d);
  
  void set_offset(int);
  int get_offset();

  string get_declared_in();
  void set_declared_in(string);
  /*
  //not needed?
  void set_memloc(int);
  int  get_memloc();
  // ------
  */

  vector<pair<token*,int> >* get_paramlist();
  map<int, pair<int,int> >* get_arrayparams();
  token * get_token() const;
  int get_type();
  friend bool operator<(const symboltableentry& t1, const symboltableentry& t2);
  friend bool operator==(const symboltableentry& t1, const symboltableentry& t2);
  friend ostream& operator<<(ostream& o, const symboltableentry& s);
};

namespace std { 
  namespace tr1
  {
    // hash function definition for use in unordered_set
    // std::tr1::hash specialization
    template <>
      struct hash<symboltableentry> : public unary_function<symboltableentry, size_t>
      {
	size_t operator()(const symboltableentry& s) const
	{
	  hash<string> h;
	  return h(s.get_token()->get_value());
	}
      };
  }
  //std::equal_to specialization
  template <>
    struct equal_to<symboltableentry> : public unary_function<symboltableentry, size_t>
    {
      size_t operator()(const symboltableentry& s1, const symboltableentry& s2) const
      {
	return  s1 == s2;
      }
    };
}

#endif //SYMBOLTABLEENTRY_H
