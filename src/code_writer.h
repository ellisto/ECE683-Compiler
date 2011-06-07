#ifndef CODE_WRITER_H
#define CODE_WRITER_H
#include "enums.h"
#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

/** 
    Machine: R[MAX_USED] is int array for registers. MM[1000] is
    int array for main memory. 
    R[0] = Frame pointer 
    R[1] = stack pointer

    -------------- <--- R[1] (stack ptr (top of stack, next available MM index))
      ...
    local var decn
      ...
    local var dec2
    local var dec1
    nth param 
      ...
    2nd param
    1st param
    return address
    return val    <--- R[0] (frame ptr)
    old frame ptr
    --------------
 **/

class code_writer{
  ofstream generated_code;
  ofstream code_defs;
  ofstream std_defs;
  int register_num;
  int label_num;
  int string_table_ptr;
  string gen_file, code_defs_file, std_defs_file;
  vector<bool> registers;
 public:
  code_writer();
  code_writer(string gen_file,string code_defs_file,string std_defs_file);
  void init_generated_code();
  void finalize_generated_code();

  void init_code_defs();
  void init_std_defs();

  void write_code_defs(string);
  void write_std_defs(string);
  void write_code(string);

  void open_generated_code(string);
  void open_code_defs(string);
  void open_std_defs(string);

  int get_register_num();

  int get_next_free_reg();
  bool use_reg(int);
  bool free_reg(int);

  string get_gen_filename();
  string get_std_defs_filename();
  string get_code_defs_filename();
  string get_next_label();

  int add_string(string); //returns address in MM array
};

#endif // CODE_WRITER_H
