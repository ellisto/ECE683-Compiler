#include<iostream>
#include "fsm.h"

using namespace std;

int main(){
  FSM statemachine;
  cout << "Initializing state machine..." << endl;
  statemachine.add_state_transition(0,'a',1);
  statemachine.add_state_transition(0,'b',2);
  statemachine.add_state_transition(2,'b',2);
  statemachine.add_state_transition(2,'a',3);
  
  statemachine.make_final_state(1);
  statemachine.make_final_state(3);
  
  char nextchar;
  int curstate = statemachine.get_cur_state();
  while(!statemachine.is_final_state(curstate)){
    cout << "Current state: " << curstate << endl;
    cout << "Enter a character:" << endl;
    cin >> nextchar;
    cout << "Transitioning to " << statemachine.transition(nextchar) << "..." << endl;
    curstate = statemachine.get_cur_state();
  }
  cout << "In final state! Exiting..." << endl;
  return 0;
}
