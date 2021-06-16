#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
  int c;

  while((c = getchar()) != EOF){
    switch(c){
      case '\t':
        printf("\\t");
        break;
      case '\b':
        printf("\\b");
        break;
      case '\\':
        printf("\\\\");
        break;
      default:
        putchar(c);
        break;
    }
  }
}
