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
        goto label2; //jump over function code
            label3: //start of function 'get3'
            //Code for function 'get3':
            //immediate value 3
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 3; //push value onto stack
            //returning from function 'get3'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 0; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'get3'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 0; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label2: //end of function 'get3'
        goto label6; //jump over function code
            label7: //start of function 'increment'
            //Code for function 'increment':
            //finding variable 'i'
            R[3] = 11; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label8: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label9; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label8; //check again
            label9: //R[4] now points to correct activation record
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
            //assigning to variable 'i' from stack
            //finding variable 'i'
            R[3] = 11; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label10: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label11; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label10; //check again
            label11: //R[4] now points to correct activation record
            R[4] = R[4] - 1; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //finding variable 'i'
            R[3] = 11; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label13: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label14; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label13; //check again
            label14: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //returning from function 'increment'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'increment'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label6: //end of function 'increment'
        goto label17; //jump over function code
            label18: //start of function 'add'
            //Code for function 'add':
            //finding variable 'i'
            R[3] = 12; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label19: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label20; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label19; //check again
            label20: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 2]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //finding variable 'j'
            R[3] = 12; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label21: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label22; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label21; //check again
            label22: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //performing arithmetic operation(s)
            R[6] = MM[R[0] - 1]; //load arithmetic term
            R[7] = MM[R[0] - 0]; //load arithmetic term
            R[6] = R[6] + R[7]; //perform arithmetic op
            R[0] = R[0] - 1; //reduce stack by operations performed
            MM[R[0]] = R[6]; //push arithmetic op result on stack
            //returning from function 'add'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 2; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'add'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 2; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label17: //end of function 'add'
        goto label25; //jump over function code
            label26: //start of function 'incrementVar'
            //Code for function 'incrementVar':
            //finding variable 'var'
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
            label29: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label30; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label29; //check again
            label30: //R[4] now points to correct activation record
            R[4] = R[4] + 3; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //immediate value 0
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 0; //push value onto stack
            //returning from function 'incrementVar'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 0; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'incrementVar'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 0; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label25: //end of function 'incrementVar'
        goto label34; //jump over function code
            label35: //start of function 'get123nest'
            //Code for function 'get123nest':
            goto label36; //jump over function code
                label37: //start of function 'add100'
                //Code for function 'add100':
                goto label38; //jump over function code
                    label39: //start of function 'add20'
                    //Code for function 'add20':
                    goto label40; //jump over function code
                        label41: //start of function 'add3'
                        //Code for function 'add3':
                        //finding variable 'sum'
                        R[3] = 14; //load target lexical id
                        R[4] = R[2]; //load frame pointer to temp location
                        label42: //start of search loop
                        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                        R[6] = R[6] == R[3]; //compare target to current
                        if(R[6] == 1)
                        goto label43; //correct activation record found
                        R[4] = MM[R[4]]; //move back one activation record
                        goto label42; //check again
                        label43: //R[4] now points to correct activation record
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
                        //assigning to variable 'sum' from stack
                        //finding variable 'sum'
                        R[3] = 14; //load target lexical id
                        R[4] = R[2]; //load frame pointer to temp location
                        label44: //start of search loop
                        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                        R[6] = R[6] == R[3]; //compare target to current
                        if(R[6] == 1)
                        goto label45; //correct activation record found
                        R[4] = MM[R[4]]; //move back one activation record
                        goto label44; //check again
                        label45: //R[4] now points to correct activation record
                        R[4] = R[4] + 3; //set poiner to destination
                        R[7] = MM[R[0]]; //load source value from stack
                        MM[R[4]] = R[7]; //store value to destination
                        R[0] = R[0] - 1; //decrement stack pointer
                        //immediate value 0
                        R[0] = R[0] + 1; //increment stack pointer
                        MM[R[0]] = 0; //push value onto stack
                        //returning from function 'add3'
                        R[4] = R[2]; //move the current frame pointer out of the way
                        R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                        R[6] = MM[R[4] + 2]; //load return address from stack
                        R[0] = R[4] - 0; //set stack pointer to beginning of return destination
                        R[4] = R[4] + 3; //set pointer to beginning of return value
                        R[7] = MM[R[4]]; //load value from return source
                        MM[R[0]] = R[7]; //store value to return destination
                        goto *R[6]; //return to caller
                        //failsafe return
                        //immediate value 32767
                        R[0] = R[0] + 1; //increment stack pointer
                        MM[R[0]] = 32767; //push value onto stack
                        //returning from function 'add3'
                        R[4] = R[2]; //move the current frame pointer out of the way
                        R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                        R[6] = MM[R[4] + 2]; //load return address from stack
                        R[0] = R[4] - 0; //set stack pointer to beginning of return destination
                        R[4] = R[4] + 3; //set pointer to beginning of return value
                        R[7] = MM[R[4]]; //load value from return source
                        MM[R[0]] = R[7]; //store value to return destination
                        goto *R[6]; //return to caller
                    label40: //end of function 'add3'
                    //calling function 'add3'
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = R[2]; //save frame pointer
                    R[2] = R[0]; //frame pointer now points to this frame
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 17; //push lexical id onto stack
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = (int)&&label49; //push return address onto stack
                    R[0] = R[0] + 0; //allocate stack space for function variables
                    goto label41; //branch to function
                    label49: //function return address
                    //assigning to variable 'dum' from stack
                    //finding variable 'dum'
                    R[3] = 14; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label50: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label51; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label50; //check again
                    label51: //R[4] now points to correct activation record
                    R[4] = R[4] + 4; //set poiner to destination
                    R[7] = MM[R[0]]; //load source value from stack
                    MM[R[4]] = R[7]; //store value to destination
                    R[0] = R[0] - 1; //decrement stack pointer
                    //finding variable 'sum'
                    R[3] = 14; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label53: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label54; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label53; //check again
                    label54: //R[4] now points to correct activation record
                    R[6] = MM[R[4] + 3]; //load variable
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = R[6]; //push variable onto stack
                    //immediate value 20
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 20; //push value onto stack
                    //performing arithmetic operation(s)
                    R[6] = MM[R[0] - 1]; //load arithmetic term
                    R[7] = MM[R[0] - 0]; //load arithmetic term
                    R[6] = R[6] + R[7]; //perform arithmetic op
                    R[0] = R[0] - 1; //reduce stack by operations performed
                    MM[R[0]] = R[6]; //push arithmetic op result on stack
                    //assigning to variable 'sum' from stack
                    //finding variable 'sum'
                    R[3] = 14; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label55: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label56; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label55; //check again
                    label56: //R[4] now points to correct activation record
                    R[4] = R[4] + 3; //set poiner to destination
                    R[7] = MM[R[0]]; //load source value from stack
                    MM[R[4]] = R[7]; //store value to destination
                    R[0] = R[0] - 1; //decrement stack pointer
                    //immediate value 0
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 0; //push value onto stack
                    //returning from function 'add20'
                    R[4] = R[2]; //move the current frame pointer out of the way
                    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                    R[6] = MM[R[4] + 2]; //load return address from stack
                    R[0] = R[4] - 0; //set stack pointer to beginning of return destination
                    R[4] = R[4] + 3; //set pointer to beginning of return value
                    R[7] = MM[R[4]]; //load value from return source
                    MM[R[0]] = R[7]; //store value to return destination
                    goto *R[6]; //return to caller
                    //failsafe return
                    //immediate value 32767
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 32767; //push value onto stack
                    //returning from function 'add20'
                    R[4] = R[2]; //move the current frame pointer out of the way
                    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                    R[6] = MM[R[4] + 2]; //load return address from stack
                    R[0] = R[4] - 0; //set stack pointer to beginning of return destination
                    R[4] = R[4] + 3; //set pointer to beginning of return value
                    R[7] = MM[R[4]]; //load value from return source
                    MM[R[0]] = R[7]; //store value to return destination
                    goto *R[6]; //return to caller
                label38: //end of function 'add20'
                //finding variable 'sum'
                R[3] = 14; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label60: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label61; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label60; //check again
                label61: //R[4] now points to correct activation record
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
                //assigning to variable 'sum' from stack
                //finding variable 'sum'
                R[3] = 14; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label62: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label63; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label62; //check again
                label63: //R[4] now points to correct activation record
                R[4] = R[4] + 3; //set poiner to destination
                R[7] = MM[R[0]]; //load source value from stack
                MM[R[4]] = R[7]; //store value to destination
                R[0] = R[0] - 1; //decrement stack pointer
                //calling function 'add20'
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = R[2]; //save frame pointer
                R[2] = R[0]; //frame pointer now points to this frame
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 16; //push lexical id onto stack
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = (int)&&label65; //push return address onto stack
                R[0] = R[0] + 0; //allocate stack space for function variables
                goto label39; //branch to function
                label65: //function return address
                //assigning to variable 'dum' from stack
                //finding variable 'dum'
                R[3] = 14; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label66: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label67; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label66; //check again
                label67: //R[4] now points to correct activation record
                R[4] = R[4] + 4; //set poiner to destination
                R[7] = MM[R[0]]; //load source value from stack
                MM[R[4]] = R[7]; //store value to destination
                R[0] = R[0] - 1; //decrement stack pointer
                //immediate value 0
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 0; //push value onto stack
                //returning from function 'add100'
                R[4] = R[2]; //move the current frame pointer out of the way
                R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                R[6] = MM[R[4] + 2]; //load return address from stack
                R[0] = R[4] - 0; //set stack pointer to beginning of return destination
                R[4] = R[4] + 3; //set pointer to beginning of return value
                R[7] = MM[R[4]]; //load value from return source
                MM[R[0]] = R[7]; //store value to return destination
                goto *R[6]; //return to caller
                //failsafe return
                //immediate value 32767
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 32767; //push value onto stack
                //returning from function 'add100'
                R[4] = R[2]; //move the current frame pointer out of the way
                R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                R[6] = MM[R[4] + 2]; //load return address from stack
                R[0] = R[4] - 0; //set stack pointer to beginning of return destination
                R[4] = R[4] + 3; //set pointer to beginning of return value
                R[7] = MM[R[4]]; //load value from return source
                MM[R[0]] = R[7]; //store value to return destination
                goto *R[6]; //return to caller
            label36: //end of function 'add100'
            //immediate value 0
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 0; //push value onto stack
            //assigning to variable 'sum' from stack
            //finding variable 'sum'
            R[3] = 14; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label71: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label72; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label71; //check again
            label72: //R[4] now points to correct activation record
            R[4] = R[4] + 3; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //calling function 'add100'
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[2]; //save frame pointer
            R[2] = R[0]; //frame pointer now points to this frame
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 15; //push lexical id onto stack
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label74; //push return address onto stack
            R[0] = R[0] + 0; //allocate stack space for function variables
            goto label37; //branch to function
            label74: //function return address
            //assigning to variable 'dum' from stack
            //finding variable 'dum'
            R[3] = 14; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label75: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label76; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label75; //check again
            label76: //R[4] now points to correct activation record
            R[4] = R[4] + 4; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //finding variable 'sum'
            R[3] = 14; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label78: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label79; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label78; //check again
            label79: //R[4] now points to correct activation record
            R[6] = MM[R[4] + 3]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //returning from function 'get123nest'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 0; //set stack pointer to beginning of return destination
            R[4] = R[4] + 5; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'get123nest'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 0; //set stack pointer to beginning of return destination
            R[4] = R[4] + 5; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label34: //end of function 'get123nest'
        goto label82; //jump over function code
            label83: //start of function 'inc3nest'
            //Code for function 'inc3nest':
            goto label84; //jump over function code
                label85: //start of function 'incA'
                //Code for function 'incA':
                goto label86; //jump over function code
                    label87: //start of function 'incB'
                    //Code for function 'incB':
                    //finding variable 'par'
                    R[3] = 20; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label88: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label89; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label88; //check again
                    label89: //R[4] now points to correct activation record
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
                    R[3] = 20; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label90: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label91; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label90; //check again
                    label91: //R[4] now points to correct activation record
                    R[4] = R[4] - 1; //set poiner to destination
                    R[7] = MM[R[0]]; //load source value from stack
                    MM[R[4]] = R[7]; //store value to destination
                    R[0] = R[0] - 1; //decrement stack pointer
                    //finding variable 'par'
                    R[3] = 20; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label93: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label94; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label93; //check again
                    label94: //R[4] now points to correct activation record
                    R[6] = MM[R[4] - 1]; //load variable
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = R[6]; //push variable onto stack
                    //returning from function 'incB'
                    R[4] = R[2]; //move the current frame pointer out of the way
                    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                    R[6] = MM[R[4] + 2]; //load return address from stack
                    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                    R[4] = R[4] + 3; //set pointer to beginning of return value
                    R[7] = MM[R[4]]; //load value from return source
                    MM[R[0]] = R[7]; //store value to return destination
                    goto *R[6]; //return to caller
                    //failsafe return
                    //immediate value 32767
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 32767; //push value onto stack
                    //returning from function 'incB'
                    R[4] = R[2]; //move the current frame pointer out of the way
                    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                    R[6] = MM[R[4] + 2]; //load return address from stack
                    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                    R[4] = R[4] + 3; //set pointer to beginning of return value
                    R[7] = MM[R[4]]; //load value from return source
                    MM[R[0]] = R[7]; //store value to return destination
                    goto *R[6]; //return to caller
                label86: //end of function 'incB'
                //finding variable 'par'
                R[3] = 19; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label97: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label98; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label97; //check again
                label98: //R[4] now points to correct activation record
                R[6] = MM[R[4] - 1]; //load variable
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = R[6]; //push variable onto stack
                //assigning to variable 'var' from stack
                //finding variable 'var'
                R[3] = 19; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label99: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label100; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label99; //check again
                label100: //R[4] now points to correct activation record
                R[4] = R[4] + 3; //set poiner to destination
                R[7] = MM[R[0]]; //load source value from stack
                MM[R[4]] = R[7]; //store value to destination
                R[0] = R[0] - 1; //decrement stack pointer
                //finding variable 'var'
                R[3] = 19; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label102: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label103; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label102; //check again
                label103: //R[4] now points to correct activation record
                R[6] = MM[R[4] + 3]; //load variable
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = R[6]; //push variable onto stack
                //calling function 'incB'
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = R[2]; //save frame pointer
                R[2] = R[0]; //frame pointer now points to this frame
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 20; //push lexical id onto stack
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = (int)&&label104; //push return address onto stack
                R[0] = R[0] + 0; //allocate stack space for function variables
                goto label87; //branch to function
                label104: //function return address
                //assigning to variable 'var' from stack
                //finding variable 'var'
                R[3] = 19; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label105: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label106; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label105; //check again
                label106: //R[4] now points to correct activation record
                R[4] = R[4] + 3; //set poiner to destination
                R[7] = MM[R[0]]; //load source value from stack
                MM[R[4]] = R[7]; //store value to destination
                R[0] = R[0] - 1; //decrement stack pointer
                //finding variable 'var'
                R[3] = 19; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label108: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label109; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label108; //check again
                label109: //R[4] now points to correct activation record
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
                //assigning to variable 'par' from stack
                //finding variable 'par'
                R[3] = 19; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label110: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label111; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label110; //check again
                label111: //R[4] now points to correct activation record
                R[4] = R[4] - 1; //set poiner to destination
                R[7] = MM[R[0]]; //load source value from stack
                MM[R[4]] = R[7]; //store value to destination
                R[0] = R[0] - 1; //decrement stack pointer
                //finding variable 'par'
                R[3] = 19; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label113: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label114; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label113; //check again
                label114: //R[4] now points to correct activation record
                R[6] = MM[R[4] - 1]; //load variable
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = R[6]; //push variable onto stack
                //returning from function 'incA'
                R[4] = R[2]; //move the current frame pointer out of the way
                R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                R[6] = MM[R[4] + 2]; //load return address from stack
                R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                R[4] = R[4] + 4; //set pointer to beginning of return value
                R[7] = MM[R[4]]; //load value from return source
                MM[R[0]] = R[7]; //store value to return destination
                goto *R[6]; //return to caller
                //failsafe return
                //immediate value 32767
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 32767; //push value onto stack
                //returning from function 'incA'
                R[4] = R[2]; //move the current frame pointer out of the way
                R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                R[6] = MM[R[4] + 2]; //load return address from stack
                R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                R[4] = R[4] + 4; //set pointer to beginning of return value
                R[7] = MM[R[4]]; //load value from return source
                MM[R[0]] = R[7]; //store value to return destination
                goto *R[6]; //return to caller
            label84: //end of function 'incA'
            //finding variable 'par'
            R[3] = 18; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label117: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label118; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label117; //check again
            label118: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //calling function 'incA'
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[2]; //save frame pointer
            R[2] = R[0]; //frame pointer now points to this frame
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 19; //push lexical id onto stack
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label119; //push return address onto stack
            R[0] = R[0] + 1; //allocate stack space for function variables
            goto label85; //branch to function
            label119: //function return address
            //assigning to variable 'par' from stack
            //finding variable 'par'
            R[3] = 18; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label120: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label121; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label120; //check again
            label121: //R[4] now points to correct activation record
            R[4] = R[4] - 1; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //finding variable 'par'
            R[3] = 18; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label123: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label124; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label123; //check again
            label124: //R[4] now points to correct activation record
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
            R[3] = 18; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label125: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label126; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label125; //check again
            label126: //R[4] now points to correct activation record
            R[4] = R[4] - 1; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //finding variable 'par'
            R[3] = 18; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label128: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label129; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label128; //check again
            label129: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //returning from function 'inc3nest'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'inc3nest'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label82: //end of function 'inc3nest'
        goto label132; //jump over function code
            label133: //start of function 'getValue'
            //Code for function 'getValue':
            //finding variable 'index'
            R[3] = 21; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label134: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label135; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label134; //check again
            label135: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //finding variable 'inArray'
            R[3] = 21; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label136: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label137; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label136; //check again
            label137: //R[4] now points to correct activation record
            R[6] = MM[R[0]]; //load array index from stack
            R[0] = R[0] - 1; //decrement stack pointer
            R[4] = R[4] + R[6]; //add index to frame pointer
            R[6] = MM[R[4] - 11]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //returning from function 'getValue'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 11; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'getValue'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 11; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label132: //end of function 'getValue'
        goto label140; //jump over function code
            label141: //start of function 'overwrite'
            //Code for function 'overwrite':
            //immediate value 0
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 0; //push value onto stack
            //immediate value 123
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 123; //push value onto stack
            //assigning into array 'inArray' from stack
            //finding variable 'inArray'
            R[3] = 22; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label142: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label143; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label142; //check again
            label143: //R[4] now points to correct activation record
            R[4] = R[4] - 10; //add variable offset tp frame pointer
            R[6] = MM[R[0] - 1]; //get index from stack
            R[4] = R[4] + R[6]; //index into array
            R[7] = MM[R[0]]; //get source from stack
            MM[R[4]] = R[7]; //assign source to destination
            R[0] = R[0] - 2; //adjust stack for used parameters
            //immediate value 0
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 0; //push value onto stack
            //returning from function 'overwrite'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 10; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'overwrite'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 10; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label140: //end of function 'overwrite'
        goto label146; //jump over function code
            label147: //start of function 'recCount'
            //Code for function 'recCount':
            //if statement
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label148; //push if end address onto stack
            //finding variable 'i'
            R[3] = 23; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label149: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label150; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label149; //check again
            label150: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
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
            goto label152; //skip over if code block
            label151: //if-then
            //immediate value 1
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 1; //push value onto stack
            //finding variable 'i'
            R[3] = 23; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label153: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label154; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label153; //check again
            label154: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
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
            //calling function 'recCount'
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[2]; //save frame pointer
            R[2] = R[0]; //frame pointer now points to this frame
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 23; //push lexical id onto stack
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label155; //push return address onto stack
            R[0] = R[0] + 0; //allocate stack space for function variables
            goto label147; //branch to function
            label155: //function return address
            //performing arithmetic operation(s)
            R[6] = MM[R[0] - 1]; //load arithmetic term
            R[7] = MM[R[0] - 0]; //load arithmetic term
            R[6] = R[6] + R[7]; //perform arithmetic op
            R[0] = R[0] - 1; //reduce stack by operations performed
            MM[R[0]] = R[6]; //push arithmetic op result on stack
            //returning from function 'recCount'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 4; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            R[6] = MM[R[0]]; //load end address from stack
            R[0] = R[0] - 1; //decrement stack pointer
            goto *R[6]; //branch to end of if statement
            label152: //end of if code block
            goto label158; //skip over if code block
            label157: //if-else
            //immediate value 0
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 0; //push value onto stack
            //returning from function 'recCount'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 4; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            R[6] = MM[R[0]]; //load end address from stack
            R[0] = R[0] - 1; //decrement stack pointer
            goto *R[6]; //branch to end of if statement
            label158: //end of if code block
            R[6] = MM[R[0]]; //load branch decision value
            R[0] = R[0] - 1; //decrement stack pointer
            if(R[6] == 1)
            goto label151; //branch to then
            goto label157; //branch to else
            label148: //end of if statement
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'recCount'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label146: //end of function 'recCount'
        goto label161; //jump over function code
            label162: //start of function 'sillyFib'
            //Code for function 'sillyFib':
            //case statement
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label163; //push case end address onto stack
            //finding variable 'i'
            R[3] = 24; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label164: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label165; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label164; //check again
            label165: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            goto label167; //skip over case when code block
            label166: //when
            //immediate value 1
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 1; //push value onto stack
            //returning from function 'sillyFib'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 4; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            R[6] = MM[R[0]]; //load end address from stack
            R[0] = R[0] - 1; //decrement stack pointer
            goto *R[6]; //branch to end of case statement
            label167: //end of when code block
            goto label170; //skip over case when code block
            label169: //when
            //immediate value 1
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 1; //push value onto stack
            //returning from function 'sillyFib'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 4; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            R[6] = MM[R[0]]; //load end address from stack
            R[0] = R[0] - 1; //decrement stack pointer
            goto *R[6]; //branch to end of case statement
            label170: //end of when code block
            goto label173; //skip over case default code block
            label172: //default
            //finding variable 'i'
            R[3] = 24; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label174: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label175; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label174; //check again
            label175: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
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
            //calling function 'sillyFib'
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[2]; //save frame pointer
            R[2] = R[0]; //frame pointer now points to this frame
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 24; //push lexical id onto stack
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label176; //push return address onto stack
            R[0] = R[0] + 0; //allocate stack space for function variables
            goto label162; //branch to function
            label176: //function return address
            //finding variable 'i'
            R[3] = 24; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label177: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label178; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label177; //check again
            label178: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //immediate value 2
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 2; //push value onto stack
            //performing arithmetic operation(s)
            R[6] = MM[R[0] - 1]; //load arithmetic term
            R[7] = MM[R[0] - 0]; //load arithmetic term
            R[6] = R[6] - R[7]; //perform arithmetic op
            R[0] = R[0] - 1; //reduce stack by operations performed
            MM[R[0]] = R[6]; //push arithmetic op result on stack
            //calling function 'sillyFib'
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[2]; //save frame pointer
            R[2] = R[0]; //frame pointer now points to this frame
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 24; //push lexical id onto stack
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label179; //push return address onto stack
            R[0] = R[0] + 0; //allocate stack space for function variables
            goto label162; //branch to function
            label179: //function return address
            //performing arithmetic operation(s)
            R[6] = MM[R[0] - 1]; //load arithmetic term
            R[7] = MM[R[0] - 0]; //load arithmetic term
            R[6] = R[6] + R[7]; //perform arithmetic op
            R[0] = R[0] - 1; //reduce stack by operations performed
            MM[R[0]] = R[6]; //push arithmetic op result on stack
            //returning from function 'sillyFib'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 4; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            R[6] = MM[R[0]]; //load end address from stack
            R[0] = R[0] - 1; //decrement stack pointer
            goto *R[6]; //branch to end of case statement
            label173: //end of when code block
            R[6] = MM[R[0]]; //load case decision value
            R[0] = R[0] - 1; //decrement stack pointer
            R[7] = 1; //load 1 for comparison
            R[7] = R[6] - R[7]; //compare values
            if(R[7] == 0)
            goto label166; //branch to 'when 1' code block
            R[7] = 2; //load 2 for comparison
            R[7] = R[6] - R[7]; //compare values
            if(R[7] == 0)
            goto label169; //branch to 'when 2' code block
            goto label172; //branch to default code block
            R[0] = R[0] - 1; //decrement stack pointer
            goto label163; //failsafe branch to end of case statement
            label163: //end of case statement
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'sillyFib'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 3; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label161: //end of function 'sillyFib'
        goto label182; //jump over function code
            label183: //start of function 'callCount'
            //Code for function 'callCount':
            goto label184; //jump over function code
                label185: //start of function 'recCountNest'
                //Code for function 'recCountNest':
                goto label186; //jump over function code
                    label187: //start of function 'recInc'
                    //Code for function 'recInc':
                    //finding variable 'count'
                    R[3] = 25; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label188: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label189; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label188; //check again
                    label189: //R[4] now points to correct activation record
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
                    //assigning to variable 'count' from stack
                    //finding variable 'count'
                    R[3] = 25; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label190: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label191; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label190; //check again
                    label191: //R[4] now points to correct activation record
                    R[4] = R[4] + 3; //set poiner to destination
                    R[7] = MM[R[0]]; //load source value from stack
                    MM[R[4]] = R[7]; //store value to destination
                    R[0] = R[0] - 1; //decrement stack pointer
                    //if statement
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = (int)&&label193; //push if end address onto stack
                    //finding variable 'j'
                    R[3] = 27; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label194: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label195; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label194; //check again
                    label195: //R[4] now points to correct activation record
                    R[6] = MM[R[4] - 1]; //load variable
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
                    goto label197; //skip over if code block
                    label196: //if-then
                    //finding variable 'j'
                    R[3] = 27; //load target lexical id
                    R[4] = R[2]; //load frame pointer to temp location
                    label198: //start of search loop
                    R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                    R[6] = R[6] == R[3]; //compare target to current
                    if(R[6] == 1)
                    goto label199; //correct activation record found
                    R[4] = MM[R[4]]; //move back one activation record
                    goto label198; //check again
                    label199: //R[4] now points to correct activation record
                    R[6] = MM[R[4] - 1]; //load variable
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
                    //calling function 'recInc'
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = R[2]; //save frame pointer
                    R[2] = R[0]; //frame pointer now points to this frame
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 27; //push lexical id onto stack
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = (int)&&label200; //push return address onto stack
                    R[0] = R[0] + 0; //allocate stack space for function variables
                    goto label187; //branch to function
                    label200: //function return address
                    //immediate value 1
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 1; //push value onto stack
                    //performing arithmetic operation(s)
                    R[6] = MM[R[0] - 1]; //load arithmetic term
                    R[7] = MM[R[0] - 0]; //load arithmetic term
                    R[6] = R[6] + R[7]; //perform arithmetic op
                    R[0] = R[0] - 1; //reduce stack by operations performed
                    MM[R[0]] = R[6]; //push arithmetic op result on stack
                    //returning from function 'recInc'
                    R[4] = R[2]; //move the current frame pointer out of the way
                    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                    R[6] = MM[R[4] + 2]; //load return address from stack
                    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                    R[4] = R[4] + 4; //set pointer to beginning of return value
                    R[7] = MM[R[4]]; //load value from return source
                    MM[R[0]] = R[7]; //store value to return destination
                    goto *R[6]; //return to caller
                    R[6] = MM[R[0]]; //load end address from stack
                    R[0] = R[0] - 1; //decrement stack pointer
                    goto *R[6]; //branch to end of if statement
                    label197: //end of if code block
                    goto label203; //skip over if code block
                    label202: //if-else
                    //immediate value 1
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 1; //push value onto stack
                    //returning from function 'recInc'
                    R[4] = R[2]; //move the current frame pointer out of the way
                    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                    R[6] = MM[R[4] + 2]; //load return address from stack
                    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                    R[4] = R[4] + 4; //set pointer to beginning of return value
                    R[7] = MM[R[4]]; //load value from return source
                    MM[R[0]] = R[7]; //store value to return destination
                    goto *R[6]; //return to caller
                    R[6] = MM[R[0]]; //load end address from stack
                    R[0] = R[0] - 1; //decrement stack pointer
                    goto *R[6]; //branch to end of if statement
                    label203: //end of if code block
                    R[6] = MM[R[0]]; //load branch decision value
                    R[0] = R[0] - 1; //decrement stack pointer
                    if(R[6] == 1)
                    goto label196; //branch to then
                    goto label202; //branch to else
                    label193: //end of if statement
                    //failsafe return
                    //immediate value 32767
                    R[0] = R[0] + 1; //increment stack pointer
                    MM[R[0]] = 32767; //push value onto stack
                    //returning from function 'recInc'
                    R[4] = R[2]; //move the current frame pointer out of the way
                    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                    R[6] = MM[R[4] + 2]; //load return address from stack
                    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                    R[4] = R[4] + 3; //set pointer to beginning of return value
                    R[7] = MM[R[4]]; //load value from return source
                    MM[R[0]] = R[7]; //store value to return destination
                    goto *R[6]; //return to caller
                label186: //end of function 'recInc'
                //if statement
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = (int)&&label206; //push if end address onto stack
                //finding variable 'i'
                R[3] = 26; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label207: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label208; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label207; //check again
                label208: //R[4] now points to correct activation record
                R[6] = MM[R[4] - 1]; //load variable
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
                goto label210; //skip over if code block
                label209: //if-then
                //finding variable 'i'
                R[3] = 26; //load target lexical id
                R[4] = R[2]; //load frame pointer to temp location
                label211: //start of search loop
                R[6] = MM[R[4] + 1]; //load lexical id of current activation record
                R[6] = R[6] == R[3]; //compare target to current
                if(R[6] == 1)
                goto label212; //correct activation record found
                R[4] = MM[R[4]]; //move back one activation record
                goto label211; //check again
                label212: //R[4] now points to correct activation record
                R[6] = MM[R[4] - 1]; //load variable
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
                //calling function 'recCountNest'
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = R[2]; //save frame pointer
                R[2] = R[0]; //frame pointer now points to this frame
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 26; //push lexical id onto stack
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = (int)&&label213; //push return address onto stack
                R[0] = R[0] + 0; //allocate stack space for function variables
                goto label185; //branch to function
                label213: //function return address
                //calling function 'recInc'
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = R[2]; //save frame pointer
                R[2] = R[0]; //frame pointer now points to this frame
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 27; //push lexical id onto stack
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = (int)&&label214; //push return address onto stack
                R[0] = R[0] + 0; //allocate stack space for function variables
                goto label187; //branch to function
                label214: //function return address
                //returning from function 'recCountNest'
                R[4] = R[2]; //move the current frame pointer out of the way
                R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                R[6] = MM[R[4] + 2]; //load return address from stack
                R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                R[4] = R[4] + 4; //set pointer to beginning of return value
                R[7] = MM[R[4]]; //load value from return source
                MM[R[0]] = R[7]; //store value to return destination
                goto *R[6]; //return to caller
                R[6] = MM[R[0]]; //load end address from stack
                R[0] = R[0] - 1; //decrement stack pointer
                goto *R[6]; //branch to end of if statement
                label210: //end of if code block
                goto label217; //skip over if code block
                label216: //if-else
                //immediate value 0
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 0; //push value onto stack
                //returning from function 'recCountNest'
                R[4] = R[2]; //move the current frame pointer out of the way
                R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                R[6] = MM[R[4] + 2]; //load return address from stack
                R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                R[4] = R[4] + 4; //set pointer to beginning of return value
                R[7] = MM[R[4]]; //load value from return source
                MM[R[0]] = R[7]; //store value to return destination
                goto *R[6]; //return to caller
                R[6] = MM[R[0]]; //load end address from stack
                R[0] = R[0] - 1; //decrement stack pointer
                goto *R[6]; //branch to end of if statement
                label217: //end of if code block
                R[6] = MM[R[0]]; //load branch decision value
                R[0] = R[0] - 1; //decrement stack pointer
                if(R[6] == 1)
                goto label209; //branch to then
                goto label216; //branch to else
                label206: //end of if statement
                //failsafe return
                //immediate value 32767
                R[0] = R[0] + 1; //increment stack pointer
                MM[R[0]] = 32767; //push value onto stack
                //returning from function 'recCountNest'
                R[4] = R[2]; //move the current frame pointer out of the way
                R[2] = MM[R[4]]; //restore frame pointer from previous activation record
                R[6] = MM[R[4] + 2]; //load return address from stack
                R[0] = R[4] - 1; //set stack pointer to beginning of return destination
                R[4] = R[4] + 3; //set pointer to beginning of return value
                R[7] = MM[R[4]]; //load value from return source
                MM[R[0]] = R[7]; //store value to return destination
                goto *R[6]; //return to caller
            label184: //end of function 'recCountNest'
            //immediate value 0
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 0; //push value onto stack
            //assigning to variable 'count' from stack
            //finding variable 'count'
            R[3] = 25; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label220: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label221; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label220; //check again
            label221: //R[4] now points to correct activation record
            R[4] = R[4] + 3; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //finding variable 'x'
            R[3] = 25; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label223: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label224; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label223; //check again
            label224: //R[4] now points to correct activation record
            R[6] = MM[R[4] - 1]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //calling function 'recCountNest'
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[2]; //save frame pointer
            R[2] = R[0]; //frame pointer now points to this frame
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 26; //push lexical id onto stack
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = (int)&&label225; //push return address onto stack
            R[0] = R[0] + 0; //allocate stack space for function variables
            goto label185; //branch to function
            label225: //function return address
            //assigning to variable 'x' from stack
            //finding variable 'x'
            R[3] = 25; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label226: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label227; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label226; //check again
            label227: //R[4] now points to correct activation record
            R[4] = R[4] - 1; //set poiner to destination
            R[7] = MM[R[0]]; //load source value from stack
            MM[R[4]] = R[7]; //store value to destination
            R[0] = R[0] - 1; //decrement stack pointer
            //finding variable 'count'
            R[3] = 25; //load target lexical id
            R[4] = R[2]; //load frame pointer to temp location
            label229: //start of search loop
            R[6] = MM[R[4] + 1]; //load lexical id of current activation record
            R[6] = R[6] == R[3]; //compare target to current
            if(R[6] == 1)
            goto label230; //correct activation record found
            R[4] = MM[R[4]]; //move back one activation record
            goto label229; //check again
            label230: //R[4] now points to correct activation record
            R[6] = MM[R[4] + 3]; //load variable
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = R[6]; //push variable onto stack
            //returning from function 'callCount'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 4; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
            //failsafe return
            //immediate value 32767
            R[0] = R[0] + 1; //increment stack pointer
            MM[R[0]] = 32767; //push value onto stack
            //returning from function 'callCount'
            R[4] = R[2]; //move the current frame pointer out of the way
            R[2] = MM[R[4]]; //restore frame pointer from previous activation record
            R[6] = MM[R[4] + 2]; //load return address from stack
            R[0] = R[4] - 1; //set stack pointer to beginning of return destination
            R[4] = R[4] + 4; //set pointer to beginning of return value
            R[7] = MM[R[4]]; //load value from return source
            MM[R[0]] = R[7]; //store value to return destination
            goto *R[6]; //return to caller
        label182: //end of function 'callCount'
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
        label233: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label234; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label233; //check again
        label234: //R[4] now points to correct activation record
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
        label236: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label237; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label236; //check again
        label237: //R[4] now points to correct activation record
        R[4] = R[4] + 6; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__function calls__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 115; //s
        MM[R[5] - 5] = 108; //l
        MM[R[5] - 6] = 108; //l
        MM[R[5] - 7] = 97; //a
        MM[R[5] - 8] = 99; //c
        MM[R[5] - 9] = 32; // 
        MM[R[5] - 10] = 110; //n
        MM[R[5] - 11] = 111; //o
        MM[R[5] - 12] = 105; //i
        MM[R[5] - 13] = 116; //t
        MM[R[5] - 14] = 99; //c
        MM[R[5] - 15] = 110; //n
        MM[R[5] - 16] = 117; //u
        MM[R[5] - 17] = 102; //f
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
        MM[R[0]] = (int)&&label239; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label239: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'get3'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label243; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label3; //branch to function
        label243: //function return address
        //immediate value 3
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 3; //push value onto stack
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
        MM[R[0]] = (int)&&label244; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label244: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label245: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label246; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label245; //check again
        label246: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 9
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 9; //push value onto stack
        //calling function 'increment'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 11; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label248; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label7; //branch to function
        label248: //function return address
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
        MM[R[0]] = (int)&&label249; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label249: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label250: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label251; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label250; //check again
        label251: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //immediate value 100
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 100; //push value onto stack
        //calling function 'add'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label253; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label18; //branch to function
        label253: //function return address
        //immediate value 110
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 110; //push value onto stack
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
        MM[R[0]] = (int)&&label254; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label254: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label255: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label256; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label255; //check again
        label256: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 11
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 11; //push value onto stack
        //assigning to variable 'var' from stack
        //finding variable 'var'
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
        R[4] = R[4] + 3; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //calling function 'incrementVar'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 13; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label261; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label26; //branch to function
        label261: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label262: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label263; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label262; //check again
        label263: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //finding variable 'var'
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
        R[6] = MM[R[4] + 3]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 12
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push value onto stack
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
        MM[R[0]] = (int)&&label267; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label267: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 123
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 123; //push value onto stack
        //calling function 'get123nest'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 14; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label271; //push return address onto stack
        R[0] = R[0] + 2; //allocate stack space for function variables
        goto label35; //branch to function
        label271: //function return address
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
        MM[R[0]] = (int)&&label272; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label272: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label273: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label274; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label273; //check again
        label274: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //calling function 'inc3nest'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 18; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label276; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label83; //branch to function
        label276: //function return address
        //immediate value 13
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 13; //push value onto stack
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
        MM[R[0]] = (int)&&label277; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label277: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label278: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label279; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label278; //check again
        label279: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 6
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 6; //push value onto stack
        //immediate value 88
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 88; //push value onto stack
        //assigning into array 'array' from stack
        //finding variable 'array'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label281: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label282; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label281; //check again
        label282: //R[4] now points to correct activation record
        R[4] = R[4] + 9; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //finding variable 'array'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label283: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label284; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label283; //check again
        label284: //R[4] now points to correct activation record
        R[7] = 10; //load array size
        R[8] = 0; //initialize array counter
        label285: //start of array copy loop
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        R[4] = R[4] + 1; //increment location
        R[8] = R[8] + 1; //increment count
        R[6] = R[8] == R[7]; //check for completeion
        if(R[6] == 0)
        goto label285; //copy next array value, or fall through
        //immediate value 6
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 6; //push value onto stack
        //calling function 'getValue'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 21; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label286; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label133; //branch to function
        label286: //function return address
        //immediate value 88
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 88; //push value onto stack
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
        MM[R[0]] = (int)&&label287; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label287: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label288: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label289; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label288; //check again
        label289: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //immediate value 56
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 56; //push value onto stack
        //assigning into array 'array' from stack
        //finding variable 'array'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label291: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label292; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label291; //check again
        label292: //R[4] now points to correct activation record
        R[4] = R[4] + 9; //add variable offset tp frame pointer
        R[6] = MM[R[0] - 1]; //get index from stack
        R[4] = R[4] + R[6]; //index into array
        R[7] = MM[R[0]]; //get source from stack
        MM[R[4]] = R[7]; //assign source to destination
        R[0] = R[0] - 2; //adjust stack for used parameters
        //finding variable 'array'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label293: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label294; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label293; //check again
        label294: //R[4] now points to correct activation record
        R[7] = 10; //load array size
        R[8] = 0; //initialize array counter
        label295: //start of array copy loop
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        R[4] = R[4] + 1; //increment location
        R[8] = R[8] + 1; //increment count
        R[6] = R[8] == R[7]; //check for completeion
        if(R[6] == 0)
        goto label295; //copy next array value, or fall through
        //calling function 'overwrite'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 22; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label296; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label141; //branch to function
        label296: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label297: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label298; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label297; //check again
        label298: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 0
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 0; //push value onto stack
        //finding variable 'array'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label300: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label301; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label300; //check again
        label301: //R[4] now points to correct activation record
        R[6] = MM[R[0]]; //load array index from stack
        R[0] = R[0] - 1; //decrement stack pointer
        R[4] = R[4] + R[6]; //add index to frame pointer
        R[6] = MM[R[4] + 9]; //load variable
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[6]; //push variable onto stack
        //immediate value 56
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 56; //push value onto stack
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
        MM[R[0]] = (int)&&label302; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label302: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
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
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //allocating string '__recursion__'
        MM[R[5] - 1] = 0; //'\0'
        MM[R[5] - 2] = 95; //_
        MM[R[5] - 3] = 95; //_
        MM[R[5] - 4] = 110; //n
        MM[R[5] - 5] = 111; //o
        MM[R[5] - 6] = 105; //i
        MM[R[5] - 7] = 115; //s
        MM[R[5] - 8] = 114; //r
        MM[R[5] - 9] = 117; //u
        MM[R[5] - 10] = 99; //c
        MM[R[5] - 11] = 101; //e
        MM[R[5] - 12] = 114; //r
        MM[R[5] - 13] = 95; //_
        MM[R[5] - 14] = 95; //_
        R[5] = R[5] - 14; //adjust string pointer
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[5]; //push string pointer onto stack
        //calling function 'putString'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 5; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label306; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run5; //branch to function
        label306: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label307: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label308; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label307; //check again
        label308: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
        //calling function 'recCount'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 23; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label310; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label147; //branch to function
        label310: //function return address
        //immediate value 8
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 8; //push value onto stack
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
        MM[R[0]] = (int)&&label311; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label311: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label312: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label313; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label312; //check again
        label313: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 12
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 12; //push value onto stack
        //calling function 'sillyFib'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 24; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label315; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto label162; //branch to function
        label315: //function return address
        //immediate value 144
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 144; //push value onto stack
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
        MM[R[0]] = (int)&&label316; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label316: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label317: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label318; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label317; //check again
        label318: //R[4] now points to correct activation record
        R[4] = R[4] + 8; //set poiner to destination
        R[7] = MM[R[0]]; //load source value from stack
        MM[R[4]] = R[7]; //store value to destination
        R[0] = R[0] - 1; //decrement stack pointer
        //immediate value 10
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 10; //push value onto stack
        //calling function 'callCount'
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = R[2]; //save frame pointer
        R[2] = R[0]; //frame pointer now points to this frame
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = 25; //push lexical id onto stack
        R[0] = R[0] + 1; //increment stack pointer
        MM[R[0]] = (int)&&label320; //push return address onto stack
        R[0] = R[0] + 1; //allocate stack space for function variables
        goto label183; //branch to function
        label320: //function return address
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
        MM[R[0]] = (int)&&label321; //push return address onto stack
        R[0] = R[0] + 0; //allocate stack space for function variables
        goto run3; //branch to function
        label321: //function return address
        //assigning to variable 'tmp' from stack
        //finding variable 'tmp'
        R[3] = 9; //load target lexical id
        R[4] = R[2]; //load frame pointer to temp location
        label322: //start of search loop
        R[6] = MM[R[4] + 1]; //load lexical id of current activation record
        R[6] = R[6] == R[3]; //compare target to current
        if(R[6] == 1)
        goto label323; //correct activation record found
        R[4] = MM[R[4]]; //move back one activation record
        goto label322; //check again
        label323: //R[4] now points to correct activation record
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
        R[4] = R[4] + 19; //set pointer to beginning of return value
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
        R[4] = R[4] + 19; //set pointer to beginning of return value
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
    MM[R[0]] = (int)&&label327; //push return address onto stack
    R[0] = R[0] + 16; //allocate stack space for function variables
    goto label1; //branch to function
    label327: //function return address
    return 0; //exit status
}
