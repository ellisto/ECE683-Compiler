#include "code_defs.h"
#include "std_defs.h"
#include "runtime.h"
#include <stdio.h>
int main(){
int i;
goto L1;
L0: R[1] = R[1] + 1; //allocate space for varvar
R[1] = R[1] + 1; //allocate space for varbar
R[1] = R[1] + 1; //allocate space for vartrue
R[1] = R[1] + 1; //allocate space for varfalse
R[1] = R[1] + 1; //allocate space for varsar
R[1] = R[1] + 1; //allocate space for vartmp
MM[9999] = '_';
MM[9998] = '_';
MM[9997] = 'e';
MM[9996] = 'x';
MM[9995] = 'p';
MM[9994] = 'r';
MM[9993] = 'e';
MM[9992] = 's';
MM[9991] = 's';
MM[9990] = 'i';
MM[9989] = 'o';
MM[9988] = 'n';
MM[9987] = ' ';
MM[9986] = 'o';
MM[9985] = 'p';
MM[9984] = 'e';
MM[9983] = 'r';
MM[9982] = 'a';
MM[9981] = 't';
MM[9980] = 'i';
MM[9979] = 'o';
MM[9978] = 'n';
MM[9977] = 's';
MM[9976] = '_';
MM[9975] = '_';
MM[9974] = '\0';
R[4] = 9999; // string factor "__expression operations__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L2;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L2: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 9];//factor putString
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 1;//factor
R[4] = 1;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 4] = R[3]; //assignment_statement
R[3] = 1;//factor
R[4] = 1;//factor
R[3] = R[3] != R[4]; //relation 
MM[R[0] + 5] = R[3]; //assignment_statement
R[3] = MM[R[0] + 5];//factor false
R[3] = !R[3];//expression
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L3;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L3: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 10];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = MM[R[0] + 4];//factor true
R[4] = MM[R[0] + 4];//factor true
R[3] = R[3] && R[4]; //expression
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L4;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L4: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 11];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = MM[R[0] + 4];//factor true
R[4] = MM[R[0] + 5];//factor false
R[3] = R[3] || R[4]; //expression
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L5;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L5: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 12];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = MM[R[0] + 5];//factor false
R[4] = MM[R[0] + 5];//factor false
R[5] = MM[R[0] + 4];//factor true
R[4] = R[4] && R[5]; //expression
R[3] = R[3] || R[4]; //expression
R[3] = !R[3];//expression
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L6;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L6: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 13];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
MM[9973] = '_';
MM[9972] = '_';
MM[9971] = 'a';
MM[9970] = 'r';
MM[9969] = 'i';
MM[9968] = 't';
MM[9967] = 'h';
MM[9966] = 'm';
MM[9965] = 'e';
MM[9964] = 't';
MM[9963] = 'i';
MM[9962] = 'c';
MM[9961] = ' ';
MM[9960] = 'o';
MM[9959] = 'p';
MM[9958] = 'e';
MM[9957] = 'r';
MM[9956] = 'a';
MM[9955] = 't';
MM[9954] = 'i';
MM[9953] = 'o';
MM[9952] = 'n';
MM[9951] = 's';
MM[9950] = '_';
MM[9949] = '_';
MM[9948] = '\0';
R[4] = 9973; // string factor "__arithmetic operations__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L7;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L7: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 14];//factor putString
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 9;//factor
R[4] = 12;//factor
R[3] = R[3] + R[4]; //arithop 2
R[4] = 21;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L8;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L8: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 15];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 0;//factor
R[4] = 15;//factor
R[5] = 5;//factor
R[3] = R[3] - R[4]; //arithop 2
R[3] = R[3] + R[5]; //arithop 2
R[4] = 0;//factor
R[5] = 10;//factor
R[4] = R[4] - R[5]; //arithop 2
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L9;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L9: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 16];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 26;//factor
R[4] = 8;//factor
R[3] = R[3] - R[4]; //arithop 2
R[4] = 18;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L10;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L10: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 17];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 8;//factor
R[4] = 4;//factor
R[3] = R[3] | R[4]; //arithop 2
R[4] = 12;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L11;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L11: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 18];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 31;//factor
R[4] = 12;//factor
R[3] = R[3] & R[4]; //arithop 2
R[4] = 12;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L12;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L12: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 19];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
MM[9947] = '_';
MM[9946] = '_';
MM[9945] = 'r';
MM[9944] = 'e';
MM[9943] = 'l';
MM[9942] = 'a';
MM[9941] = 't';
MM[9940] = 'i';
MM[9939] = 'o';
MM[9938] = 'n';
MM[9937] = ' ';
MM[9936] = 'o';
MM[9935] = 'p';
MM[9934] = 'e';
MM[9933] = 'r';
MM[9932] = 'a';
MM[9931] = 't';
MM[9930] = 'i';
MM[9929] = 'o';
MM[9928] = 'n';
MM[9927] = 's';
MM[9926] = '_';
MM[9925] = '_';
MM[9924] = '\0';
R[4] = 9947; // string factor "__relation operations__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L13;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L13: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 20];//factor putString
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 1;//factor
R[4] = 1;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L14;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L14: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 21];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = MM[R[0] + 4];//factor true
R[4] = MM[R[0] + 4];//factor true
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L15;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L15: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 22];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 7;//factor
R[4] = 1;//factor
R[3] = R[3] != R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L16;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L16: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 23];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = MM[R[0] + 5];//factor false
R[4] = MM[R[0] + 4];//factor true
R[3] = R[3] != R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L17;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L17: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 24];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 7;//factor
R[4] = 3;//factor
R[3] = R[3] > R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L18;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L18: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 25];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 9;//factor
R[4] = 22;//factor
R[3] = R[3] < R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L19;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L19: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 26];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
MM[9923] = '_';
MM[9922] = '_';
MM[9921] = 'f';
MM[9920] = 'a';
MM[9919] = 'c';
MM[9918] = 't';
MM[9917] = 'o';
MM[9916] = 'r';
MM[9915] = ' ';
MM[9914] = 'o';
MM[9913] = 'p';
MM[9912] = 'e';
MM[9911] = 'r';
MM[9910] = 'a';
MM[9909] = 't';
MM[9908] = 'i';
MM[9907] = 'o';
MM[9906] = 'n';
MM[9905] = 's';
MM[9904] = '_';
MM[9903] = '_';
MM[9902] = '\0';
R[4] = 9923; // string factor "__factor operations__"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L20;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L20: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 27];//factor putString
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 5;//factor
R[4] = 7;//factor
R[3] = R[3] * R[4]; //term 2
R[4] = 35;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L21;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L21: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 28];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 2;//factor
R[4] = 2;//factor
R[5] = 3;//factor
R[6] = 4;//factor
R[3] = R[3] * R[4]; //term 2
R[3] = R[3] * R[5]; //term 2
R[3] = R[3] * R[6]; //term 2
R[4] = 3;//factor
R[5] = 4;//factor
R[6] = 2;//factor
R[7] = 2;//factor
R[4] = R[4] * R[5]; //term 2
R[4] = R[4] * R[6]; //term 2
R[4] = R[4] * R[7]; //term 2
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L22;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L22: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 29];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 8;//factor
R[4] = 2;//factor
R[5] = 4;//factor
R[6] = 2;//factor
R[3] = R[3] / R[4]; //term 2
R[3] = R[3] * R[5]; //term 2
R[3] = R[3] / R[6]; //term 2
R[4] = 8;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L23;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L23: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 30];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 0;//factor
R[4] = 3;//factor
R[3] = R[3] - R[4]; //arithop 2
R[4] = 0;//factor
R[5] = 8;//factor
R[4] = R[4] - R[5]; //arithop 2
R[3] = R[3] * R[4]; //term 2
R[4] = 24;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L24;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L24: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 31];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 21;//factor
R[4] = 3;//factor
R[3] = R[3] / R[4]; //term 2
R[4] = 7;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L25;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L25: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 32];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 18;//factor
R[4] = 0;//factor
R[5] = 2;//factor
R[4] = R[4] - R[5]; //arithop 2
R[3] = R[3] / R[4]; //term 2
R[4] = 0;//factor
R[5] = 9;//factor
R[4] = R[4] - R[5]; //arithop 2
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L26;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L26: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 33];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 0;//factor
R[4] = 9;//factor
R[3] = R[3] - R[4]; //arithop 2
R[4] = 3;//factor
R[3] = R[3] / R[4]; //term 2
R[4] = 0;//factor
R[5] = 3;//factor
R[4] = R[4] - R[5]; //arithop 2
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor bar
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L27;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTBOOL;
L27: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 34];//factor putBool
MM[R[0] + 7] = R[3]; //assignment_statement
R[3] = 1;//factor
R[4] = 1;//factor
R[3] = R[3] == R[4]; //relation 
MM[R[0] + 0] = R[3]; //assignment_statement
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
