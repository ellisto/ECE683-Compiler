#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include "linecounter.h"
#include "symboltable.h"
#include "token.h"
#include "code_writer.h"
#include <string>

using namespace std;
// before i forget: make functions for each grammar rule, i.e.
// if_statement(){
//   if (token != "if") ERROR
//   scan()
//   expression()
//   ...
class parser{
  scanner * s;
  line_counter * l;
  symboltable * st;
  token * next_token;
  code_writer * c;
  bool error_flag;
  //  int next_type;
 public:
  //constructors
  parser();
  parser(scanner&,line_counter&,symboltable&,code_writer&);

  bool parse();
  
  void attach_scanner(scanner&);

  void scan_next_token();
  void set_next_type();
  bool check_token_type(int type, const char* expected);
  bool check_types(int type1, int type2);
  bool check_array_sizes(int s1, int s2);
  void panic();

  bool is_error();
  void reset_error();

  void add_scope(token);
  void remove_scope();

  //grammar rules
  void function_declaration(int);
  token function_header(int);
  void parameter_list(vector<pair<token*,int> >*, map<int, pair<int,int> > *);
  pair<int,token> parameter();
  void function_body(token);
  void declaration();
  void declaration2(int);
  void variable_declaration(int);
  int type_mark();
  void array_size();
  void statement();
  void assignment_statement();
  int destination(stringstream&, int*);
  void if_statement();
  void while_statement();
  void case_statement();
  int identifier();
  int identifier(int);
  int expression(int * regnum);
  int expression();
  int expression2();
  int expression2(stringstream&);
  int arithOp();
  int arithOp(int * regnum);
  int arithOp2();
  int arithOp2(stringstream&);
  int relation(int * regnum);
  int relation2(stringstream&,int*);
  int term(int * regnum);
  int factor(int*);
  int* name_or_function_call(token);
  void argument_list(token, int);
  
  
};

#endif //PARSER_H
