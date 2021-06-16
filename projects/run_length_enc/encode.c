#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <assert.h> 
#include <ctype.h>

#define MAX_RUN (10)

void printCharCount(int c, int count){
  // print count - 1 of character(c)
  putc(count - 1 + '0', stdout);
  // print character(c)
  putc(c, stdout);
}

int main(int argc, char **argv){
  if(argc != 2){
    fprintf(stderr, "Usage: %s [- or filename]\n", argv[0]);
    exit(1);
  }

  int c; // char to encode
  int nextc; // next character
  int count; // total count of c

  char h[2] = "-";
  h[1] = '\0';
  FILE *a = (argv[1][0] == h[0]) ? stdin : fopen(argv[1], "r");
  
  while((c = getc(a)) != EOF){
    // count c up to MAX-RUN
    for(count = 1; (nextc = getc(a)) == c && count < MAX_RUN; count++);

    ungetc(nextc, a);

    if(isdigit(c))
      printCharCount(c, count);
    else{
      switch(count){
        case 2:
          putc(c, stdout);
        case 1:
          putc(c, stdout);
          break;
        default:
          printCharCount(c, count);
          break;
      }
    }
  }
  return 0;
}
