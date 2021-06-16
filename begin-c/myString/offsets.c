#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

int main(){
  struct foo{
    int i;
    char c;
    double d;
    float f;
    char *s;
    int it;
  };

  printf("i is at %u\n", offsetof(struct foo, i));
  printf("c is at %u\n", offsetof(struct foo, c));
  printf("d is at %u\n", offsetof(struct foo, d));
  printf("f is at %u\n", offsetof(struct foo, f));
  printf("s is at %u\n", offsetof(struct foo, s));
  printf("it is at %u\n", offsetof(struct foo, it));

  puts("Test STRUCTS AND UNION\n");

  struct lisp{
    int type;

    union{
      int intVal;
      double floatVal;
      char *stringVal;

      struct{
        struct lisp *obj1;
        struct lisp *obj2;
      } constVal;;
    } u;
  };

  enum type {INT, FLOAT, STRING, CONST, F};

  enum type gh;
  struct lisp lo;
  lo.type = INT;

  gh = 789;
  lo.u.intVal = 34;

  printf("%i\n", lo.u.intVal);
  printf("sizeof type %d, %d, %d\n", sizeof(enum type), F, gh);
}
