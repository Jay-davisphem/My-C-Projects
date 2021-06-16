#include <stdio.h>
#include "ghj/testi.h"
#include <ctype.h>
#include <math.h>
#define EXPRESSION_ERROR (-1)

/*
 * read an expression from the stdin and return its value
 * returns EXPRESSION_ERROR on error 
*/

int readExpression(void){
  int e1; /* value of first sub-expression */
  int op; /* operation: '+' or '*' */
  int e2; /* value of second sub-expression */
  int c;  /* character streamer */

  c = peekchar();

  if (c == '('){
    c = getchar();

    e1 = readExpression();
    op = getchar();
    e2 = readExpression();

    c = getchar(); /* closing of the expression */
    if (c != ')') return EXPRESSION_ERROR;

    /* else */
    switch(op){
      case '+':
        return e1 + e2;
        break;
      case '*':
        return e1 * e2;
        break;
      case '-':
        return e1 - e2;
        break;
      case '/':
        return e1 / e2;
        break;
      case '^':
        return pow(e1, e2);
        break;
      default:
        return EXPRESSION_ERROR;
        break;
    }
  }
  else if (isdigit(c))
    return readNumber();
  else
    return EXPRESSION_ERROR;
}

int main(){
  int a = readExpression();
  printf("%d\n", a);
}
