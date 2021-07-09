#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct elt{
  struct elt *next;
  int value;
};

typedef struct elt *Stack;

#define STACK_EMPTY (0)

/* push a new value on top th stack */
void stackPush(Stack *s, int value){
  
  struct elt *e;

  e = malloc(sizeof(struct elt));
  assert(e);

  e->value = value;
  e->next = *s;

  *s = e;
}

int stackEmpty(Stack *s){
  return (*s == 0);
}

/* remove an item from the top a List */
int stackPop(Stack *s){
  int ret;
  struct elt *e;

  assert(!stackEmpty(s));

  ret = (*s)->value;

  e = *s;

  *s = e->next;

  free(e);
  return ret;
}

/* print content of stack on a single line */
void stackPrint(const Stack *s){

  struct elt *e;
  for(e = *s; e != 0; e = e->next){
    printf("%d ", e->value);
  }

  putchar('\n');
}

void stackPrintReversedRecursive(struct elt *first) {
  static int ij = 0;
  if(first != 0) { 
    /* print the rest of the stack */
    stackPrintReversedRecursive(first->next); 
    /* then print the first element */  
    printf("%d|%d ", first->value, ij++);
  }
}
int main(int argc, char **argv){

  int i;
  Stack s;

  s = STACK_EMPTY;

  for(i = 0; i < 20; i++){
    printf("push %d\n", i);
    stackPush(&s, i);
    stackPrint(&s);
  }

  puts(""); puts("");
  stackPrintReversedRecursive(s);
  puts(""); puts("");

  while(!stackEmpty(&s)){
    printf("pops %d\n", stackPop(&s));
    stackPrint(&s);
  }
}
