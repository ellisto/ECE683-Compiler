#include "linecounter.h"

line_counter::line_counter(){
  this->linenumber = 1;
}

int line_counter::get_linenumber(){
  return this->linenumber;
}

void line_counter::increment(){
  this->linenumber++;
  return;
}

void line_counter::reset(){
  this->linenumber = 1;
  return;
}
