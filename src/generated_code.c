#include "code_defs.h"
#include "std_defs.h"
#include "runtime.h"
#include <stdio.h>
int main(){
int i;
goto L1;
L0: goto L3;
L2: R[3] = 15;//factor
MM[R[0] + 0] = R[3]; //assignment_statement
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
L3:goto L5;
L4: MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L6;
R[1] = R[1] + 2; //leave room for return value and address
goto L2;
L6: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 4];//factor s
MM[R[0] + 0] = R[3]; //assignment_statement
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
L5:R[4] = MM[R[0] + 0];//factor i
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L7;
R[1] = R[1] + 2; //leave room for return value and address
goto L4;
L7: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 3];//factor t
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
