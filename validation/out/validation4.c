#include <stdio.h>
#include <math.h>

int main()
{
    //declare registers and main memory
    int R[16]; //allocate registers
    int MM[32768]; //allocate main memory
    
    #include "WilseyRuntime.c"
    
    R[0] = 0; //stack pointer set to beginning of memory
    R[5] = 32767; //string allocation register set to end of memory
    MM[R[5]] = 0; //load last location in string memory with null terminator
    goto label0; //jump over function code
        label1: //start of function 'main'
        //Code for function 'main':
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'true' from stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label2: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label3; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label2; //check again
        label3: //R[4] now points to correct activation record
        R[4] = R[4] + 5; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] != R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'false' from stack
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label5: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label6; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label5; //check again
        label6: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__runtime library__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 121; //y
        MM[R[5] - 5] = 114; //r
        MM[R[5] - 6] = 97; //a
        MM[R[5] - 7] = 114; //r
        MM[R[5] - 8] = 98; //b
        MM[R[5] - 9] = 105; //i
        MM[R[5] - 10] = 108; //l
        MM[R[5] - 11] = 32; // 
        MM[R[5] - 12] = 101; //e
        MM[R[5] - 13] = 109; //m
        MM[R[5] - 14] = 105; //i
        MM[R[5] - 15] = 116; //t
        MM[R[5] - 16] = 110; //n
        MM[R[5] - 17] = 117; //u
        MM[R[5] - 18] = 114; //r
        MM[R[5] - 19] = 95; //_
        MM[R[5] - 20] = 95; //_
        R[5] = R[5] - 20; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label8; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label8: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label9: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label10; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label9; //check again
        label10: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 16
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 16; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label12: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label13; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label12; //check again
        label13: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 16
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 16; //push value onto stack
        //calling function 'sqrt'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 6; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label15; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run6; //branch to function
        label15: //function return address
        //immediate value 4
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label16; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label16: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label17: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label18; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label17; //check again
        label18: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //calling function 'int2bool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label20; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run7; //branch to function
        label20: //function return address
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label21: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label22; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label21; //check again
        label22: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label23; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label23: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label24: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label25; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label24; //check again
        label25: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 25
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 25; //push value onto stack
        //calling function 'int2bool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label27; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run7; //branch to function
        label27: //function return address
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label28: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label29; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label28; //check again
        label29: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label30; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label30: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label31: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label32; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label31; //check again
        label32: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 25
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 25; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //calling function 'int2bool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label34; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run7; //branch to function
        label34: //function return address
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label35: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label36; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label35; //check again
        label36: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label37; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label37: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label38: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label39; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label38; //check again
        label39: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label41: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label42; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label41; //check again
        label42: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'bool2int'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label43; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run8; //branch to function
        label43: //function return address
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label44; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label44: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label45: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label46; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label45; //check again
        label46: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label48: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label49; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label48; //check again
        label49: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'bool2int'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label50; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run8; //branch to function
        label50: //function return address
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label51; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label51: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label52: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label53; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label52; //check again
        label53: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 33
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 33; //push value onto stack
        //calling function 'int2bool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label55; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run7; //branch to function
        label55: //function return address
        //calling function 'bool2int'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label56; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run8; //branch to function
        label56: //function return address
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label57; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label57: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label58: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label59; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label58; //check again
        label59: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //calling function 'int2bool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label61; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run7; //branch to function
        label61: //function return address
        //calling function 'bool2int'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label62; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run8; //branch to function
        label62: //function return address
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label63; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label63: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label64: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label65; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label64; //check again
        label65: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //returning from function 'main'
        R[4] = R[2]; //move the current frame pointer out of the way
        R[2] = MM[R[4]]; //restore frame pointer from previous activation record
        R[6] = MM[R[4] + 2]; //load return address from stack
        R[0] = R[4] - 1; //set stack pointer to beginning of return destination
        R[4] = R[4] + 9; //set pointer to beginning of return value
        R[7] = MM[R[4]]; //load value from return source
        MM[R[0]] = R[7]; //store value to return destination
        goto *R[6]; //return to caller
        //failsafe return
        //immediate value 32767
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 32767; //push value onto stack
        //returning from function 'main'
        R[4] = R[2]; //move the current frame pointer out of the way
        R[2] = MM[R[4]]; //restore frame pointer from previous activation record
        R[6] = MM[R[4] + 2]; //load return address from stack
        R[0] = R[4] - 1; //set stack pointer to beginning of return destination
        R[4] = R[4] + 9; //set pointer to beginning of return value
        R[7] = MM[R[4]]; //load value from return source
        MM[R[0]] = R[7]; //store value to return destination
        goto *R[6]; //return to caller
    label0: //end of function 'main'
    R[0] = R[0] + 1; //allocate parameter space for main function
    //calling function 'main'
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = R[2]; //save frame pointer
    R[2] = R[0]; //frame pointer now points to this frame
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = 9; //push lexical id onto stack
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = (int)&&label69; //push return address onto stack
    R[0] = R[0] + 6; //allocate stack space for function variables
    goto label1; //branch to function
    label69: //function return address
    return 0; //exit status
}
