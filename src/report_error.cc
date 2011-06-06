#include<iostream>
#include<string>
#include<sstream>
#include "report_error.h"
#include "token.h"

using namespace std;

void report_error(string e){
  cerr << e << endl;
}

void report_error(const char * e){
  cerr << e << endl;
}

void report_error(const char * e, int ln){
  cerr <<"On line "<< ln << ": " << e << endl;
}

void report_error( string e, int ln){
  cerr <<"On line "<< ln << ": " << e << endl;
}

void report_error(const char * e, int ln,token& t){
  stringstream ss;
  ss <<"On line "<< ln << ": " << e << "Token found: " << t <<  endl;
  //throw ss.str();
  cout << ss.str();
}

void report_error(string e, int ln,token& t){
  stringstream ss;
  ss <<"On line "<< ln << ": " << e << "Token found: " << t <<  endl;
  //throw ss.str();
  cout << ss.str();
}

void debug(const char* m){
#ifdef DEBUG
  cout << m << " token: " << *next_token << endl;
#endif
}
void debug(string m){
#ifdef DEBUG
  cout << m << " token: " << *next_token << endl;
#endif
}

void debug(const char* m,int i){
#ifdef DEBUG
  cout << m << i << endl;
#endif
}
