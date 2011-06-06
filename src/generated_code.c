#include "code_defs.h"
#include "std_defs.h"
#include <stdio.h>
int main(){
  int i;
  goto L1;
 L0: R[1] = R[1]+1; //allocate space for var a
  goto L3;
 L2: R[2] = MM[R[0] + 2];//factor b
  R[3] = MM[R[0] + 3];//factor c
  R[2] = R[2] + R[3]; //arithop1
  MM[R[0]+0] = R[2]; //assignment_statement
  R[2] = MM[R[0]+1];
  goto *R[2]; //write return statement
 L3:R[2] = 0;//factor
  MM[R[0]+2] = R[2]; //assignment_statement
  R[3] = 2;//factor
  R[3] = 5;//factor
  MM[R[1]] = R[0]; //store old frame ptr
  R[1] = R[1] + 1;
  R[0] = R[1]; //set frame ptr to top of stk
  MM[R[0] + 1] = &&L4;
  R[1] = R[1] + 2;
  MM[R[0]+2] = R[3]; //passing argument
  MM[R[0]+3] = R[3]; //passing argument
  goto L2;
 L4: R[1] = R[0];
  R[0] = MM[R[0]-1];
  R[2] = MM[R[0] + 5];//factor add
  MM[R[0]+2] = R[2]; //assignment_statement
  R[2] = MM[R[0] + 2];//factor a
  MM[R[0]+0] = R[2]; //assignment_statement
  R[2] = MM[R[0]+1];
  goto *R[2]; //write return statement
 L1:R[0] = 0;
  R[1] = R[0];
  MM[R[0]+1] = &&end;
  R[1] = R[1]+2;
  goto L0;
 end: for(i = 0; i < 20; i++)
    printf("MM[%d] = %d\n",i,MM[i]);
  return 0;
}
