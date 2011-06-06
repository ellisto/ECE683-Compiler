#include "code_defs.h"
#include "std_defs.h"
#include <stdio.h>

int main(){
  goto MAIN;

 funclbl: 
  MM[R[0]] = R[1];
  R[1] = R[0] + 1;
  R[1] = MM[R[0]];
  goto *R[1];

 MAIN:
  R[0] = 0;
  R[1] = &&end;
 call1: goto funclbl;
 end: 
   for(i = 0; i < 9; i++){
   printf("R[%d] = %d",i,R[i]);
 }
return 0;
}
