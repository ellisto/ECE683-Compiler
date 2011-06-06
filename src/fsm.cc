#include "fsm.h"
#include "report_error.h"
#include<string>
#include<iostream>
using namespace std;

FSM::FSM(){
  this->cur_state = 0;
}
int FSM::get_next_state(char c){
  map<char,int>::iterator it = this->next_state[this->cur_state].find(c);
  if(it == this->next_state[this->cur_state].end()){
    return -1; // no transition from this state with this char
  }
  return it->second;
}
int FSM::get_cur_state(){
  return this->cur_state;
}
// void FSM::add_state_transition(int from_state, char transition, int end_state){
//   if(from_state<this->next_state.size()){ //if from_state is already in the transition table
//     this->next_state[from_state][(int) transition] = end_state;
//     return;
//   }
//   int transitions[255];
//   transitions[(int) transition] = end_state;
//   if(from_state > this->next_state.capacity()){
//     this->next_state.resize(from_state);
//   }
//   this->next_state[from_state] = transitions;
//   return;
// }

void FSM::add_state_transition(int from_state, char next_char, int to_state){
  mapmapit itfrom, itto;
  itfrom = this->next_state.find(from_state);
  itto = this->next_state.find(to_state);
  if(itto == this->next_state.end()){ // if to state doesnt yet have an entry
    map<char,int> transitions;
    this->next_state.insert(pair<int, map<char,int> >(to_state,transitions));
    this->final_state.insert(pair<int,bool>(to_state,false));
    //cout << "added state : " << to_state << endl;
  }
  if(itfrom == this->next_state.end()){ // if from state doesnt yet have an entry
    map<char,int> transitions;
    transitions.insert(pair<char, int>(next_char,to_state));
    this->next_state.insert(pair<int, map<char,int> >(from_state,transitions));
    this->final_state.insert(pair<int,bool>(from_state,false));
    //cout << "added state : " << to_state << endl;
    //cout << "added transition: " << from_state << "->" << to_state << endl;
    return;
  }
  
  itfrom->second.insert(pair<char, int>(next_char,to_state));
  //cout << "added transition: " << from_state << "->" << to_state << endl;
  return;
}

bool FSM::is_final_state(int state){
  map<int,bool>::iterator it = this->final_state.find(state);
  if(it==this->final_state.end()){
    report_error("State not yet initialized!");
    return false;
  }
  return it->second;
}
void FSM::make_final_state(int state){
  map<int,bool>::iterator it = this->final_state.find(state);
  if(it==this->final_state.end()){
    report_error("State not yet initialized!");
    return;
  }
  it->second = true;
  return;
}

int FSM::transition(char next_char){
  this->cur_state = get_next_state(next_char);
  return this->cur_state;
}

int FSM::reset(){
  this->cur_state = 0;
  return this->cur_state;
}
