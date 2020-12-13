#include <stdio.h>

int main(int argc, char *argv[]){
  int i = 0;

  if (argc == 1){
    printf("You have no argument. Cheese! Not playing.\n");
  }
  else if (argc == 2) {
    printf("You have only one argument. You suck.\n");
  } 
  else if (argc > 2 && argc < 4) {
    printf("Here's your %d arguments:\n", argc - 1);
    for (i = 1; i < argc; i++) {
      printf("%s ", argv[i]);
    }
    printf("\n");
  }
  else {
    printf("You have too many argument. You suck.\n");
  }

  return 0;
}
