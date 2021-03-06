#include <sstream>
#include "code_writer.h"
#include "report_error.h"

#define DEBUG_REG

code_writer::code_writer(){
  label_num = 0;
  // R0 and R1 should be reserved, and start out full.
  registers.push_back(1); 
  registers.push_back(1);
  //and R[2] too?
  registers.push_back(1);
  string_table_ptr = MM_SIZE;
  string_table_ptr--;
}
code_writer::code_writer(string gen_file,string code_defs_file,string std_defs_file){
  this->gen_file = gen_file;
  this->code_defs_file = code_defs_file;
  this->std_defs_file = std_defs_file;
  
  generated_code.open(gen_file.c_str());
  label_num = 0;
  
  // R0 and R1 should be reserved, and start out full.
  registers.push_back(1); 
  registers.push_back(1);
  //and R[2] too?
  registers.push_back(1);
  string_table_ptr = MM_SIZE;
  string_table_ptr--;
}
void code_writer::init_code_defs(){
  if(!code_defs.is_open()){
    code_defs.open(code_defs_file.c_str());
  }
  if(code_defs.is_open()){
    int mm_size = MM_SIZE;
    code_defs << "#define MAX_USED_REGISTER " << registers.size()  << endl
	      << "#define MM_SIZE " << mm_size  << endl;
  }
}
void code_writer::init_std_defs(){
  if(!std_defs.is_open()){
    std_defs.open(std_defs_file.c_str());
  }
  if(std_defs.is_open()){
    std_defs << "#include \"" << code_defs_file << "\"" << endl
	     << endl
	     << "int R[MAX_USED_REGISTER];" << endl
	     <<  "int MM[MM_SIZE];" << endl;
  }
}
void code_writer::init_generated_code(){
 if(!generated_code.is_open()){
    generated_code.open(gen_file.c_str());
  }
  if(generated_code.is_open()){
    generated_code << "#include \"" << code_defs_file << "\"" << endl
		   << "#include \"" << std_defs_file << "\"" << endl
		   << "#include \"runtime.h\"" << endl
#ifdef DEBUG_REG
		   << "#include <stdio.h>" << endl
#endif
		   << "int main(){" << endl
#ifdef DEBUG_REG
		   << "int i;" << endl
#endif
      ;
  }
}

void code_writer::finalize_generated_code(){
  if(!generated_code.is_open()){
    generated_code.open(gen_file.c_str());
  }
  if(generated_code.is_open()){
    generated_code <<  "R[0] = 0;" << endl
		   <<  "R[1] = R[0];" << endl
		   <<  "MM[R[0]] = &&L0;" << endl
		   <<  "MM[R[0]+1] = &&end;" << endl
		   <<  "R[1] = R[1]+2;" << endl
		   <<  "goto L0;" << endl
      // add hooks for runtime functions.
		   << "GETBOOL: MM[R[0]] = getBool();" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "GETINT: MM[R[0]] = getInt();" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "GETSTRING: MM[R[0]] = getString();" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "PUTBOOL: MM[R[0]] = putBool(MM[R[0] + 2]);" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "PUTINT: MM[R[0]] = putInt(MM[R[0] + 2]);" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "PUTSTRING: MM[R[0]] = putString(MM[R[0] + 2]);" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "SQRT: MM[R[0]] = isqrt(MM[R[0] + 2]);" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "INT2BOOL: MM[R[0]] = int2bool(MM[R[0] + 2]);" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
		   << "BOOL2INT: MM[R[0]] = bool2int(MM[R[0] + 2]);" << endl
		   << "R[2] = MM[R[0]+1];" << endl
		   << "goto *R[2]; //write return statement" << endl
      //end
		   << "end: "
#ifdef DEBUG_REG
		   << "printf(\"\\n\");" << endl
		   << "for(i = 0; i < MAX_USED_REGISTER; i++)" << endl
      		   << "printf(\"R[%d] = %d\\n\",i,R[i]);" <<endl
		   << "printf(\"\\n\\n\");" << endl
		   << "for(i = 0; i < 20; i++)" << endl
		   << "printf(\"MM[%d] = %d\\t\\t MM[%d] = %d\\n\",i,MM[i],MM_SIZE - 1 - i, MM[MM_SIZE - 1 - i]);" <<endl
      //<< "for(i = MM_SIZE - 1; i > MM_SIZE - 20; i--)" << endl
      //	   << "printf(\"MM[%d] = %d\\n\",i,MM[i]);" <<endl
#endif
		   << " return 0;" << endl
		   << " }" << endl;
    generated_code.close();
  }
}

void code_writer::write_code(string line){
 if(generated_code.is_open()){
#ifdef DEBUG
   cout << "wrote code: " <<  line << endl;
#endif
    generated_code << line;
  }
}
void code_writer::write_code_defs(string line){
  if(!code_defs.is_open()){
    code_defs.open(code_defs_file.c_str());
  }
  if(code_defs.is_open()){
    code_defs << line << endl;
  }
}
void code_writer::write_std_defs(string line){
  if(!std_defs.is_open()){
    std_defs.open(std_defs_file.c_str());
  }
  if(std_defs.is_open()){
    std_defs << line << endl;
  }
}
void code_writer::open_generated_code(string filename){
  generated_code.open(filename.c_str());
}
void code_writer::open_code_defs(string filename){
  code_defs.open(filename.c_str());
}
void code_writer::open_std_defs(string filename){
  std_defs.open(filename.c_str());
}

/*int code_writer::get_register_num(){
  return register_num;
  }*/

/*void code_writer::inc_register_num(){
  register_num++;
  }*/

int code_writer::get_next_free_reg(){
  for(vector<bool>::iterator it = registers.begin(); it != registers.end(); it++){
    if(!*it){ //if it points to a free register
      return it - registers.begin();
    }
  }
  //looped through all without finding free reg, add one.
  registers.push_back(false);
  return registers.size()-1;
}

bool code_writer::use_reg(int rnum){
  if(rnum >= registers.size()){
    cerr << "Register R[" << rnum << "] is outside scope of registers (trying to use)" << endl;
    return false;
  }
  if(!registers[rnum]){
    stringstream ss;
    ss << "using R[" << rnum << "]" <<endl;
    debug(ss.str());
    registers[rnum] = true;
    return true;
  }else{
    cerr << "Register R[" << rnum << "] still in use!"  << endl;
    return false;
  }
}

bool code_writer::free_reg(int rnum){
  if(rnum >= registers.size()){
    cerr << "Register R[" << rnum << "] is outside scope of registers (trying to free)" << endl;
    return false;
  }
  if(rnum < 2){
    cerr << "Register R[" << rnum << "] is reserved, cannot free it!"  << endl;
    return false;
  }
  if(registers[rnum]){
    stringstream ss;
    ss << "Freeing R[" << rnum << "]" <<  endl;
    debug(ss.str());
    registers[rnum] = false;
    return true;
  }else{
    cerr << "Register R[" << rnum << "] already free!"  << endl;
    return false;
  }
}

string code_writer::get_gen_filename(){
  return gen_file;
}


string code_writer::get_std_defs_filename(){
  return std_defs_file;
}
string code_writer::get_code_defs_filename(){
  return code_defs_file;
}

string code_writer::get_next_label(){
  stringstream ss;
  ss << "L" << label_num++;
  return ss.str();
}

int code_writer::add_string(string str){
  //char * cstr = str.c_str();
  stringstream ss;
  str.erase(0,1);
  str.erase(str.length()-1,1);
  int strstart = string_table_ptr;
  for(int i = 0; i < str.length(); i++){
    ss << "MM[" << strstart - i << "] = \'" << str[i] << "\';" << endl;
  }
  ss << "MM[" << strstart - str.length() << "] = \'\\0\';" << endl;
  write_code(ss.str());

  string_table_ptr -= (str.length() + 1); // move ptr so it points at
					  // next free slot for string
  return strstart;
}
