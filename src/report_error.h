#ifndef REPORT_ERROR_H
#define REPORT_ERROR_H
#include<string>
#include "token.h"

using namespace std;

void report_error(string);
void report_error(const char*);
void report_error(const char*,int);
void report_error(const char * e, int ln,token& t);

void report_error(string,int);
void report_error(string, int ln,token& t);

void debug(const char* m);
void debug(string m);

void debug(const char* m,int i);


#endif // REPORT_ERROR_H
