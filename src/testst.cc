#include<iostream>
#include<string>
#include<tr1/unordered_set>
#include "symboltableentry.h"
#include "token.h"
#include "enums.h"

using namespace std;
using namespace std::tr1;

int main(){
  unordered_set<symboltableentry> table;
  token t(ID,"identifier"), t2(ID,"identifierdfdd");
  symboltableentry s(t);
  table.insert(s);
  cout << "s:" << s << endl;
  //  cout << (table.find(t2) == table.end()) << endl;
  //  unordered_set<symboltableentry>::iterator founds =  table.find(t);
  symboltableentry founds =  *table.find(t);
  cout << "s':" << founds <<endl;
  founds.set_type(INTEGERTYPE);
  founds.set_array(5);
  cout << "s:" << *table.find(t) <<endl;
}
