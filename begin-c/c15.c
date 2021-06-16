#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[]){
  int ages[] = { 23, 43, 12, 89, 2 };
  char *names[] = {
    "Michael", "Opeyemi",
    "Oluwafemi", "Tosin", "Pejumola"
  };

  // size of arrays
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using indexing
  for (i = 0; i < count; i++){
    // access an 'name' array using pointer arithmetic
    printf("%s has %d years alive.\n", *(names + i), ages[i]);
  }

  printf("---\n");

  // set up pointer to the start of the arrays
  int *cur_age  = ages;
  char **cur_name = names;

  // Second way using pointer
  for (i = 0; i < count; i++){
    printf("%s is %d years old.\n",
       *(cur_name + i), *(cur_age + i));
  }

  printf("---\n");
  // third ways, pointers are just arrays
  for (i = 0; i < count; i++){
    // access pointer by indexing
    printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
  }

  printf("---\n");

  // fourth, an insane, stupid complex way of using pointer
  for (cur_age = ages, cur_name = names;
      (cur_age - ages) < count; cur_age++, cur_name++){
    printf("%p %p: %s lived %d years so far.\n",
        cur_name, cur_age, *cur_name, *cur_age); // Used for clarification sake.
  }

  printf("---\n");
  
  for (cur_age = ages + count - 1, cur_name = names + count - 1;
     0 <= (cur_age - ages) < count; cur_name--, cur_age--){
    printf("Wow! %p %p: %s lived %d years so far.\n",
        cur_name, cur_age, *cur_name, *cur_age);
    if (*cur_age == ages[0]){
      break;
    }
  }
  void pprint(int *, char *);
  int ades[] = {33, 23, 87, 655};
  char *na[] = {"femi", "laide", "fatiu", "cheese"};
  pprint(ades, *na);
  return 0;
}
void pprint(int *ages, char *names){
  int count = sizeof(ages);
  printf("Size of pointer array: %d\n", count);
  for (int i = 0; i < count; i++){
    printf("%c is %d years old.\n", names[i], ages[i]);
  }
}
