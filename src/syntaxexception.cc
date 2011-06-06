#include <exception>
#include "linecounter.h"
using namespace std;

extern line_counter *l;

class syntaxexception: public exception
{
  virtual const char* what() const throw()
  {
    return "Syntax exception!";
  }
};
