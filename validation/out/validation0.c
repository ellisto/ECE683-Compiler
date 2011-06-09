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
        //allocating string 'Runtime validation'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 110; //n
        MM[R[5] - 3] = 111; //o
        MM[R[5] - 4] = 105; //i
        MM[R[5] - 5] = 116; //t
        MM[R[5] - 6] = 97; //a
        MM[R[5] - 7] = 100; //d
        MM[R[5] - 8] = 105; //i
        MM[R[5] - 9] = 108; //l
        MM[R[5] - 10] = 97; //a
        MM[R[5] - 11] = 118; //v
        MM[R[5] - 12] = 32; // 
        MM[R[5] - 13] = 101; //e
        MM[R[5] - 14] = 109; //m
        MM[R[5] - 15] = 105; //i
        MM[R[5] - 16] = 116; //t
        MM[R[5] - 17] = 110; //n
        MM[R[5] - 18] = 117; //u
        MM[R[5] - 19] = 82; //R
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__basic io__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 111; //o
        MM[R[5] - 5] = 105; //i
        MM[R[5] - 6] = 32; // 
        MM[R[5] - 7] = 99; //c
        MM[R[5] - 8] = 105; //i
        MM[R[5] - 9] = 115; //s
        MM[R[5] - 10] = 97; //a
        MM[R[5] - 11] = 98; //b
        MM[R[5] - 12] = 95; //_
        MM[R[5] - 13] = 95; //_
        R[5] = R[5] - 13; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label6; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label6: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label7: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label8; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label7; //check again
        label8: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'enter true boolean'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 110; //n
        MM[R[5] - 3] = 97; //a
        MM[R[5] - 4] = 101; //e
        MM[R[5] - 5] = 108; //l
        MM[R[5] - 6] = 111; //o
        MM[R[5] - 7] = 111; //o
        MM[R[5] - 8] = 98; //b
        MM[R[5] - 9] = 32; // 
        MM[R[5] - 10] = 101; //e
        MM[R[5] - 11] = 117; //u
        MM[R[5] - 12] = 114; //r
        MM[R[5] - 13] = 116; //t
        MM[R[5] - 14] = 32; // 
        MM[R[5] - 15] = 114; //r
        MM[R[5] - 16] = 101; //e
        MM[R[5] - 17] = 116; //t
        MM[R[5] - 18] = 110; //n
        MM[R[5] - 19] = 101; //e
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
        MM[R[0]] = (int)&&label10; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label10: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label11: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label12; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label11; //check again
        label12: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'getBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label14; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run0; //branch to function
        label14: //function return address
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'got'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 116; //t
        MM[R[5] - 3] = 111; //o
        MM[R[5] - 4] = 103; //g
        R[5] = R[5] - 4; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label18; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label18: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label19: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label20; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label19; //check again
        label20: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'bar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label22: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label23; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label22; //check again
        label23: //R[4] now points to correct activation record
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
        MM[R[0]] = (int)&&label24; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label24: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'enter false boolean'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 110; //n
        MM[R[5] - 3] = 97; //a
        MM[R[5] - 4] = 101; //e
        MM[R[5] - 5] = 108; //l
        MM[R[5] - 6] = 111; //o
        MM[R[5] - 7] = 111; //o
        MM[R[5] - 8] = 98; //b
        MM[R[5] - 9] = 32; // 
        MM[R[5] - 10] = 101; //e
        MM[R[5] - 11] = 115; //s
        MM[R[5] - 12] = 108; //l
        MM[R[5] - 13] = 97; //a
        MM[R[5] - 14] = 102; //f
        MM[R[5] - 15] = 32; // 
        MM[R[5] - 16] = 114; //r
        MM[R[5] - 17] = 101; //e
        MM[R[5] - 18] = 116; //t
        MM[R[5] - 19] = 110; //n
        MM[R[5] - 20] = 101; //e
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
        MM[R[0]] = (int)&&label28; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label28: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'getBool'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label32; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run0; //branch to function
        label32: //function return address
        //assigning to variable 'bar' from stack
        //finding variable 'bar'
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
        R[4] = R[4] + 4; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'got'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 116; //t
        MM[R[5] - 3] = 111; //o
        MM[R[5] - 4] = 103; //g
        R[5] = R[5] - 4; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label36; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label36: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label37: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label38; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label37; //check again
        label38: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
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
        MM[R[0]] = (int)&&label42; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label42: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'enter positive integer'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 114; //r
        MM[R[5] - 3] = 101; //e
        MM[R[5] - 4] = 103; //g
        MM[R[5] - 5] = 101; //e
        MM[R[5] - 6] = 116; //t
        MM[R[5] - 7] = 110; //n
        MM[R[5] - 8] = 105; //i
        MM[R[5] - 9] = 32; // 
        MM[R[5] - 10] = 101; //e
        MM[R[5] - 11] = 118; //v
        MM[R[5] - 12] = 105; //i
        MM[R[5] - 13] = 116; //t
        MM[R[5] - 14] = 105; //i
        MM[R[5] - 15] = 115; //s
        MM[R[5] - 16] = 111; //o
        MM[R[5] - 17] = 112; //p
        MM[R[5] - 18] = 32; // 
        MM[R[5] - 19] = 114; //r
        MM[R[5] - 20] = 101; //e
        MM[R[5] - 21] = 116; //t
        MM[R[5] - 22] = 110; //n
        MM[R[5] - 23] = 101; //e
        R[5] = R[5] - 23; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label46; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label46: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label47: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label48; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label47; //check again
        label48: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'getInt'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label50; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run1; //branch to function
        label50: //function return address
        //assigning to variable 'var' from stack
        //finding variable 'var'
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
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'got'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 116; //t
        MM[R[5] - 3] = 111; //o
        MM[R[5] - 4] = 103; //g
        R[5] = R[5] - 4; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label54; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label54: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
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
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putInt'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label60; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run4; //branch to function
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'enter zero integer'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 114; //r
        MM[R[5] - 3] = 101; //e
        MM[R[5] - 4] = 103; //g
        MM[R[5] - 5] = 101; //e
        MM[R[5] - 6] = 116; //t
        MM[R[5] - 7] = 110; //n
        MM[R[5] - 8] = 105; //i
        MM[R[5] - 9] = 32; // 
        MM[R[5] - 10] = 111; //o
        MM[R[5] - 11] = 114; //r
        MM[R[5] - 12] = 101; //e
        MM[R[5] - 13] = 122; //z
        MM[R[5] - 14] = 32; // 
        MM[R[5] - 15] = 114; //r
        MM[R[5] - 16] = 101; //e
        MM[R[5] - 17] = 116; //t
        MM[R[5] - 18] = 110; //n
        MM[R[5] - 19] = 101; //e
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'getInt'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label68; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run1; //branch to function
        label68: //function return address
        //assigning to variable 'var' from stack
        //finding variable 'var'
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
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'got'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 116; //t
        MM[R[5] - 3] = 111; //o
        MM[R[5] - 4] = 103; //g
        R[5] = R[5] - 4; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label72; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label72: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label73: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label74; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label73; //check again
        label74: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label76: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label77; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label76; //check again
        label77: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putInt'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label78; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run4; //branch to function
        label78: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'enter negative integer'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 114; //r
        MM[R[5] - 3] = 101; //e
        MM[R[5] - 4] = 103; //g
        MM[R[5] - 5] = 101; //e
        MM[R[5] - 6] = 116; //t
        MM[R[5] - 7] = 110; //n
        MM[R[5] - 8] = 105; //i
        MM[R[5] - 9] = 32; // 
        MM[R[5] - 10] = 101; //e
        MM[R[5] - 11] = 118; //v
        MM[R[5] - 12] = 105; //i
        MM[R[5] - 13] = 116; //t
        MM[R[5] - 14] = 97; //a
        MM[R[5] - 15] = 103; //g
        MM[R[5] - 16] = 101; //e
        MM[R[5] - 17] = 110; //n
        MM[R[5] - 18] = 32; // 
        MM[R[5] - 19] = 114; //r
        MM[R[5] - 20] = 101; //e
        MM[R[5] - 21] = 116; //t
        MM[R[5] - 22] = 110; //n
        MM[R[5] - 23] = 101; //e
        R[5] = R[5] - 23; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label82; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'getInt'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label86; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run1; //branch to function
        label86: //function return address
        //assigning to variable 'var' from stack
        //finding variable 'var'
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
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'got'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 116; //t
        MM[R[5] - 3] = 111; //o
        MM[R[5] - 4] = 103; //g
        R[5] = R[5] - 4; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label90; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label90: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label94: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label95; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label94; //check again
        label95: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putInt'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 4; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label96; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run4; //branch to function
        label96: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label97: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label98; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label97; //check again
        label98: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'enter string'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 103; //g
        MM[R[5] - 3] = 110; //n
        MM[R[5] - 4] = 105; //i
        MM[R[5] - 5] = 114; //r
        MM[R[5] - 6] = 116; //t
        MM[R[5] - 7] = 115; //s
        MM[R[5] - 8] = 32; // 
        MM[R[5] - 9] = 114; //r
        MM[R[5] - 10] = 101; //e
        MM[R[5] - 11] = 116; //t
        MM[R[5] - 12] = 110; //n
        MM[R[5] - 13] = 101; //e
        R[5] = R[5] - 13; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label100; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
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
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'getString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 2; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label104; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run2; //branch to function
        label104: //function return address
        //assigning to variable 'sar' from stack
        //finding variable 'sar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label105: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label106; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label105; //check again
        label106: //R[4] now points to correct activation record
        R[4] = R[4] + 5; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string 'got'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 116; //t
        MM[R[5] - 3] = 111; //o
        MM[R[5] - 4] = 103; //g
        R[5] = R[5] - 4; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label108; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label108: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label109: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label110; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label109; //check again
        label110: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'sar'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label112: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label113; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label112; //check again
        label113: //R[4] now points to correct activation record
        R[6] = MM[R[4] + 5]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label114; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label114: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label115: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label116; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label115; //check again
        label116: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 1
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 1; //push value onto stack
        //returning from function 'main'
        R[4] = R[2]; //move the current frame pointer out of the way
        R[2] = MM[R[4]]; //restore frame pointer from previous activation record
        R[6] = MM[R[4] + 2]; //load return address from stack
        R[0] = R[4] - 0; //set stack pointer to beginning of return destination
        R[4] = R[4] + 7; //set pointer to beginning of return value
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
        R[4] = R[4] + 7; //set pointer to beginning of return value
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
    MM[R[0]] = (int)&&label120; //push return address onto stack
    R[0] = R[0] + 4; //allocate stack space for function variables
    goto label1; //branch to function
    label120: //function return address
    return 0; //exit status
}
