#include "runtime.h"

int getBool(){
  int b;
  scanf("%d",&b);
  return b;
}
  
int getInt(){
  int n;
  scanf("%d",&n);
  return n;
}
  
int getString(){
  //get string from stdin, put it in string table, return address
  char strbuf[255];
  scanf("%s",strbuf);

  //find next free slot in str table
  int i = MM_SIZE - 1;
  while(MM[i] != 0){
    i--;
    if (i == R[1])//if you hit top of stack, outta room in str table.
      return -1;
  }
  int strstart = i; //first empty slot
  for(i = 0; i < strlen(strbuf); i++){
    MM[strstart - i] = strbuf[i];
  }
  MM[strstart - strlen(strbuf)] = '\0';
  
  return strstart;
}
  
int putBool(int b){
  printf("%d\n",b);
  return 0;
}

int putInt(int n){
  printf("%d\n",n);
  return 0;
}

int putString(int straddr){
  //look up string in string table, print it out.
  int i = straddr;
  while(MM[i] != '\0'){
    printf("%c",MM[i--]);
  }
  printf("\n");
  return 0;
}

int isqrt(int n){
  return (int) sqrt((double) n);
}

int int2bool(int n){
  if(n != 0)
    return 1;
  else
    return 0;
}

int bool2int(int b){
  return b;
}
