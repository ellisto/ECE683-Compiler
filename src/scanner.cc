#include<fstream>
#include "token.h"
#include "scanner.h"
#include "report_error.h"
#include "fsm.h"
#include<cstdlib>
#include<cstring>

using namespace std;  

//int linenumber =0;

scanner::scanner(){
  this->in = new ifstream();
  this->l =  new line_counter();
  this->st = new symboltable();
  initFSM();
  //initST();
}

scanner::scanner(const char* filename){
  this->in = new ifstream(filename);
  this->l =  new line_counter();
  initFSM();
}

scanner::scanner(line_counter& lc,symboltable& st){
  this->l = &lc;
  this->in = new ifstream();
  this->st = &st;
  initFSM();
  //initST();
}
scanner::scanner(const char* filename, line_counter& lc, symboltable& st){
  this->in = new ifstream(filename);
  this->l = &lc;
  this->st = &st;
  initFSM();
  //initST();
}

/*void scanner::initST(){
  st->add(token(FUNCTION,string("function")));
  st->add(token(BEGIN,string("begin")));
  st->add(token(END,string("end")));
  st->add(token(TYPE,string("integer")));
  st->add(token(TYPE,string("boolean")));
  st->add(token(TYPE,string("string")));
  st->add(token(IF,string("if")));
  st->add(token(THEN,string("then")));
  st->add(token(ELSE,string("else")));
  st->add(token(WHILE,string("while")));
  st->add(token(CASE,string("case")));
  st->add(token(IS,string("is")));
  st->add(token(WHEN,string("when")));
  st->add(token(DEFAULT,string("default")));
  st->add(token(AND,string("and")));
  st->add(token(OR,string("or")));
  st->add(token(NOT,string("not")));
  }*/

void scanner::initFSM(){
  //initialize state machine
  
  //Gobble whitespace
  this->fsm.add_state_transition(0,WHITESPACE,0); 
  
  //IDs
  this->fsm.add_state_transition(0,LETTER,1);//
  this->fsm.add_state_transition(1,LETTER,1);
  this->fsm.add_state_transition(1,DIGIT,1);
  this->fsm.make_final_state(1);
  final_state_names.insert(pair<int,int>(1,ID));
  
  //STRING
  this->fsm.add_state_transition(0,QUOTE,2);
  this->fsm.add_state_transition(2,LETTER,2);
  this->fsm.add_state_transition(2,DIGIT,2);
  this->fsm.add_state_transition(2,WHITESPACE,2);
  this->fsm.add_state_transition(2,QUOTE,3);
  this->fsm.make_final_state(3);
  final_state_names.insert(pair<int,int>(3,STRING));
  
  //NUMBERS
  this->fsm.add_state_transition(0,DIGIT,4); 
  this->fsm.add_state_transition(4,DIGIT,4);
  this->fsm.make_final_state(4);
  final_state_names.insert(pair<int,int>(4,NUMBER));
  
  //COMMENTS and /
  this->fsm.add_state_transition(0,SLASH,5); 
  this->fsm.make_final_state(5);
  final_state_names.insert(pair<int,int>(5,DIVIDE));
  
  this->fsm.add_state_transition(5,SLASH,6); 
  this->fsm.make_final_state(6);
  final_state_names.insert(pair<int,int>(6,COMMENT));
  
  //+
  this->fsm.add_state_transition(0,PLUS,7);
  this->fsm.make_final_state(7);
  final_state_names.insert(pair<int,int>(7,ADD));
			   
  //-
  this->fsm.add_state_transition(0,MINUS,8);
  this->fsm.make_final_state(8);
  final_state_names.insert(pair<int,int>(8,SUB));
  
  //&
  this->fsm.add_state_transition(0,AMPERSAND,9);
  this->fsm.make_final_state(9);
  final_state_names.insert(pair<int,int>(9,BITAND));

  //|
  this->fsm.add_state_transition(0,PIPE,10);
  this->fsm.make_final_state(10);
  final_state_names.insert(pair<int,int>(10,BITOR));

  //(
  this->fsm.add_state_transition(0,LPARENc,11);
  this->fsm.make_final_state(11);
  final_state_names.insert(pair<int,int>(11,LPAREN));

  //)
  this->fsm.add_state_transition(0,RPARENc,12);
  this->fsm.make_final_state(12);
  final_state_names.insert(pair<int,int>(12,RPAREN));

  //[
  this->fsm.add_state_transition(0,LBRACKETc,13);
  this->fsm.make_final_state(13);
  final_state_names.insert(pair<int,int>(13,LBRACKET));

  //]
  this->fsm.add_state_transition(0,RBRACKETc,14);
  this->fsm.make_final_state(14);
  final_state_names.insert(pair<int,int>(14,RBRACKET));
  
  //*
  this->fsm.add_state_transition(0,ASTERISK,15);
  this->fsm.make_final_state(15);
  final_state_names.insert(pair<int,int>(15,TIMES));
  
  //.
  this->fsm.add_state_transition(0,PERIODc,16);
  this->fsm.make_final_state(16);
  final_state_names.insert(pair<int,int>(16,PERIOD));

  //,
  this->fsm.add_state_transition(0,COMMAc,23);
  this->fsm.make_final_state(23);
  final_state_names.insert(pair<int,int>(23,COMMA));

  //;
  this->fsm.add_state_transition(0,SEMICOLONc,17);
  this->fsm.make_final_state(17);
  final_state_names.insert(pair<int,int>(17,SEMICOLON));

  //:=
  this->fsm.add_state_transition(0,COLON,18);
  this->fsm.add_state_transition(18,EQUAL,19);
  this->fsm.make_final_state(19);
  final_state_names.insert(pair<int,int>(19,ASSIGN));

  //<, >
  this->fsm.add_state_transition(0,LT,20);
  this->fsm.add_state_transition(0,GT,20);
  this->fsm.make_final_state(20);
  final_state_names.insert(pair<int,int>(20,RELOP));

  //!=
  this->fsm.add_state_transition(0,EXCLAIM,21);
  this->fsm.add_state_transition(21,EQUAL,20);

  //==
  this->fsm.add_state_transition(0,EQUAL,22);
  this->fsm.add_state_transition(22,EQUAL,20);

}

bool scanner::attach_file(const char* filename){
  this->in->open(filename);
  this->l->reset();
  return this->in->good();
}

int scanner::get_char_class(char c){
  int char_class;
  if(c<=8){
    //control codes
    char_class = INVALID;
  }else if(c <= 13){ 
    //whitespace
    char_class = WHITESPACE;
  }else if(c <= 31){ 
    //more control codes
    char_class = INVALID;
  }else if(c == 32){ 
    //space
    char_class = WHITESPACE;
  }else if(c == 33){ 
    char_class = EXCLAIM;
  }else if(c == 34){
    char_class=QUOTE;
  }else if(c == 38){
    char_class=AMPERSAND;
  }else if(c == 40){
    char_class=LPARENc;
  }else if(c == 41){
    char_class=RPARENc;
  }else if(c == 42){
    char_class=ASTERISK;
  }else if(c == 43){
    char_class=PLUS;
  }else if(c == 44){
    char_class=COMMAc;
  }else if(c == 45){
    char_class=MINUS;
  }else if(c == 46){
    char_class=PERIODc;
  }else if(c == 47){
    char_class=SLASH;
  }
  else if(c <= 47){ 
    //punctuation; need to break up into smaller classes
    char_class = PUNCTUATION;
  }else if(c <= 57){ 
    //digit
    char_class = DIGIT;
  }
  else if(c == 58){
    char_class=COLON;
  }else if(c == 59){
    char_class=SEMICOLONc;
  }else if(c == 60){
    char_class=LT;
  }else if(c == 61){
    char_class=EQUAL;
  }else if(c == 62){
    char_class=GT;
  }
  else if(c <= 64){ 
    //more punctuation
    char_class = PUNCTUATION;
  }else if(c <= 90){ 
    //letter
    char_class = LETTER;
  }
  else if(c == 91){
    char_class=LBRACKETc;
  }else if(c == 93){
    char_class=RBRACKETc;
  }
  else if(c <= 96){ 
    //more punctuation
    char_class = PUNCTUATION;
  }else if(c <= 122){ 
    //lowercase letters
    char_class = LETTER;
  }else if(c == 124){
    char_class=PIPE;
  }else if(c <= 126){ 
    //yet more punctuation
    char_class = PUNCTUATION;
  }else{char_class = INVALID;}
  return char_class;
}

char scanner::get_lexeme_begin(){
  char tmp_lexeme_begin;
  if(this->in->good()){
    this->in->get(tmp_lexeme_begin);  
    //gobble whitespace, increment linenum on newline
    while(this->in->good() && get_char_class(tmp_lexeme_begin)==WHITESPACE){
      if(tmp_lexeme_begin=='\n'){
	l->increment();
      }
      this->in->get(tmp_lexeme_begin);
    }
    //this->in->putback(tmp_lexeme_begin);
  }
  return tmp_lexeme_begin;
}

token scanner::scan(){
  if(!this->in->good()){
    report_error("No valid file attached to scanner!");
    return *(new token());
  }
  this->fsm.reset();
  int curstate = this->fsm.get_cur_state();
  int nextstate;
  char * buffer = (char*) malloc(255);
  char * value;
  int type = -1;
  int i = 0;
  char lexeme_begin,next_char;
  
  lexeme_begin = get_lexeme_begin();
  next_char = lexeme_begin;
  
  while(this->in->good()){
    int next_char_class;
    
    next_char_class = get_char_class(next_char);
    
    nextstate = this->fsm.get_next_state(next_char_class);
    if(nextstate == -1){
      if(!this->fsm.is_final_state(curstate)){
	//no valid transition in nonfinal state
	char error[24];
	sprintf(error,"Unexpected character: %c",next_char);
	report_error(error, l->get_linenumber());
      }else{
	this->in->putback(next_char);
	buffer[i] = '\0';      
      }
      
      break;
    }
    curstate = this->fsm.transition(next_char_class);
    if(this->fsm.is_final_state(curstate)){
      type = final_state_names[curstate]; 
    }
    if(type==COMMENT){
      l->increment();
      char* commentstr = (char *) malloc (256);
      this->in->getline(commentstr,256);
      #ifdef DEBUG
      cout << "Got comment: " << commentstr << endl;
      #endif
      this->fsm.reset();
      buffer = (char*) malloc(255);
      i=0;
      lexeme_begin = get_lexeme_begin();
      next_char = lexeme_begin;
      continue;
    }

    if(i >= 255){
      report_error("buffer overflow",this->l->get_linenumber());
      return *(new token());
    }
    buffer[i++] = next_char;
    this->in->get(next_char);
  }

  
  if(this->in->eof()){
    if(i==0){
      value = "EOF";
      type=EOFMARKER;
    }else{
      value = (char*) malloc(i+1);
      strncpy(value,buffer,i);
      value[i]='\0';
      this->in->clear();
      this->in->putback('\n');
    }
  }else{
    value = (char*) malloc(i+1);
    strncpy(value,buffer,i);
    value[i]='\0';
  }
  
  token t(type,value);

  /*if(type == ID){
    cout << "New token value: " << value << endl;
    t = *st->add(t);
  }
  return t;*/
  
  token* tptr = st->find(t);
  if(!tptr)
    tptr = st->add(t); // add if it's not currently visible.
  //  cout << " added " << t << endl;
  return *tptr;
  //return *st->add(t);
}

bool scanner::good(){
  return this->in->good();
}

void scanner::set_st(symboltable* st){
  this->st =st;
}
