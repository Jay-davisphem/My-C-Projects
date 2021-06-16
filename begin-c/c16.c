#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight){
  // allocate memory to who(malloc from stdlib)
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);
  who->name = strdup(name); //strdup duplicate name exactly from memory(bahaves like malloc)
  who->age = age;
  who->height = height;
  who->weight= weight;

  return who;
}

void Person_destroy(struct Person *who){
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who){
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[]){
  struct Person *femi = Person_create("David Oluwafemi", 23, 170, 67);
  struct Person *mike = Person_create("Oyebadejo Micheal", 21, 130, 79);

  // print 'em out
  printf("%s and %s are at memory locations %p and %p respectively\n",
      femi->name, mike->name, femi, mike);

  Person_print(femi);
  Person_print(mike);

  // make changes to them
  // femi->name = strcat("Mr. ", femi->name);
  femi->age += 5;
  femi->height += 23;

  Person_print(femi);
  Person_print(mike);

  //Person_destroy(NULL);
  Person_destroy(femi);
  Person_destroy(mike);

  return 0;
}
