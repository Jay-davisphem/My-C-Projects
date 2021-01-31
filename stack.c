#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Stack {
  int maxsize;
  int top;
  char *items;
};

void initialize(struct Stack *stk, int size){
  char new[size];
  stk->items = new;
  stk->maxsize = size;
  stk->top = 0;
}

void push(struct Stack *stk, char item){
  if (stk->top == stk->maxsize){
    perror("StackOverflowError");
    exit(1);
  }
  else{
    stk->items[stk->top] = item;
    stk->top++;
  }
}

char pop(struct Stack *stk){
  if (stk->top == 0){
    perror("StackUnderflowError");
    exit(1);
  }
  else{
    stk->top--;
    char r = stk->items[stk->top];
    return r;
  }
}

int main(void){
  struct Stack *stk = malloc(sizeof(struct Stack));
  initialize(stk, 5);
  for (int i = 0; i < 9; i++){
    char j;
    scanf("%c", &j);
    push(stk, j);
  }
  for (int i = 0; i < 10; i++){
    char a = pop(stk);
    printf("%c\n", a);
  }
}
