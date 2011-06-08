#include "code_defs.h"
#include "std_defs.h"
#include "runtime.h"
#include <stdio.h>
int main(){
int i;
goto L1;
L0: R[1] = R[1] + 1; //allocate space for vartmp
goto L3;
L2: R[1] = R[1] + 1; //allocate space for arg n
R[1] = R[1] + 1; //allocate space for varcat
R[2] = MM[R[0] + 2];//factor n
R[3] = 0;//factor
R[2] = R[2] == R[3]; //relation 
R[2] = !R[2]; //if
if(R[2]) goto L4; //if
R[4] = 1;//factor
MM[R[0] + 0] = R[4]; //assignment_statement
L4: R[2] = !R[2]; //if
if(R[2]) goto L5; //if
R[5] = MM[R[0] + 2];//factor n
R[6] = 1;//factor
R[5] = R[5] - R[6]; //arithop1
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L6;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[5]; //passing argument n
goto L2;
L6: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 5];//factor factorial
R[5] = MM[R[0] + 2];//factor n
R[4] = R[4] * R[5]; //term
MM[R[0] + 0] = R[4]; //assignment_statement
L5: R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
L3:R[4] = 3;//factor
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L7;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument n
goto L2;
L7: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 4];//factor factorial
MM[R[0] + 2] = R[3]; //assignment_statement
R[6] = 3;//factor
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L9;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[6]; //passing argument n
goto L2;
L9: R[1] = R[0];
R[0] = MM[R[0]-1];
R[4] = MM[R[0] + 6];//factor factorial
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L8;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument 
goto PUTINT;
L8: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 5];//factor putInt
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
