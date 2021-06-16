#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

void expandCount(int c, int nextc){
  for(int i = 0; i < (c - '0' + 1); i++)
    putc(nextc, stdout);
}
int main(int argc, char **argv){
  if(argc != 2){
    fprintf(stderr, "Usage: %s [- or filename]\n", argv[0]);
    exit(1);
  }

  int c; // current character
  int nextc;

  char h[2] = "-";
  h[1] = '\0';
  FILE *a = (argv[1][0] == h[0]) ? stdin : fopen(argv[1], "r");

  while ((c = getc(a)) != EOF){   
    if(isdigit(c)){
      // take another character and duplicate it
      if((nextc = getc(a)) != EOF){
        expandCount(c, nextc);
      }
    }
    else
      putc(c, stdout); // no duplicate
  }

  return 0;
}
