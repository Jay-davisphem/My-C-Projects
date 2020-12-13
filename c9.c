#include <stdio.h>

int main(int argc, char *argv[]) {
  char *state[] = {"California", "Oregon", "Washington", "Texas"};

  int i = 0;
  for (i = 0; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }
  int j = 0;
  while (j < 4) {
    printf("State %d: %s\n", j, state[j]);
    j++;
  }
}
