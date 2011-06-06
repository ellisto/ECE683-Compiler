#ifndef FSM_H
#define FSM_H
#include<vector>
#include<map>

using namespace std;

typedef map<int,map<char,int> >::iterator mapmapit;
typedef map<char,int>::iterator mapcharintit;

class FSM{
  map<int,map<char,int> > next_state;
  map<int,bool> final_state;
  int cur_state;
 public:
  FSM();
  //adds a state transition
  void add_state_transition(int, char, int);

//returns next state without changing state
  int get_next_state(char);
  
  //returns current state
  int get_cur_state();
  
  //transitions from cur_state to next_state for given char
  int transition(char);
  
  //returns true if state is a final state
  bool is_final_state(int);
  
  //makes indicated state final.
  void make_final_state(int);
  
  //reset fsm (curstate->0)
  int reset();
};


#endif //FSM_H
