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
        //allocating string '__assignment statement__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 116; //t
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 101; //e
        MM[R[5] - 7] = 109; //m
        MM[R[5] - 8] = 101; //e
        MM[R[5] - 9] = 116; //t
        MM[R[5] - 10] = 97; //a
        MM[R[5] - 11] = 116; //t
        MM[R[5] - 12] = 115; //s
        MM[R[5] - 13] = 32; // 
        MM[R[5] - 14] = 116; //t
        MM[R[5] - 15] = 110; //n
        MM[R[5] - 16] = 101; //e
        MM[R[5] - 17] = 109; //m
        MM[R[5] - 18] = 110; //n
        MM[R[5] - 19] = 103; //g
        MM[R[5] - 20] = 105; //i
        MM[R[5] - 21] = 115; //s
        MM[R[5] - 22] = 115; //s
        MM[R[5] - 23] = 97; //a
        MM[R[5] - 24] = 95; //_
        MM[R[5] - 25] = 95; //_
        R[5] = R[5] - 25; //adjust string pointer
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
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
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
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label15: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label16; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label15; //check again
        label16: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
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
        MM[R[0]] = (int)&&label17; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label17: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label18: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label19; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label18; //check again
        label19: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 22
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 22; //push value onto stack
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
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
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label26: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label27; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label26; //check again
        label27: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label29: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label30; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label29; //check again
        label30: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 22
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 22; //push value onto stack
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
        MM[R[0]] = (int)&&label31; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label31: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label32: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label33; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label32; //check again
        label33: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 74
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 74; //push value onto stack
        //assigning to variable 'par' from stack
        //finding variable 'par'
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
        R[4] = R[4] - 1; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'par'
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
        R[6] = MM[R[4] - 1]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label40: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label41; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label40; //check again
        label41: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label43: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label44; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label43; //check again
        label44: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 74
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 74; //push value onto stack
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
        MM[R[0]] = (int)&&label45; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label45: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label46: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label47; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label46; //check again
        label47: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label49: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label50; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label49; //check again
        label50: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label51: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label52; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label51; //check again
        label52: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label54: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label55; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label54; //check again
        label55: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label56; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label56: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label57: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label58; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label57; //check again
        label58: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__if statement__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 116; //t
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 101; //e
        MM[R[5] - 7] = 109; //m
        MM[R[5] - 8] = 101; //e
        MM[R[5] - 9] = 116; //t
        MM[R[5] - 10] = 97; //a
        MM[R[5] - 11] = 116; //t
        MM[R[5] - 12] = 115; //s
        MM[R[5] - 13] = 32; // 
        MM[R[5] - 14] = 102; //f
        MM[R[5] - 15] = 105; //i
        MM[R[5] - 16] = 95; //_
        MM[R[5] - 17] = 95; //_
        R[5] = R[5] - 17; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //assigning to variable 'sar' from stack
        //finding variable 'sar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label60: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label61; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label60; //check again
        label61: //R[4] now points to correct activation record
        R[4] = R[4] + 7; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'sar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label63: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label64; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label63; //check again
        label64: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 7]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label65; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label65: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label66: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label67; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label66; //check again
        label67: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label69: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label70; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label69; //check again
        label70: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label71: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label72; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label71; //check again
        label72: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label74; //push if end address onto stack
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
        goto label76; //skip over if code block
        label75: //if-then
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label77: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label78; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label77; //check again
        label78: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label79: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label80; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label79; //check again
        label80: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label76: //end of if code block
        goto label83; //skip over if code block
        label82: //if-else
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label83: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label75; //branch to then
        goto label82; //branch to else
        label74: //end of if statement
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label84: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label85; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label84; //check again
        label85: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 4]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label86; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label86: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label87: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label88; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label87; //check again
        label88: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label90; //push if end address onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label91: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label92; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label91; //check again
        label92: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label94; //skip over if code block
        label93: //if-then
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label95: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label96; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label95; //check again
        label96: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label97; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label97: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label98: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label99; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label98; //check again
        label99: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label94: //end of if code block
        goto label102; //skip over if code block
        label101: //if-else
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label103: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label104; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label103; //check again
        label104: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label105; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label105: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label106: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label107; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label106; //check again
        label107: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label102: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label93; //branch to then
        goto label101; //branch to else
        label90: //end of if statement
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label109; //push if end address onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label110: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label111; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label110; //check again
        label111: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing not operation
        R[6] = MM[R[0] - 0]; //load not term
        R[6] = !R[6]; //perform not op
        MM[R[0] - 0] = R[6]; //put not result back onto stack
        goto label113; //skip over if code block
        label112: //if-then
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label114: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label115; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label114; //check again
        label115: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label116; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label116: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label117: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label118; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label117; //check again
        label118: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label113: //end of if code block
        goto label121; //skip over if code block
        label120: //if-else
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label122: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label123; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label122; //check again
        label123: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label124; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label124: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label125: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label126; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label125; //check again
        label126: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label121: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label112; //branch to then
        goto label120; //branch to else
        label109: //end of if statement
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label128: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label129; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label128; //check again
        label129: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label131; //push if end address onto stack
        //immediate value 6
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 6; //push value onto stack
        //immediate value 22
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 22; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] > R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        goto label133; //skip over if code block
        label132: //if-then
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label134: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label135; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label134; //check again
        label135: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label136: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label137; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label136; //check again
        label137: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label139: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label140; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label139; //check again
        label140: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label141: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label142; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label141; //check again
        label142: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label144: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label145; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label144; //check again
        label145: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 4
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label146: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label147; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label146; //check again
        label147: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label133: //end of if code block
        goto label150; //skip over if code block
        label149: //if-else
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label151: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label152; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label151; //check again
        label152: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label153: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label154; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label153; //check again
        label154: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label156: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label157; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label156; //check again
        label157: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label158: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label159; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label158; //check again
        label159: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label161: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label162; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label161; //check again
        label162: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1000
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1000; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label163: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label164; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label163; //check again
        label164: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label150: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label132; //branch to then
        goto label149; //branch to else
        label131: //end of if statement
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label166: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label167; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label166; //check again
        label167: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1110
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1110; //push value onto stack
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
        MM[R[0]] = (int)&&label168; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label168: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label169: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label170; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label169; //check again
        label170: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label172: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label173; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label172; //check again
        label173: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label175; //push if end address onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label176: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label177; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label176; //check again
        label177: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label179; //skip over if code block
        label178: //if-then
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label180; //push if end address onto stack
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label181: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label182; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label181; //check again
        label182: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label184; //skip over if code block
        label183: //if-then
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label185: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label186; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label185; //check again
        label186: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label187: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label188; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label187; //check again
        label188: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label184: //end of if code block
        goto label191; //skip over if code block
        label190: //if-else
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label192; //push if end address onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label193: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label194; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label193; //check again
        label194: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label196; //skip over if code block
        label195: //if-then
        //if statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label197; //push if end address onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label198: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label199; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label198; //check again
        label199: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label201; //skip over if code block
        label200: //if-then
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label202: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label203; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label202; //check again
        label203: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label204: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label205; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label204; //check again
        label205: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label201: //end of if code block
        goto label208; //skip over if code block
        label207: //if-else
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label209: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label210; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label209; //check again
        label210: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label211: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label212; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label211; //check again
        label212: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label208: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label200; //branch to then
        goto label207; //branch to else
        label197: //end of if statement
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label196: //end of if code block
        goto label215; //skip over if code block
        label214: //if-else
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label215: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label195; //branch to then
        goto label214; //branch to else
        label192: //end of if statement
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label191: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label183; //branch to then
        goto label190; //branch to else
        label180: //end of if statement
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label179: //end of if code block
        goto label217; //skip over if code block
        label216: //if-else
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of if statement
        label217: //end of if code block
        R[6] = MM[R[0]]; //load branch decision value
        R[0] = R[0] - 1; //decrement stack pointer
        if(R[6] == 1)
        goto label178; //branch to then
        goto label216; //branch to else
        label175: //end of if statement
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label218: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label219; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label218; //check again
        label219: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
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
        MM[R[0]] = (int)&&label220; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label220: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label221: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label222; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label221; //check again
        label222: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__while statement__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 116; //t
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 101; //e
        MM[R[5] - 7] = 109; //m
        MM[R[5] - 8] = 101; //e
        MM[R[5] - 9] = 116; //t
        MM[R[5] - 10] = 97; //a
        MM[R[5] - 11] = 116; //t
        MM[R[5] - 12] = 115; //s
        MM[R[5] - 13] = 32; // 
        MM[R[5] - 14] = 101; //e
        MM[R[5] - 15] = 108; //l
        MM[R[5] - 16] = 105; //i
        MM[R[5] - 17] = 104; //h
        MM[R[5] - 18] = 119; //w
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
        MM[R[0]] = (int)&&label224; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label224: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label225: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label226; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label225; //check again
        label226: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label228: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label229; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label228; //check again
        label229: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //while statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label232; //push while end address onto stack
        label231: //while loop start
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label233: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label234; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label233; //check again
        label234: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] > R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        R[6] = MM[R[0]]; //load loop decision value from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = MM[R[0]]; //load loop end address from stack
        if(R[6] == 0)
        goto *R[7]; //branch to end of while loop
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label235: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label236; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label235; //check again
        label236: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label237: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label238; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label237; //check again
        label238: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        goto label231; //branch to start of while loop
        label232: //end of while loop
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label240: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label241; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label240; //check again
        label241: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
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
        MM[R[0]] = (int)&&label242; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label242: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label243: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label244; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label243; //check again
        label244: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label246: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label247; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label246; //check again
        label247: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label249: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label250; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label249; //check again
        label250: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //while statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label253; //push while end address onto stack
        label252: //while loop start
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label254: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label255; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label254; //check again
        label255: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 11
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 11; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] < R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        R[6] = MM[R[0]]; //load loop decision value from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = MM[R[0]]; //load loop end address from stack
        if(R[6] == 0)
        goto *R[7]; //branch to end of while loop
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label256: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label257; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label256; //check again
        label257: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label258: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label259; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label258; //check again
        label259: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label260: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label261; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label260; //check again
        label261: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label263: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label264; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label263; //check again
        label264: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label265: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label266; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label265; //check again
        label266: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        goto label252; //branch to start of while loop
        label253: //end of while loop
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label268: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label269; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label268; //check again
        label269: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 55
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 55; //push value onto stack
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
        MM[R[0]] = (int)&&label270; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label270: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label271: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label272; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label271; //check again
        label272: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label274: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label275; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label274; //check again
        label275: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'par' from stack
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label277: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label278; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label277; //check again
        label278: //R[4] now points to correct activation record
        R[4] = R[4] - 1; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label280: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label281; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label280; //check again
        label281: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //while statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label284; //push while end address onto stack
        label283: //while loop start
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label285: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label286; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label285; //check again
        label286: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 4
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] < R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        R[6] = MM[R[0]]; //load loop decision value from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = MM[R[0]]; //load loop end address from stack
        if(R[6] == 0)
        goto *R[7]; //branch to end of while loop
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label287: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label288; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label287; //check again
        label288: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //assigning to variable 'par' from stack
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label289: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label290; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label289; //check again
        label290: //R[4] now points to correct activation record
        R[4] = R[4] - 1; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //while statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label293; //push while end address onto stack
        label292: //while loop start
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label294: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label295; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label294; //check again
        label295: //R[4] now points to correct activation record
        R[6] = MM[R[4] - 1]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 5
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] < R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        R[6] = MM[R[0]]; //load loop decision value from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = MM[R[0]]; //load loop end address from stack
        if(R[6] == 0)
        goto *R[7]; //branch to end of while loop
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label296: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label297; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label296; //check again
        label297: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label298: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label299; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label298; //check again
        label299: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label301: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label302; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label301; //check again
        label302: //R[4] now points to correct activation record
        R[6] = MM[R[4] - 1]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'par' from stack
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label303: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label304; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label303; //check again
        label304: //R[4] now points to correct activation record
        R[4] = R[4] - 1; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        goto label292; //branch to start of while loop
        label293: //end of while loop
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'par' from stack
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label306: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label307; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label306; //check again
        label307: //R[4] now points to correct activation record
        R[4] = R[4] - 1; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //while statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label310; //push while end address onto stack
        label309: //while loop start
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label311: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label312; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label311; //check again
        label312: //R[4] now points to correct activation record
        R[6] = MM[R[4] - 1]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 5
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] < R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        R[6] = MM[R[0]]; //load loop decision value from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = MM[R[0]]; //load loop end address from stack
        if(R[6] == 0)
        goto *R[7]; //branch to end of while loop
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label313: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label314; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label313; //check again
        label314: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label315: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label316; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label315; //check again
        label316: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label318: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label319; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label318; //check again
        label319: //R[4] now points to correct activation record
        R[6] = MM[R[4] - 1]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'par' from stack
        //finding variable 'par'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label320: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label321; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label320; //check again
        label321: //R[4] now points to correct activation record
        R[4] = R[4] - 1; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        goto label309; //branch to start of while loop
        label310: //end of while loop
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label323: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label324; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label323; //check again
        label324: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label325: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label326; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label325; //check again
        label326: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        goto label283; //branch to start of while loop
        label284: //end of while loop
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label328: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label329; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label328; //check again
        label329: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 34
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 34; //push value onto stack
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
        MM[R[0]] = (int)&&label330; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label330: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label331: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label332; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label331; //check again
        label332: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__case statement__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 116; //t
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 101; //e
        MM[R[5] - 7] = 109; //m
        MM[R[5] - 8] = 101; //e
        MM[R[5] - 9] = 116; //t
        MM[R[5] - 10] = 97; //a
        MM[R[5] - 11] = 116; //t
        MM[R[5] - 12] = 115; //s
        MM[R[5] - 13] = 32; // 
        MM[R[5] - 14] = 101; //e
        MM[R[5] - 15] = 115; //s
        MM[R[5] - 16] = 97; //a
        MM[R[5] - 17] = 99; //c
        MM[R[5] - 18] = 95; //_
        MM[R[5] - 19] = 95; //_
        R[5] = R[5] - 19; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label334; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label334: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label335: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label336; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label335; //check again
        label336: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label338: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label339; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label338; //check again
        label339: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label341: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label342; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label341; //check again
        label342: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //case statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label344; //push case end address onto stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label345: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label346; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label345; //check again
        label346: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 8]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label348; //skip over case when code block
        label347: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label349: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label350; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label349; //check again
        label350: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label351: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label352; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label351; //check again
        label352: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label348: //end of when code block
        goto label355; //skip over case when code block
        label354: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label356: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label357; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label356; //check again
        label357: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label358: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label359; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label358; //check again
        label359: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label355: //end of when code block
        goto label362; //skip over case when code block
        label361: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label363: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label364; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label363; //check again
        label364: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label365: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label366; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label365; //check again
        label366: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label362: //end of when code block
        R[6] = MM[R[0]]; //load case decision value
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = 3; //load 3 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label347; //branch to 'when 3' code block
        R[7] = 9; //load 9 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label354; //branch to 'when 9' code block
        R[7] = 11; //load 11 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label361; //branch to 'when 11' code block
        R[0] = R[0] - 1; //decrement stack pointer
        goto label344; //failsafe branch to end of case statement
        label344: //end of case statement
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label368: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label369; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label368; //check again
        label369: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
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
        MM[R[0]] = (int)&&label370; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label370: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label371: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label372; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label371; //check again
        label372: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label374: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label375; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label374; //check again
        label375: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //case statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label377; //push case end address onto stack
        //immediate value 11
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 11; //push value onto stack
        goto label379; //skip over case when code block
        label378: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label380: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label381; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label380; //check again
        label381: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label382: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label383; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label382; //check again
        label383: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label379: //end of when code block
        goto label386; //skip over case when code block
        label385: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label387: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label388; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label387; //check again
        label388: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label389: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label390; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label389; //check again
        label390: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label386: //end of when code block
        goto label393; //skip over case when code block
        label392: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label394: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label395; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label394; //check again
        label395: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label396: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label397; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label396; //check again
        label397: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label393: //end of when code block
        goto label400; //skip over case default code block
        label399: //default
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label401: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label402; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label401; //check again
        label402: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1000
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1000; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label403: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label404; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label403; //check again
        label404: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label400: //end of when code block
        R[6] = MM[R[0]]; //load case decision value
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = 3; //load 3 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label378; //branch to 'when 3' code block
        R[7] = 9; //load 9 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label385; //branch to 'when 9' code block
        R[7] = 11; //load 11 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label392; //branch to 'when 11' code block
        goto label399; //branch to default code block
        R[0] = R[0] - 1; //decrement stack pointer
        goto label377; //failsafe branch to end of case statement
        label377: //end of case statement
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label406: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label407; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label406; //check again
        label407: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
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
        MM[R[0]] = (int)&&label408; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label408: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label409: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label410; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label409; //check again
        label410: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label412: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label413; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label412; //check again
        label413: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //case statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label415; //push case end address onto stack
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 12
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        goto label417; //skip over case when code block
        label416: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label418: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label419; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label418; //check again
        label419: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label420: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label421; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label420; //check again
        label421: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label417: //end of when code block
        goto label424; //skip over case when code block
        label423: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label425: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label426; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label425; //check again
        label426: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label427: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label428; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label427; //check again
        label428: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label424: //end of when code block
        goto label431; //skip over case when code block
        label430: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label432: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label433; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label432; //check again
        label433: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label434: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label435; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label434; //check again
        label435: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label431: //end of when code block
        goto label438; //skip over case default code block
        label437: //default
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label439: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label440; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label439; //check again
        label440: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1000
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1000; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label441: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label442; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label441; //check again
        label442: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label438: //end of when code block
        R[6] = MM[R[0]]; //load case decision value
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = 3; //load 3 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label416; //branch to 'when 3' code block
        R[7] = 9; //load 9 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label423; //branch to 'when 9' code block
        R[7] = 11; //load 11 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label430; //branch to 'when 11' code block
        goto label437; //branch to default code block
        R[0] = R[0] - 1; //decrement stack pointer
        goto label415; //failsafe branch to end of case statement
        label415: //end of case statement
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label444: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label445; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label444; //check again
        label445: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1000
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1000; //push value onto stack
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
        MM[R[0]] = (int)&&label446; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label446: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label447: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label448; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label447; //check again
        label448: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label450: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label451; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label450; //check again
        label451: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //case statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label453; //push case end address onto stack
        //immediate value 11
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 11; //push value onto stack
        goto label455; //skip over case when code block
        label454: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label456: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label457; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label456; //check again
        label457: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label458: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label459; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label458; //check again
        label459: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label455: //end of when code block
        goto label462; //skip over case when code block
        label461: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label463: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label464; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label463; //check again
        label464: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label465: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label466; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label465; //check again
        label466: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label462: //end of when code block
        goto label469; //skip over case when code block
        label468: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label470: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label471; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label470; //check again
        label471: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label472: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label473; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label472; //check again
        label473: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //case statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label475; //push case end address onto stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label476: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label477; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label476; //check again
        label477: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label479; //skip over case when code block
        label478: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label480: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label481; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label480; //check again
        label481: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 22
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 22; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label482: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label483; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label482; //check again
        label483: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label479: //end of when code block
        goto label486; //skip over case when code block
        label485: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label487: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label488; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label487; //check again
        label488: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 33
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 33; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label489: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label490; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label489; //check again
        label490: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //case statement
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label492; //push case end address onto stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label493: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label494; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label493; //check again
        label494: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        goto label496; //skip over case when code block
        label495: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label497: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label498; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label497; //check again
        label498: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 123
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 123; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label499: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label500; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label499; //check again
        label500: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label496: //end of when code block
        goto label503; //skip over case default code block
        label502: //default
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label504: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label505; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label504; //check again
        label505: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 2000
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2000; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label506: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label507; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label506; //check again
        label507: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label503: //end of when code block
        R[6] = MM[R[0]]; //load case decision value
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = 0; //load 0 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label495; //branch to 'when 0' code block
        goto label502; //branch to default code block
        R[0] = R[0] - 1; //decrement stack pointer
        goto label492; //failsafe branch to end of case statement
        label492: //end of case statement
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label486: //end of when code block
        goto label510; //skip over case when code block
        label509: //when
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label511: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label512; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label511; //check again
        label512: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 44
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 44; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label513: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label514; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label513; //check again
        label514: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label510: //end of when code block
        goto label517; //skip over case default code block
        label516: //default
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label518: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label519; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label518; //check again
        label519: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 44
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 44; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label520: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label521; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label520; //check again
        label521: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label517: //end of when code block
        R[6] = MM[R[0]]; //load case decision value
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = 77; //load 77 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label478; //branch to 'when 77' code block
        R[7] = 100; //load 100 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label485; //branch to 'when 100' code block
        R[7] = 10; //load 10 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label509; //branch to 'when 10' code block
        goto label516; //branch to default code block
        R[0] = R[0] - 1; //decrement stack pointer
        goto label475; //failsafe branch to end of case statement
        label475: //end of case statement
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label469: //end of when code block
        goto label524; //skip over case default code block
        label523: //default
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label525: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label526; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label525; //check again
        label526: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 1000
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1000; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label527: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label528; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label527; //check again
        label528: //R[4] now points to correct activation record
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[6] = MM[R[0]]; //load end address from stack
        R[0] = R[0] - 1; //decrement stack pointer
        goto *R[6]; //branch to end of case statement
        label524: //end of when code block
        R[6] = MM[R[0]]; //load case decision value
        R[0] = R[0] - 1; //decrement stack pointer
        R[7] = 3; //load 3 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label454; //branch to 'when 3' code block
        R[7] = 9; //load 9 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label461; //branch to 'when 9' code block
        R[7] = 11; //load 11 for comparison
        R[7] = R[6] - R[7]; //compare values
        if(R[7] == 0)
        goto label468; //branch to 'when 11' code block
        goto label523; //branch to default code block
        R[0] = R[0] - 1; //decrement stack pointer
        goto label453; //failsafe branch to end of case statement
        label453: //end of case statement
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label530: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label531; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label530; //check again
        label531: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 2133
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2133; //push value onto stack
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
        MM[R[0]] = (int)&&label532; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label532: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label533: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label534; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label533; //check again
        label534: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__arrays__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 115; //s
        MM[R[5] - 5] = 121; //y
        MM[R[5] - 6] = 97; //a
        MM[R[5] - 7] = 114; //r
        MM[R[5] - 8] = 114; //r
        MM[R[5] - 9] = 97; //a
        MM[R[5] - 10] = 95; //_
        MM[R[5] - 11] = 95; //_
        R[5] = R[5] - 11; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label536; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label536: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label537: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label538; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label537; //check again
        label538: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 5
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push value onto stack
        //assigning into array 'array1' from stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label540: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label541; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label540; //check again
        label541: //R[4] now points to correct activation record
        R[4] = R[4] + 9; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label542: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label543; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label542; //check again
        label543: //R[4] now points to correct activation record
        R[6] = MM[R[0]]; //load array index from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] + R[6]; //add index to frame pointer
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 5
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push value onto stack
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
        MM[R[0]] = (int)&&label544; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label544: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label545: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label546; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label545; //check again
        label546: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 6
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 6; //push value onto stack
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //assigning into array 'array1' from stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label548: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label549; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label548; //check again
        label549: //R[4] now points to correct activation record
        R[4] = R[4] + 9; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label550: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label551; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label550; //check again
        label551: //R[4] now points to correct activation record
        R[6] = MM[R[0]]; //load array index from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] + R[6]; //add index to frame pointer
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 6
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 6; //push value onto stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label552: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label553; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label552; //check again
        label553: //R[4] now points to correct activation record
        R[6] = MM[R[0]]; //load array index from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] + R[6]; //add index to frame pointer
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 1]; //load factor term
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 40
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 40; //push value onto stack
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
        MM[R[0]] = (int)&&label554; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label554: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label555: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label556; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label555; //check again
        label556: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 7
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push value onto stack
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //assigning into array 'array1' from stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label558: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label559; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label558; //check again
        label559: //R[4] now points to correct activation record
        R[4] = R[4] + 9; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //assigning into array 'array1' from stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label560: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label561; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label560; //check again
        label561: //R[4] now points to correct activation record
        R[4] = R[4] + 9; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //assigning into array 'array2' from stack
        //finding variable 'array2'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label562: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label563; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label562; //check again
        label563: //R[4] now points to correct activation record
        R[4] = R[4] + 19; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //immediate value 6
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 6; //push value onto stack
        //immediate value 200
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 200; //push value onto stack
        //assigning into array 'array2' from stack
        //finding variable 'array2'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label564: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label565; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label564; //check again
        label565: //R[4] now points to correct activation record
        R[4] = R[4] + 19; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //immediate value 7
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push value onto stack
        //immediate value 300
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 300; //push value onto stack
        //assigning into array 'array2' from stack
        //finding variable 'array2'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label566: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label567; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label566; //check again
        label567: //R[4] now points to correct activation record
        R[4] = R[4] + 19; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //immediate value 400
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 400; //push value onto stack
        //assigning into array 'array2' from stack
        //finding variable 'array2'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label568: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label569; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label568; //check again
        label569: //R[4] now points to correct activation record
        R[4] = R[4] + 19; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label570: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label571; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label570; //check again
        label571: //R[4] now points to correct activation record
        R[7] = 10; //load array size
        R[8] = 0; //initialize array counter
        label572: //start of array copy loop
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        R[4] = R[4] + 1; //increment location
        R[8] = R[8] + 1; //increment count
        R[6] = R[8] == R[7]; //check for completeion
        if(R[6] == 0)
        goto label572; //copy next array value, or fall through
        //assigning to variable 'array2' from stack
        //finding variable 'array2'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label573: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label574; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label573; //check again
        label574: //R[4] now points to correct activation record
        R[4] = R[4] + 28; //set poiner to destination
        R[6] = 10; //initialize assign loop count
        label575: //start of assign loop
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] - 1; //decrement destination pointer
        R[6] = R[6] - 1; //decrement loop count
        R[7] = R[6] == 0; //check if loop is finished
        if(R[7] == 0)
        goto label575; //copy next value
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //finding variable 'array2'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label576: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label577; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label576; //check again
        label577: //R[4] now points to correct activation record
        R[6] = MM[R[0]]; //load array index from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] + R[6]; //add index to frame pointer
        R[6] = MM[R[4] + 19]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
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
        MM[R[0]] = (int)&&label578; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label578: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label579: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label580; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label579; //check again
        label580: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'array2'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label582: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label583; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label582; //check again
        label583: //R[4] now points to correct activation record
        R[7] = 10; //load array size
        R[8] = 0; //initialize array counter
        label584: //start of array copy loop
        R[6] = MM[R[4] + 19]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        R[4] = R[4] + 1; //increment location
        R[8] = R[8] + 1; //increment count
        R[6] = R[8] == R[7]; //check for completeion
        if(R[6] == 0)
        goto label584; //copy next array value, or fall through
        //assigning to variable 'array1' from stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label585: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label586; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label585; //check again
        label586: //R[4] now points to correct activation record
        R[4] = R[4] + 18; //set poiner to destination
        R[6] = 10; //initialize assign loop count
        label587: //start of assign loop
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] - 1; //decrement destination pointer
        R[6] = R[6] - 1; //decrement loop count
        R[7] = R[6] == 0; //check if loop is finished
        if(R[7] == 0)
        goto label587; //copy next value
        //immediate value 7
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push value onto stack
        //finding variable 'array1'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label588: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label589; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label588; //check again
        label589: //R[4] now points to correct activation record
        R[6] = MM[R[0]]; //load array index from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] + R[6]; //add index to frame pointer
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
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
        MM[R[0]] = (int)&&label590; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label590: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label591: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label592; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label591; //check again
        label592: //R[4] now points to correct activation record
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
        R[4] = R[4] + 29; //set pointer to beginning of return value
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
        R[4] = R[4] + 29; //set pointer to beginning of return value
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
    MM[R[0]] = (int)&&label596; //push return address onto stack
    R[0] = R[0] + 26; //allocate stack space for function variables
    goto label1; //branch to function
    label596: //function return address
    return 0; //exit status
}
