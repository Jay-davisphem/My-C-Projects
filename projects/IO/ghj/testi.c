#include "testi.h"

int peekchar(void) {
  int c;
  c = getchar();
  if(c != EOF) 
    ungetc(c, stdin);
  return c;
}
int readNumber(void) { 
  int accumulator; 
  int c;
  accumulator = 0;   /* the number so far */
  while((c = peekchar()) != EOF && isdigit(c)) {
    c = getchar(); /* consume it */ 
    accumulator *= 10; 
    accumulator += (c -'0');
  }
  return accumulator;
}
