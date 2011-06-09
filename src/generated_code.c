#include "code_defs.h"
#include "std_defs.h"
#include "runtime.h"
#include <stdio.h>
int main(){
int i;
goto L1;
L0: R[1] = R[1] + 1; //allocate space for arg par
R[1] = R[1] + 1; //allocate space for varvar
R[1] = R[1] + 1; //allocate space for varbar
R[1] = R[1] + 1; //allocate space for vartrue
R[1] = R[1] + 1; //allocate space for varfalse
R[1] = R[1] + 1; //allocate space for varsar
R[1] = R[1] + 1; //allocate space for vartmp
R[1] = R[1] + 10; // allocate space for array array1
R[1] = R[1] + 10; // allocate space for array array2
R[3] = 1;//factor
R[4] = 1;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 5] = R[3]; //assignment_statement
R[3] = 1;//factor
R[4] = 1;//factor
R[3] = R[3] != R[4]; //relation 
MM[R[0] + 6] = R[3]; //assignment_statement
MM[9999] = '_';
MM[9998] = '_';
MM[9997] = 'a';
MM[9996] = 's';
MM[9995] = 's';
MM[9994] = 'i';
MM[9993] = 'g';
MM[9992] = 'n';
MM[9991] = 'm';
MM[9990] = 'e';
MM[9989] = 'n';
MM[9988] = 't';
MM[9987] = ' ';
MM[9986] = 's';
MM[9985] = 't';
MM[9984] = 'a';
MM[9983] = 't';
MM[9982] = 'e';
MM[9981] = 'm';
MM[9980] = 'e';
MM[9979] = 'n';
MM[9978] = 't';
MM[9977] = '_';
MM[9976] = '_';
MM[9975] = '\0';
R[4] = 9999; // string factor "__assignment statement__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L2;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L2: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 30];//factor putString
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 10;//factor
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor var
R[5] = 10;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L3;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L3: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 31];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 22;//factor
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = MM[R[0] + 8];//factor tmp
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor var
R[5] = 22;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L4;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L4: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 32];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 74;//factor
MM[R[0] + 2] = R[3]; //assignment_statement
R[3] = MM[R[0] + 2];//factor par
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor var
R[5] = 74;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L5;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L5: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 33];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = MM[R[0] + 5];//factor true
MM[R[0] + 4] = R[3]; //assignment_statement
R[4] = MM[R[0] + 5];//factor true
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L6;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L6: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 34];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
MM[9974] = '_';
MM[9973] = '_';
MM[9972] = 'i';
MM[9971] = 'f';
MM[9970] = ' ';
MM[9969] = 's';
MM[9968] = 't';
MM[9967] = 'a';
MM[9966] = 't';
MM[9965] = 'e';
MM[9964] = 'm';
MM[9963] = 'e';
MM[9962] = 'n';
MM[9961] = 't';
MM[9960] = '_';
MM[9959] = '_';
MM[9958] = '\0';
R[3] = 9974; // string factor "__if statement__"
MM[R[0] + 7] = R[3]; //assignment_statement
R[4] = MM[R[0] + 7];//factor sar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L7;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L7: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 35];//factor putString
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = MM[R[0] + 6];//factor false
MM[R[0] + 4] = R[3]; //assignment_statement
R[2] = 1;//factor
R[3] = 1;//factor
R[2] = R[2] == R[3]; //relation 
R[2] = !R[2]; //if
if(R[2]) goto L8; //if
R[4] = MM[R[0] + 5];//factor true
MM[R[0] + 4] = R[4]; //assignment_statement
goto L9; //if
L8: L9: R[4] = MM[R[0] + 4];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L10;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L10: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 36];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
R[2] = MM[R[0] + 5];//factor true
R[2] = !R[2]; //if
if(R[2]) goto L11; //if
R[5] = MM[R[0] + 5];//factor true
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L13;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[5]; //passing argument 
goto PUTBOOL;
L13: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 37];//factor putBool
MM[R[0] + 8] = R[4]; //assignment_statement
goto L12; //if
L11: R[2] = !R[2]; //if
if(R[2]) goto L12; //if
R[5] = MM[R[0] + 6];//factor false
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L14;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[5]; //passing argument 
goto PUTBOOL;
L14: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 38];//factor putBool
MM[R[0] + 8] = R[4]; //assignment_statement
L12: R[2] = MM[R[0] + 5];//factor true
R[2] = !R[2];//expression
R[2] = !R[2]; //if
if(R[2]) goto L15; //if
R[5] = MM[R[0] + 6];//factor false
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L17;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[5]; //passing argument 
goto PUTBOOL;
L17: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 39];//factor putBool
MM[R[0] + 8] = R[4]; //assignment_statement
goto L16; //if
L15: R[2] = !R[2]; //if
if(R[2]) goto L16; //if
R[5] = MM[R[0] + 5];//factor true
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L18;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[5]; //passing argument 
goto PUTBOOL;
L18: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 40];//factor putBool
MM[R[0] + 8] = R[4]; //assignment_statement
L16: R[3] = 0;//factor
MM[R[0] + 3] = R[3]; //assignment_statement
R[2] = 6;//factor
R[3] = 22;//factor
R[2] = R[2] > R[3]; //relation 
R[2] = !R[2]; //if
if(R[2]) goto L19; //if
R[4] = MM[R[0] + 3];//factor var
R[5] = 2;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
R[4] = MM[R[0] + 3];//factor var
R[5] = 3;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
R[4] = MM[R[0] + 3];//factor var
R[5] = 4;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
goto L20; //if
L19: R[2] = !R[2]; //if
if(R[2]) goto L20; //if
R[4] = MM[R[0] + 3];//factor var
R[5] = 10;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
R[4] = MM[R[0] + 3];//factor var
R[5] = 100;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
R[4] = MM[R[0] + 3];//factor var
R[5] = 1000;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
L20: R[4] = MM[R[0] + 3];//factor var
R[5] = 1110;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L21;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L21: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 41];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 0;//factor
MM[R[0] + 3] = R[3]; //assignment_statement
R[2] = MM[R[0] + 5];//factor true
R[2] = !R[2]; //if
if(R[2]) goto L22; //if
R[3] = MM[R[0] + 6];//factor false
R[3] = !R[3]; //if
if(R[3]) goto L24; //if
R[5] = MM[R[0] + 3];//factor var
R[6] = 1;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 3] = R[5]; //assignment_statement
goto L25; //if
L24: R[3] = !R[3]; //if
if(R[3]) goto L25; //if
R[4] = MM[R[0] + 5];//factor true
R[4] = !R[4]; //if
if(R[4]) goto L26; //if
R[5] = MM[R[0] + 5];//factor true
R[5] = !R[5]; //if
if(R[5]) goto L28; //if
R[7] = MM[R[0] + 3];//factor var
R[8] = 10;//factor
R[7] = R[7] + R[8]; //arithop 2
MM[R[0] + 3] = R[7]; //assignment_statement
goto L29; //if
L28: R[5] = !R[5]; //if
if(R[5]) goto L29; //if
R[7] = MM[R[0] + 3];//factor var
R[8] = 100;//factor
R[7] = R[7] + R[8]; //arithop 2
MM[R[0] + 3] = R[7]; //assignment_statement
L29: goto L27; //if
L26: L27: L25: goto L23; //if
L22: L23: R[4] = MM[R[0] + 3];//factor var
R[5] = 10;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L30;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L30: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 42];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
MM[9957] = '_';
MM[9956] = '_';
MM[9955] = 'w';
MM[9954] = 'h';
MM[9953] = 'i';
MM[9952] = 'l';
MM[9951] = 'e';
MM[9950] = ' ';
MM[9949] = 's';
MM[9948] = 't';
MM[9947] = 'a';
MM[9946] = 't';
MM[9945] = 'e';
MM[9944] = 'm';
MM[9943] = 'e';
MM[9942] = 'n';
MM[9941] = 't';
MM[9940] = '_';
MM[9939] = '_';
MM[9938] = '\0';
R[4] = 9957; // string factor "__while statement__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L31;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L31: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 43];//factor putString
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 10;//factor
MM[R[0] + 3] = R[3]; //assignment_statement
L32: R[2] = MM[R[0] + 3];//factor var
R[3] = 0;//factor
R[2] = R[2] > R[3]; //relation 
R[2] = !R[2]; //while
if(R[2]) goto L33; //while
R[4] = MM[R[0] + 3];//factor var
R[5] = 1;//factor
R[4] = R[4] - R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
goto L32;
L33: R[4] = MM[R[0] + 3];//factor var
R[5] = 0;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L34;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L34: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 44];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 1;//factor
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 0;//factor
MM[R[0] + 3] = R[3]; //assignment_statement
L35: R[2] = MM[R[0] + 8];//factor tmp
R[3] = 11;//factor
R[2] = R[2] < R[3]; //relation 
R[2] = !R[2]; //while
if(R[2]) goto L36; //while
R[4] = MM[R[0] + 3];//factor var
R[5] = MM[R[0] + 8];//factor tmp
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 3] = R[4]; //assignment_statement
R[4] = MM[R[0] + 8];//factor tmp
R[5] = 1;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 8] = R[4]; //assignment_statement
goto L35;
L36: R[4] = MM[R[0] + 3];//factor var
R[5] = 55;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L37;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L37: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 45];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 0;//factor
MM[R[0] + 3] = R[3]; //assignment_statement
R[3] = 0;//factor
MM[R[0] + 2] = R[3]; //assignment_statement
R[3] = 0;//factor
MM[R[0] + 8] = R[3]; //assignment_statement
L38: R[2] = MM[R[0] + 8];//factor tmp
R[3] = 4;//factor
R[2] = R[2] < R[3]; //relation 
R[2] = !R[2]; //while
if(R[2]) goto L39; //while
R[4] = MM[R[0] + 8];//factor tmp
MM[R[0] + 2] = R[4]; //assignment_statement
L40: R[3] = MM[R[0] + 2];//factor par
R[4] = 5;//factor
R[3] = R[3] < R[4]; //relation 
R[3] = !R[3]; //while
if(R[3]) goto L41; //while
R[5] = MM[R[0] + 3];//factor var
R[6] = 1;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 3] = R[5]; //assignment_statement
R[5] = MM[R[0] + 2];//factor par
R[6] = 1;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 2] = R[5]; //assignment_statement
goto L40;
L41: R[4] = 0;//factor
MM[R[0] + 2] = R[4]; //assignment_statement
L42: R[3] = MM[R[0] + 2];//factor par
R[4] = 5;//factor
R[3] = R[3] < R[4]; //relation 
R[3] = !R[3]; //while
if(R[3]) goto L43; //while
R[5] = MM[R[0] + 3];//factor var
R[6] = 1;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 3] = R[5]; //assignment_statement
R[5] = MM[R[0] + 2];//factor par
R[6] = 1;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 2] = R[5]; //assignment_statement
goto L42;
L43: R[4] = MM[R[0] + 8];//factor tmp
R[5] = 1;//factor
R[4] = R[4] + R[5]; //arithop 2
MM[R[0] + 8] = R[4]; //assignment_statement
goto L38;
L39: R[4] = MM[R[0] + 3];//factor var
R[5] = 34;//factor
R[4] = R[4] == R[5]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L44;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L44: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 46];//factor putBool
MM[R[0] + 8] = R[3]; //assignment_statement
MM[9937] = '_';
MM[9936] = '_';
MM[9935] = 'c';
MM[9934] = 'a';
MM[9933] = 's';
MM[9932] = 'e';
MM[9931] = ' ';
MM[9930] = 's';
MM[9929] = 't';
MM[9928] = 'a';
MM[9927] = 't';
MM[9926] = 'e';
MM[9925] = 'm';
MM[9924] = 'e';
MM[9923] = 'n';
MM[9922] = 't';
MM[9921] = '_';
MM[9920] = '_';
MM[9919] = '\0';
R[4] = 9937; // string factor "__case statement__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L45;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L45: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 47];//factor putString
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 9;//factor
MM[R[0] + 8] = R[3]; //assignment_statement
R[3] = 0;//factor
MM[R[0] + 3] = R[3]; //assignment_statement
R[2] = MM[R[0] + 8];//factor tmp
R[3] = R[2] == 3; //case
R[3] = !R[3]; //case
if(R[3]) goto L47; //case
R[5] = MM[R[0] + 3];//factor var
R[6] = 1;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 3] = R[5]; //assignment_statement
goto L46;
L47:R[3] = R[2] == 9; //case
R[3] = !R[3]; //case
if(R[3]) goto L48; //case
R[5] = MM[R[0] + 3];//factor var
R[6] = 10;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 3] = R[5]; //assignment_statement
goto L46;
L48:R[3] = R[2] == 11; //case
R[3] = !R[3]; //case
if(R[3]) goto L49; //case
R[5] = MM[R[0] + 3];//factor var
R[6] = 100;//factor
R[5] = R[5] + R[6]; //arithop 2
MM[R[0] + 3] = R[5]; //assignment_statement
goto L46;
L49:L46:R[6] = MM[R[0] + 3];//factor var
R[7] = 10;//factor
R[6] = R[6] == R[7]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L50;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[6]; //passing argument 
goto PUTBOOL;
L50: R[1] = R[0];
R[0] = MM[R[0]-1];
R[5] = MM[R[0] + 48];//factor putBool
MM[R[0] + 8] = R[5]; //assignment_statement
R[5] = 0;//factor
MM[R[0] + 3] = R[5]; //assignment_statement
R[4] = 11;//factor
R[5] = R[4] == 3; //case
R[5] = !R[5]; //case
if(R[5]) goto L52; //case
R[7] = MM[R[0] + 3];//factor var
R[8] = 1;//factor
R[7] = R[7] + R[8]; //arithop 2
MM[R[0] + 3] = R[7]; //assignment_statement
goto L51;
L52:R[5] = R[4] == 9; //case
R[5] = !R[5]; //case
if(R[5]) goto L53; //case
R[7] = MM[R[0] + 3];//factor var
R[8] = 10;//factor
R[7] = R[7] + R[8]; //arithop 2
MM[R[0] + 3] = R[7]; //assignment_statement
goto L51;
L53:R[5] = R[4] == 11; //case
R[5] = !R[5]; //case
if(R[5]) goto L54; //case
R[7] = MM[R[0] + 3];//factor var
R[8] = 100;//factor
R[7] = R[7] + R[8]; //arithop 2
MM[R[0] + 3] = R[7]; //assignment_statement
goto L51;
L54:R[7] = MM[R[0] + 3];//factor var
R[8] = 1000;//factor
R[7] = R[7] + R[8]; //arithop 2
MM[R[0] + 3] = R[7]; //assignment_statement
L51:R[8] = MM[R[0] + 3];//factor var
R[9] = 100;//factor
R[8] = R[8] == R[9]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L55;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[8]; //passing argument 
goto PUTBOOL;
L55: R[1] = R[0];
R[0] = MM[R[0]-1];
R[7] = MM[R[0] + 49];//factor putBool
MM[R[0] + 8] = R[7]; //assignment_statement
R[7] = 0;//factor
MM[R[0] + 3] = R[7]; //assignment_statement
R[6] = 0;//factor
R[7] = 12;//factor
R[6] = R[6] - R[7]; //arithop 2
R[7] = R[6] == 3; //case
R[7] = !R[7]; //case
if(R[7]) goto L57; //case
R[9] = MM[R[0] + 3];//factor var
R[10] = 1;//factor
R[9] = R[9] + R[10]; //arithop 2
MM[R[0] + 3] = R[9]; //assignment_statement
goto L56;
L57:R[7] = R[6] == 9; //case
R[7] = !R[7]; //case
if(R[7]) goto L58; //case
R[9] = MM[R[0] + 3];//factor var
R[10] = 10;//factor
R[9] = R[9] + R[10]; //arithop 2
MM[R[0] + 3] = R[9]; //assignment_statement
goto L56;
L58:R[7] = R[6] == 11; //case
R[7] = !R[7]; //case
if(R[7]) goto L59; //case
R[9] = MM[R[0] + 3];//factor var
R[10] = 100;//factor
R[9] = R[9] + R[10]; //arithop 2
MM[R[0] + 3] = R[9]; //assignment_statement
goto L56;
L59:R[9] = MM[R[0] + 3];//factor var
R[10] = 1000;//factor
R[9] = R[9] + R[10]; //arithop 2
MM[R[0] + 3] = R[9]; //assignment_statement
L56:R[10] = MM[R[0] + 3];//factor var
R[11] = 1000;//factor
R[10] = R[10] == R[11]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L60;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[10]; //passing argument 
goto PUTBOOL;
L60: R[1] = R[0];
R[0] = MM[R[0]-1];
R[9] = MM[R[0] + 50];//factor putBool
MM[R[0] + 8] = R[9]; //assignment_statement
R[9] = 0;//factor
MM[R[0] + 3] = R[9]; //assignment_statement
R[8] = 11;//factor
R[9] = R[8] == 3; //case
R[9] = !R[9]; //case
if(R[9]) goto L62; //case
R[11] = MM[R[0] + 3];//factor var
R[12] = 1;//factor
R[11] = R[11] + R[12]; //arithop 2
MM[R[0] + 3] = R[11]; //assignment_statement
goto L61;
L62:R[9] = R[8] == 9; //case
R[9] = !R[9]; //case
if(R[9]) goto L63; //case
R[11] = MM[R[0] + 3];//factor var
R[12] = 10;//factor
R[11] = R[11] + R[12]; //arithop 2
MM[R[0] + 3] = R[11]; //assignment_statement
goto L61;
L63:R[9] = R[8] == 11; //case
R[9] = !R[9]; //case
if(R[9]) goto L64; //case
R[11] = MM[R[0] + 3];//factor var
R[12] = 100;//factor
R[11] = R[11] + R[12]; //arithop 2
MM[R[0] + 3] = R[11]; //assignment_statement
R[10] = MM[R[0] + 3];//factor var
R[11] = R[10] == 77; //case
R[11] = !R[11]; //case
if(R[11]) goto L66; //case
R[13] = MM[R[0] + 3];//factor var
R[14] = 22;//factor
R[13] = R[13] + R[14]; //arithop 2
MM[R[0] + 3] = R[13]; //assignment_statement
goto L65;
L66:R[11] = R[10] == 100; //case
R[11] = !R[11]; //case
if(R[11]) goto L67; //case
R[13] = MM[R[0] + 3];//factor var
R[14] = 33;//factor
R[13] = R[13] + R[14]; //arithop 2
MM[R[0] + 3] = R[13]; //assignment_statement
R[12] = MM[R[0] + 3];//factor var
R[13] = R[12] == 0; //case
R[13] = !R[13]; //case
if(R[13]) goto L69; //case
R[15] = MM[R[0] + 3];//factor var
R[16] = 123;//factor
R[15] = R[15] + R[16]; //arithop 2
MM[R[0] + 3] = R[15]; //assignment_statement
goto L68;
L69:R[15] = MM[R[0] + 3];//factor var
R[16] = 2000;//factor
R[15] = R[15] + R[16]; //arithop 2
MM[R[0] + 3] = R[15]; //assignment_statement
L68:goto L65;
L67:R[11] = R[10] == 10; //case
R[11] = !R[11]; //case
if(R[11]) goto L70; //case
R[15] = MM[R[0] + 3];//factor var
R[16] = 44;//factor
R[15] = R[15] + R[16]; //arithop 2
MM[R[0] + 3] = R[15]; //assignment_statement
goto L65;
L70:R[15] = MM[R[0] + 3];//factor var
R[16] = 44;//factor
R[15] = R[15] + R[16]; //arithop 2
MM[R[0] + 3] = R[15]; //assignment_statement
L65:goto L61;
L64:R[15] = MM[R[0] + 3];//factor var
R[16] = 1000;//factor
R[15] = R[15] + R[16]; //arithop 2
MM[R[0] + 3] = R[15]; //assignment_statement
L61:R[16] = MM[R[0] + 3];//factor var
R[17] = 2133;//factor
R[16] = R[16] == R[17]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L71;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[16]; //passing argument 
goto PUTBOOL;
L71: R[1] = R[0];
R[0] = MM[R[0]-1];
R[15] = MM[R[0] + 51];//factor putBool
MM[R[0] + 8] = R[15]; //assignment_statement
MM[9918] = '_';
MM[9917] = '_';
MM[9916] = 'a';
MM[9915] = 'r';
MM[9914] = 'r';
MM[9913] = 'a';
MM[9912] = 'y';
MM[9911] = 's';
MM[9910] = '_';
MM[9909] = '_';
MM[9908] = '\0';
R[16] = 9918; // string factor "__arrays__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L72;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[16]; //passing argument 
goto PUTSTRING;
L72: R[1] = R[0];
R[0] = MM[R[0]-1];
R[15] = MM[R[0] + 52];//factor putString
MM[R[0] + 8] = R[15]; //assignment_statement
R[14] = 0;//factor
R[15] = 5;//factor
MM[R[0] + 9 + R[14]] = R[15]; //assignment_statement
R[17] = 0;//factor
R[16] = MM[R[0] + 9 + R[17]];//factor array1
R[17] = 5;//factor
R[16] = R[16] == R[17]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L73;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[16]; //passing argument 
goto PUTBOOL;
L73: R[1] = R[0];
R[0] = MM[R[0]-1];
R[15] = MM[R[0] + 53];//factor putBool
MM[R[0] + 8] = R[15]; //assignment_statement
R[14] = 6;//factor
R[15] = 8;//factor
MM[R[0] + 9 + R[14]] = R[15]; //assignment_statement
R[17] = 0;//factor
R[16] = MM[R[0] + 9 + R[17]];//factor array1
R[18] = 6;//factor
R[17] = MM[R[0] + 9 + R[18]];//factor array1
R[16] = R[16] * R[17]; //term 2
R[17] = 40;//factor
R[16] = R[16] == R[17]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L74;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[16]; //passing argument 
goto PUTBOOL;
L74: R[1] = R[0];
R[0] = MM[R[0]-1];
R[15] = MM[R[0] + 54];//factor putBool
MM[R[0] + 8] = R[15]; //assignment_statement
R[14] = 7;//factor
R[15] = 9;//factor
MM[R[0] + 9 + R[14]] = R[15]; //assignment_statement
R[14] = 8;//factor
R[15] = 10;//factor
MM[R[0] + 9 + R[14]] = R[15]; //assignment_statement
R[14] = 0;//factor
R[15] = 100;//factor
MM[R[0] + 19 + R[14]] = R[15]; //assignment_statement
R[14] = 6;//factor
R[15] = 200;//factor
MM[R[0] + 19 + R[14]] = R[15]; //assignment_statement
R[14] = 7;//factor
R[15] = 300;//factor
MM[R[0] + 19 + R[14]] = R[15]; //assignment_statement
R[14] = 9;//factor
R[15] = 400;//factor
MM[R[0] + 19 + R[14]] = R[15]; //assignment_statement
R[15] = MM[R[0] + 9 + R[-1]];//factor array1
MM[R[0] + 19] = R[15]; //assignment_statement
MM[9907] = 't';
MM[9906] = 'e';
MM[9905] = 's';
MM[9904] = 't';
MM[9903] = '\0';
R[16] = 9907; // string factor "test"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L75;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[16]; //passing argument 
goto PUTSTRING;
L75: R[1] = R[0];
R[0] = MM[R[0]-1];
R[15] = MM[R[0] + 55];//factor putString
MM[R[0] + 8] = R[15]; //assignment_statement
R[17] = 8;//factor
R[16] = MM[R[0] + 19 + R[17]];//factor array2
R[17] = 10;//factor
R[16] = R[16] == R[17]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L76;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[16]; //passing argument 
goto PUTBOOL;
L76: R[1] = R[0];
R[0] = MM[R[0]-1];
R[15] = MM[R[0] + 56];//factor putBool
MM[R[0] + 8] = R[15]; //assignment_statement
R[15] = MM[R[0] + 19 + R[-1]];//factor array2
MM[R[0] + 9] = R[15]; //assignment_statement
R[17] = 7;//factor
R[16] = MM[R[0] + 9 + R[17]];//factor array1
R[17] = 9;//factor
R[16] = R[16] == R[17]; //relation 
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L77;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[16]; //passing argument 
goto PUTBOOL;
L77: R[1] = R[0];
R[0] = MM[R[0]-1];
R[15] = MM[R[0] + 57];//factor putBool
MM[R[0] + 8] = R[15]; //assignment_statement
R[15] = 1;//factor
R[16] = 1;//factor
R[15] = R[15] == R[16]; //relation 
MM[R[0] + 0] = R[15]; //assignment_statement
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
L1:R[0] = 0;
R[1] = R[0];
MM[R[0]+1] = &&end;
R[1] = R[1]+2;
goto L0;
GETBOOL: MM[R[0]] = getBool();
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
GETINT: MM[R[0]] = getInt();
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
GETSTRING: MM[R[0]] = getString();
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
PUTBOOL: MM[R[0]] = putBool(MM[R[0] + 2]);
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
PUTINT: MM[R[0]] = putInt(MM[R[0] + 2]);
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
PUTSTRING: MM[R[0]] = putString(MM[R[0] + 2]);
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
SQRT: MM[R[0]] = isqrt(MM[R[0] + 2]);
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
INT2BOOL: MM[R[0]] = int2bool(MM[R[0] + 2]);
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
BOOL2INT: MM[R[0]] = bool2int(MM[R[0] + 2]);
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
end: printf("\n");
for(i = 0; i < MAX_USED_REGISTER; i++)
printf("R[%d] = %d\n",i,R[i]);
printf("\n\n");
for(i = 0; i < 20; i++)
printf("MM[%d] = %d\t\t MM[%d] = %d\n",i,MM[i],MM_SIZE - 1 - i, MM[MM_SIZE - 1 - i]);
 return 0;
 }
