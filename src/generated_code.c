#include "code_defs.h"
#include "std_defs.h"
#include "runtime.h"
#include <stdio.h>
int main(){
int i;
goto L1;
L0: R[1] = R[1] + 1; //allocate space for varlabel
R[1] = R[1] + 15; // allocate space for array someArray
R[1] = R[1] + 1; //allocate space for varresult
goto L3;
L2: R[1] = R[1] + 1; //allocate space for arg amount
R[1] = R[1] + 1; //allocate space for arg label
R[1] = R[1] + 1; //allocate space for vari
R[3] = 100;//factor
MM[R[0] + 4] = R[3]; //assignment_statement
R[4] = MM[R[0] + 3];//factor label
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L4;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTSTRING;
L4: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 6];//factor putString
MM[R[0] + 18] = R[3]; //assignment_statement
L5: R[2] = MM[R[0] + 4];//factor i
R[2] = !R[2]; //while
if(R[2]) goto L6; //while
MM[R[0] + 0] = R[4]; //assignment_statement
MM[9999] = 'D';
MM[9998] = 'i';
MM[9997] = 'v';
MM[9996] = 'i';
MM[9995] = 'd';
MM[9994] = 'i';
MM[9993] = 'n';
MM[9992] = 'g';
MM[9991] = ' ';
MM[9990] = 'a';
MM[9989] = 'm';
MM[9988] = 'o';
MM[9987] = 'u';
MM[9986] = 'n';
MM[9985] = 't';
MM[9984] = ' ';
MM[9983] = 'b';
MM[9982] = 'y';
MM[9981] = ' ';
MM[9980] = 't';
MM[9979] = 'w';
MM[9978] = 'o';
MM[9977] = ' ';
MM[9976] = 'f';
MM[9975] = 'o';
MM[9974] = 'r';
MM[9973] = ' ';
MM[9972] = 't';
MM[9971] = 'a';
MM[9970] = 's';
MM[9969] = 'k';
MM[9968] = '\0';
R[5] = 9999; // string factor "Dividing amount by two for task"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L7;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[5]; //passing argument 
goto PUTSTRING;
L7: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 7];//factor putString
MM[R[0] + 18] = R[4]; //assignment_statement
MM[R[0] + 0] = R[4]; //assignment_statement
MM[9967] = 'I';
MM[9966] = 'n';
MM[9965] = 'c';
MM[9964] = 'r';
MM[9963] = 'e';
MM[9962] = 'm';
MM[9961] = 'e';
MM[9960] = 'n';
MM[9959] = 't';
MM[9958] = 'i';
MM[9957] = 'n';
MM[9956] = 'g';
MM[9955] = ' ';
MM[9954] = 'a';
MM[9953] = 'm';
MM[9952] = 'o';
MM[9951] = 'u';
MM[9950] = 'n';
MM[9949] = 't';
MM[9948] = ' ';
MM[9947] = 'f';
MM[9946] = 'o';
MM[9945] = 'r';
MM[9944] = ' ';
MM[9943] = 't';
MM[9942] = 'a';
MM[9941] = 's';
MM[9940] = 'k';
MM[9939] = '\0';
R[5] = 9967; // string factor "Incrementing amount for task"
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L8;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[5]; //passing argument 
goto PUTSTRING;
L8: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 8];//factor putString
MM[R[0] + 18] = R[4]; //assignment_statement
goto L5;
L6: R[4] = MM[R[0] + 2];//factor amount
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L9;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTINT;
L9: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 9];//factor putInt
MM[R[0] + 18] = R[3]; //assignment_statement
R[3] = MM[R[0] + 4];//factor i
R[4] = 1;//factor
R[3] = R[3] - R[4]; //arithop1
MM[R[0] + 4] = R[3]; //assignment_statement
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
L3:MM[9938] = 'A';
MM[9937] = ' ';
MM[9936] = 't';
MM[9935] = 'e';
MM[9934] = 's';
MM[9933] = 't';
MM[9932] = ' ';
MM[9931] = 'j';
MM[9930] = 'o';
MM[9929] = 'b';
MM[9928] = '\0';
R[3] = 9938; // string factor "A test job"
MM[R[0] + 3] = R[3]; //assignment_statement
R[4] = 10;//factor
R[4] = MM[R[0] + 3];//factor label
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L10;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument amount
MM[R[0] + 3] = R[4]; //passing argument label
goto L2;
L10: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 20];//factor dowork
MM[R[0] + 18] = R[3]; //assignment_statement
R[3] = 0;//factor
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
end: for(i = 0; i < MAX_USED_REGISTER; i++)
printf("R[%d] = %d\n",i,R[i]);
printf("\n\n");
for(i = 0; i < 20; i++)
printf("MM[%d] = %d\n",i,MM[i]);
 return 0;
 }
