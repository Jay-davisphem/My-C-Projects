#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
  int pc, c;
  pc = 1;
  int a = EOF;
  printf("%d", a);
  while((c = getchar()) != EOF){
    if(isspace(pc) && !isspace(c)){
      putchar(' ');
      putchar(c);
    }else if(!isspace(pc) && !isspace(c)){
      putchar(c);
    }
    pc = c;     
  }
}
