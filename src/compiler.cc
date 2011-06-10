#include<iostream>
#include<string>
#include "scanner.h"
#include "token.h"
#include "linecounter.h"
#include "symboltable.h"
#include "parser.h"
#include "code_writer.h"
#include<cstring>
#include<cstdlib>

using namespace std;  

void report_error(string);

//int linenumber = 0;


int main(int argc, char * argv[]){
  if(argc !=2){
    report_error("Usage: scanner filename");
    return 1;
  }
  
  line_counter l;
  symboltable st;
  scanner s(l,st);
  code_writer c("generated_code.c","code_defs.h","std_defs.h");
  bool error_flag = false;

  if(!s.attach_file(argv[1])){
    report_error("Cannot open file for reading!");
    return 1;
  }
  
  parser p(s,l,st,c);
  /*  while(s.good()){
    cout << s.scan() << endl;
    }*/
  
  c.init_generated_code();

  while(s.good()){
    if(!p.parse()){
      error_flag = true;
      p.reset_error();
    }
  }
  
  c.init_code_defs();
  c.init_std_defs();
  c.finalize_generated_code();
  
    if(!error_flag){
    //compile generated code
    cout << endl << endl;
    //  system(string("cat " + c.get_gen_filename()).c_str());
    cout << endl << endl;
    system(string("gcc -g -static " + c.get_gen_filename() + " -L. -lruntime -lm ").c_str()); 
    //1> clog 2>clog").c_str());
    cout << endl << endl;
    
    //test generated code
    system("./a.out");
    }else{
    cout << "There were errors." << endl;
    //should delete generated_code.c, but leaving it there for debug
    //now.
    }
  return 0;
}

