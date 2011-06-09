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
        //allocating string '__expression operations__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 115; //s
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 111; //o
        MM[R[5] - 7] = 105; //i
        MM[R[5] - 8] = 116; //t
        MM[R[5] - 9] = 97; //a
        MM[R[5] - 10] = 114; //r
        MM[R[5] - 11] = 101; //e
        MM[R[5] - 12] = 112; //p
        MM[R[5] - 13] = 111; //o
        MM[R[5] - 14] = 32; // 
        MM[R[5] - 15] = 110; //n
        MM[R[5] - 16] = 111; //o
        MM[R[5] - 17] = 105; //i
        MM[R[5] - 18] = 115; //s
        MM[R[5] - 19] = 115; //s
        MM[R[5] - 20] = 101; //e
        MM[R[5] - 21] = 114; //r
        MM[R[5] - 22] = 112; //p
        MM[R[5] - 23] = 120; //x
        MM[R[5] - 24] = 101; //e
        MM[R[5] - 25] = 95; //_
        MM[R[5] - 26] = 95; //_
        R[5] = R[5] - 26; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label2; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label2: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label3: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label4; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label3; //check again
        label4: //R[4] now points to correct activation record
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
        //assigning to variable 'true' from stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label6: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label7; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label6; //check again
        label7: //R[4] now points to correct activation record
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
        label9: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label10; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label9; //check again
        label10: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'false'
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
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing not operation
        R[6] = MM[R[0] - 0]; //load not term
        R[6] = !R[6]; //perform not op
        MM[R[0] - 0] = R[6]; //put not result back onto stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label14: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label15; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label14; //check again
        label15: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
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
        MM[R[0]] = (int)&&label19; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label19: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label20: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label21; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label20; //check again
        label21: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label23: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label24; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label23; //check again
        label24: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label25: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label26; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label25; //check again
        label26: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing expression operation(s)
        R[6] = MM[R[0] - 1]; //load expression term
        R[7] = MM[R[0] - 0]; //load expression term
        R[6] = R[6] && R[7]; //perform expression op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push expression op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label27: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label28; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label27; //check again
        label28: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label30: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label31; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label30; //check again
        label31: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label32; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label32: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label33: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label34; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label33; //check again
        label34: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label36: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label37; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label36; //check again
        label37: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //finding variable 'false'
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
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing expression operation(s)
        R[6] = MM[R[0] - 1]; //load expression term
        R[7] = MM[R[0] - 0]; //load expression term
        R[6] = R[6] || R[7]; //perform expression op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push expression op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
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
        //finding variable 'false'
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
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //finding variable 'false'
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
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label53: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label54; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label53; //check again
        label54: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing expression operation(s)
        R[6] = MM[R[0] - 1]; //load expression term
        R[7] = MM[R[0] - 0]; //load expression term
        R[6] = R[6] && R[7]; //perform expression op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push expression op result on stack
        //performing expression operation(s)
        R[6] = MM[R[0] - 1]; //load expression term
        R[7] = MM[R[0] - 0]; //load expression term
        R[6] = R[6] || R[7]; //perform expression op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push expression op result on stack
        //performing not operation
        R[6] = MM[R[0] - 0]; //load not term
        R[6] = !R[6]; //perform not op
        MM[R[0] - 0] = R[6]; //put not result back onto stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label55: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label56; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label55; //check again
        label56: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
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
        MM[R[0]] = (int)&&label60; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label60: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label61: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label62; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label61; //check again
        label62: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__arithmetic operations__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 115; //s
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 111; //o
        MM[R[5] - 7] = 105; //i
        MM[R[5] - 8] = 116; //t
        MM[R[5] - 9] = 97; //a
        MM[R[5] - 10] = 114; //r
        MM[R[5] - 11] = 101; //e
        MM[R[5] - 12] = 112; //p
        MM[R[5] - 13] = 111; //o
        MM[R[5] - 14] = 32; // 
        MM[R[5] - 15] = 99; //c
        MM[R[5] - 16] = 105; //i
        MM[R[5] - 17] = 116; //t
        MM[R[5] - 18] = 101; //e
        MM[R[5] - 19] = 109; //m
        MM[R[5] - 20] = 104; //h
        MM[R[5] - 21] = 116; //t
        MM[R[5] - 22] = 105; //i
        MM[R[5] - 23] = 114; //r
        MM[R[5] - 24] = 97; //a
        MM[R[5] - 25] = 95; //_
        MM[R[5] - 26] = 95; //_
        R[5] = R[5] - 26; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label64; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label64: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label65: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label66; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label65; //check again
        label66: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //immediate value 12
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //immediate value 21
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 21; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label68: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label69; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label68; //check again
        label69: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
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
        MM[R[0]] = (int)&&label73; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label73: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label74: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label75; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label74; //check again
        label75: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 15
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 15; //push value onto stack
        //immediate value 5
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 2]; //load arithmetic term
        R[7] = MM[R[0] - 1]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] + R[7]; //perform arithmetic op
        R[0] = R[0] - 2; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label80: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label81; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label80; //check again
        label81: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label82; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label82: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label83: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label84; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label83; //check again
        label84: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 26
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 26; //push value onto stack
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //immediate value 18
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 18; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label86: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label87; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label86; //check again
        label87: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label89: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label90; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label89; //check again
        label90: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label91; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label91: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label92: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label93; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label92; //check again
        label93: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //immediate value 4
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] | R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //immediate value 12
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
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
        MM[R[0]] = (int)&&label100; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label100: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label101: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label102; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label101; //check again
        label102: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 31
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 31; //push value onto stack
        //immediate value 12
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] & R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //immediate value 12
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label104: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label105; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label104; //check again
        label105: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label107: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label108; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label107; //check again
        label108: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label109; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label109: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__relation operations__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 115; //s
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 111; //o
        MM[R[5] - 7] = 105; //i
        MM[R[5] - 8] = 116; //t
        MM[R[5] - 9] = 97; //a
        MM[R[5] - 10] = 114; //r
        MM[R[5] - 11] = 101; //e
        MM[R[5] - 12] = 112; //p
        MM[R[5] - 13] = 111; //o
        MM[R[5] - 14] = 32; // 
        MM[R[5] - 15] = 110; //n
        MM[R[5] - 16] = 111; //o
        MM[R[5] - 17] = 105; //i
        MM[R[5] - 18] = 116; //t
        MM[R[5] - 19] = 97; //a
        MM[R[5] - 20] = 108; //l
        MM[R[5] - 21] = 101; //e
        MM[R[5] - 22] = 114; //r
        MM[R[5] - 23] = 95; //_
        MM[R[5] - 24] = 95; //_
        R[5] = R[5] - 24; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label113; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label113: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label120: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label121; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label120; //check again
        label121: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label122; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label122: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label123: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label124; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label123; //check again
        label124: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label126: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label127; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label126; //check again
        label127: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //finding variable 'true'
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
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label130: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label131; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label130; //check again
        label131: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label133: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label134; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label133; //check again
        label134: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label135; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label135: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 7
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push value onto stack
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] != R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label142: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label143; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label142; //check again
        label143: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label144; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label144: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label145: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label146; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label145; //check again
        label146: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'false'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label148: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label149; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label148; //check again
        label149: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 6]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //finding variable 'true'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label150: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label151; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label150; //check again
        label151: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] != R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label152: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label153; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label152; //check again
        label153: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label155: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label156; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label155; //check again
        label156: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label157; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label157: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 7
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push value onto stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] > R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label164: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label165; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label164; //check again
        label165: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label166; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label166: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label167: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label168; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label167; //check again
        label168: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //immediate value 22
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 22; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] < R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label170: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label171; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label170; //check again
        label171: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label173: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label174; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label173; //check again
        label174: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label175; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label175: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__factor operations__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 115; //s
        MM[R[5] - 5] = 110; //n
        MM[R[5] - 6] = 111; //o
        MM[R[5] - 7] = 105; //i
        MM[R[5] - 8] = 116; //t
        MM[R[5] - 9] = 97; //a
        MM[R[5] - 10] = 114; //r
        MM[R[5] - 11] = 101; //e
        MM[R[5] - 12] = 112; //p
        MM[R[5] - 13] = 111; //o
        MM[R[5] - 14] = 32; // 
        MM[R[5] - 15] = 114; //r
        MM[R[5] - 16] = 111; //o
        MM[R[5] - 17] = 116; //t
        MM[R[5] - 18] = 99; //c
        MM[R[5] - 19] = 97; //a
        MM[R[5] - 20] = 102; //f
        MM[R[5] - 21] = 95; //_
        MM[R[5] - 22] = 95; //_
        R[5] = R[5] - 22; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label179; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label179: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label180: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label181; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label180; //check again
        label181: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 5
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push value onto stack
        //immediate value 7
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push value onto stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 1]; //load factor term
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 35
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 35; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label183: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label184; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label183; //check again
        label184: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label186: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label187; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label186; //check again
        label187: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label188; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label188: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label189: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label190; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label189; //check again
        label190: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //immediate value 4
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push value onto stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 3]; //load factor term
        R[7] = MM[R[0] - 2]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[7] = MM[R[0] - 1]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[0] = R[0] - 3; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //immediate value 4
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push value onto stack
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 3]; //load factor term
        R[7] = MM[R[0] - 2]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[7] = MM[R[0] - 1]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[0] = R[0] - 3; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label192: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label193; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label192; //check again
        label193: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label195: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label196; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label195; //check again
        label196: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label197; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label197: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //immediate value 4
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push value onto stack
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 3]; //load factor term
        R[7] = MM[R[0] - 2]; //load factor term
        R[6] = R[6] / R[7]; //perform factor op
        R[7] = MM[R[0] - 1]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] / R[7]; //perform factor op
        R[0] = R[0] - 3; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label201: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label202; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label201; //check again
        label202: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
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
        MM[R[0]] = (int)&&label206; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label206: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label207: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label208; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label207; //check again
        label208: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 1]; //load factor term
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] * R[7]; //perform factor op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 24
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 24; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label210: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label211; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label210; //check again
        label211: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label213: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label214; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label213; //check again
        label214: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label215; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label215: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label216: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label217; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label216; //check again
        label217: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 21
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 21; //push value onto stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 1]; //load factor term
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] / R[7]; //perform factor op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 7
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 7; //push value onto stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label219: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label220; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label219; //check again
        label220: //R[4] now points to correct activation record
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label222: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label223; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label222; //check again
        label223: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label224; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
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
        //immediate value 18
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 18; //push value onto stack
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 2
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 1]; //load factor term
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] / R[7]; //perform factor op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label231: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label232; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label231; //check again
        label232: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label233; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label233: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label234: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label235; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label234; //check again
        label235: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //performing factor operation(s)
        R[6] = MM[R[0] - 1]; //load factor term
        R[7] = MM[R[0] - 0]; //load factor term
        R[6] = R[6] / R[7]; //perform factor op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push factor op result on stack
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
        //performing arithmetic operation(s)
        R[6] = MM[R[0] - 1]; //load arithmetic term
        R[7] = MM[R[0] - 0]; //load arithmetic term
        R[6] = R[6] - R[7]; //perform arithmetic op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push arithmetic op result on stack
        //performing relation operation(s)
        R[6] = MM[R[0] - 1]; //load relation term
        R[7] = MM[R[0] - 0]; //load relation term
        R[6] = R[6] == R[7]; //perform relation op
        R[0] = R[0] - 1; //reduce stack by operations performed
        MM[R[0]] = R[6]; //push relation op result on stack
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
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
        R[0] = R[4] - 0; //set stack pointer to beginning of return destination
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
        R[0] = R[4] - 0; //set stack pointer to beginning of return destination
        R[4] = R[4] + 9; //set pointer to beginning of return value
        R[7] = MM[R[4]]; //load value from return source
        MM[R[0]] = R[7]; //store value to return destination
        goto *R[6]; //return to caller
    label0: //end of function 'main'
    R[0] = R[0] + 0; //allocate parameter space for main function
    //calling function 'main'
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = R[2]; //save frame pointer
    R[2] = R[0]; //frame pointer now points to this frame
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = 9; //push lexical id onto stack
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = (int)&&label248; //push return address onto stack
    R[0] = R[0] + 6; //allocate stack space for function variables
    goto label1; //branch to function
    label248: //function return address
    return 0; //exit status
}
