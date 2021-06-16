#include <stdio.h>
int main(int argc, char *argv[]){
  char *file = argv[0];
  char **argp = argv + 1;
  
  int i = 0;
  printf("The file %s takes arguments:\n", file);
  for (i = 0; i < argc - 1; i++){
    printf("%p\n", (argp + i));
  }
}
