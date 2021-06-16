// For -Loops and Arrays of Strings (13)

#include <stdio.h>

int main (int argc, char *argv[]) {
  int i = 0;
  char *states[] = {
    "Osun", "Oyo", "Lagos", "Abuja", NULL, argv[1]
  };
  argv[1] = "Changed";
  for (i = 1; i < argc; i++) {
      printf("argv %d: %s\n", i, argv[i]);
  }
  for (i = 0; i < 6; i++) {
    printf("state %d: %s\n", i, states[i]);
  }

  return 0;
}
