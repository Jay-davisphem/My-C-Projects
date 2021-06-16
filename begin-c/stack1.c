// Stack using Linked list
#include <stdio.h>
#include <stdlib.h>

struct __attribute__((__packed__)) mystruct_A {
    char a;
    int b;
    char c;
};

struct Frame{
  char *data;
  struct Frame *next;
};

struct Stack {
  struct Frame *head;
  int size;
};

void initialize(struct Stack stk){
  stk.head = NULL;
  stk.size = 0;
}

void push(struct Stack stk, char *item){
  struct Frame newhead;
  newhead.data = item;
  newhead.next = stk.head;
  stk.head = &newhead;
  stk.size++;
}

char *pop(struct Stack stk){
  if (stk.head == NULL){
    perror("StackUnderFlowError");
    exit(1);
  }else{
  char *r = stk.head->data;
  stk.head = stk.head->next;
  stk.size--;
  return r;
  }
}

int main(void){
 /* struct Frame *head = malloc(sizeof(struct Frame));
  struct Frame *next1 = malloc(sizeof(struct Frame));
  struct Frame *next2 = malloc(sizeof(struct Frame));
  struct Frame *next3 = malloc(sizeof(struct Frame));
  struct Frame *next4 = malloc(sizeof(struct Frame));
  head->data = "femi";
  head->next = next1;*/
  struct Stack *stk = malloc(sizeof(struct Stack)); 
  initialize(*stk);
  /*stk.head = head;
  stk.size = 5;
  next1->data = "tosin";
  next1->next = next2;
  next2->data = "peter";
  next2->next = next3;
  next3->data = "matthew";
  next3->next = next4;
  next4->data = "gideon";
  next4->next = NULL;*/
  size_t size = 10;
  char *data[10] = {
    "rice", "beans", "indomie", "noodles", "egg", "bread", "milk",
    "meat", "banana", "pizza"
  };
  for (int i = 0; i < size; i++){
    printf("%s\n", data[i]);
    push(*stk, data[i]);
  }
  printf("---\n");
  char *a = pop(*stk);
  char *b = pop(*stk);
  printf("%s\n%s\n", a, b);
}
