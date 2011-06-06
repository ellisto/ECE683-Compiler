#ifndef LINECOUNTER_H
#define LINECOUNTER_H

class line_counter{
  int linenumber;
 public:
  int get_linenumber();
  void increment();
  line_counter();
  void reset();
};

#endif //LINECOUNTER_H
