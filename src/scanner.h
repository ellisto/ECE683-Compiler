#ifndef SCANNER_H
#define SCANNER_H

#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include "token.h"
#include "fsm.h"
#include "linecounter.h"
#include "symboltable.h"
#include "enums.h"

using namespace std;  



//extern int linenumber;

class scanner{
  ifstream * in;
  FSM fsm;
  map<int,int> final_state_names;
  symboltable * st;
  line_counter * l;
  void initFSM();
  //  void initST();
  char get_lexeme_begin();
public:
  bool attach_file(const char*);
  bool good();
  void close_stream();
  token scan();
  int get_char_class(char);
  void set_st(symboltable* st);
  scanner();
  scanner(const char*);
  scanner(line_counter&,symboltable&);
  scanner(const char*, line_counter&,symboltable&);
};

#endif //SCANNER_H
