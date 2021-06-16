#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SCOM_OUT (0)
#define SCOM_IN (1)

int main(){
  int c, pc;
  c = pc = 0;
  int scomStat = SCOM_OUT;
  while((c = getchar()) != EOF){
    if(c == '/' && pc == '/' && !scomStat){
      scomStat = SCOM_IN;
    }

    if(scomStat && c != '\n'){
      putchar('\0');
    }else if(scomStat && c == '\n'){
      putchar(c);
      scomStat = SCOM_OUT;
    }else if(!scomStat){
      putchar(c);
    }
    pc = c;
  }
}
