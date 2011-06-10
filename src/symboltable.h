#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "token.h"
#include "enums.h"
#include<tr1/unordered_set>
#include<vector>
#include "symboltableentry.h"

using namespace std::tr1;


class symboltable{

  unordered_set<symboltableentry> table;
  token * ftoken;
  symboltable* prev;
 public:
  symboltable();
  ~symboltable();
  token * add(token);
  token * find(token);
  symboltableentry* find_entry(token);
  void  set_prev(symboltable* prev_st);
  symboltable * get_prev(); 
  void set_tokentype(token,int);
  int get_tokentype(token);
  void set_function(token, vector<pair<token*, int> >);
  void set_function(token,vector<pair<token*,int> >,map<int,pair<int,int> >);
  bool is_function(token); //returns true if the token is a function, false otherwise.
  vector<pair<token*, int> >* get_parameterlist(token); // returns parameter list for function.
  map<int, pair<int,int> >* get_arrayparams(token); // returns array parameter list for function.
  int get_arraysize(token);
  bool is_array(token);
  void set_arraysize(token,int);
  void set_label(token,string);
  string get_label(token);
  
  token get_ftoken();
  void set_ftoken(token t);
  
  //not needed?
  //void set_memloc(token, int);
  // int  get_memloc(token);
  //---

  void increment_ardepth(token);
  void decrement_ardepth(token t);
  void set_ardepth(token,int);
  int get_ardepth(token);
  
  void set_offset(token,int);
  int get_offset(token);
  
  friend ostream& operator<<(ostream& out, const symboltable& t);
};

#endif //SYMBOLTABLE_H
