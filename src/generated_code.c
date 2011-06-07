#include "code_defs.h"
#include "std_defs.h"
#include <stdio.h>
int main(){
int i;
goto L1;
L0: R[1] = R[1] + 1; //allocate space for vari
R[1] = R[1] + 5; // allocate space for array a
goto L3;
L2: R[3] = MM[R[0] + 2];//factor b
MM[R[0] + 0] = R[3]; //assignment_statement
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
L3:R[3] = 1;//factor
MM[R[0] + 2] = R[3]; //assignment_statement
R[2] = 0;//factor
R[3] = 0;//factor
MM[R[0] + 3 + R[2]] = R[3]; //assignment_statement
L4: R[2] = MM[R[0] + 2];//factor i
R[3] = 5;//factor
R[2] = R[2] < R[3]; //relation 
R[2] = !R[2]; //while
if(R[2]) goto L5; //while
R[3] = MM[R[0] + 2];//factor i
R[5] = MM[R[0] + 2];//factor i
R[6] = 1;//factor
R[5] = R[5] - R[6]; //arithop1
R[4] = MM[R[0] + 3 + R[5]];//factor a
R[5] = 5;//factor
R[4] = R[4] + R[5]; //arithop1
MM[R[0] + 3 + R[3]] = R[4]; //assignment_statement
R[4] = MM[R[0] + 2];//factor i
R[5] = 1;//factor
R[4] = R[4] + R[5]; //arithop1
MM[R[0] + 2] = R[4]; //assignment_statement
goto L4;
L5: R[4] = 3;//factor
MM[R[1]] = R[0]; //store old frame ptr
R[1] = R[1] + 1; //incrementing frm ptr storage 
R[0] = R[1]; //set frame ptr to top of stk
MM[R[0] + 1] = &&L6;
R[1] = R[1] + 2; //leave room for return value and address
MM[R[0] + 2] = R[4]; //passing argument b
goto L2;
L6: R[1] = R[0];
R[0] = MM[R[0]-1];
R[3] = MM[R[0] + 9];//factor arfunc
MM[R[0] + 0] = R[3]; //assignment_statement
R[2] = MM[R[0]+1];
goto *R[2]; //write return statement
L1:R[0] = 0;
R[1] = R[0];
MM[R[0]+1] = &&end;
R[1] = R[1]+2;
goto L0;
end: for(i = 0; i < MAX_USED_REGISTER; i++)
printf("R[%d] = %d\n",i,R[i]);
printf("\n\n");
for(i = 0; i < 20; i++)
printf("MM[%d] = %d\n",i,MM[i]);
 return 0;
 }
