#include <stdio.h>
int main(int argc, char *argv[]) {
  if (argc != 2) {
    // We need an argument
    printf("Error: You need one argument.\n");
    return 1;
  }

  int i = 0;
  for (i = 0; argv[1][i] != '\0'; i++) {
    char letter = (((argv[1][i] >= 'A')? argv[1][i] : 'Z' + 1) <= 'Z')
      ? (32 + argv[1][i]) : argv[1][i];


    switch (letter) {
      case 'a':
        printf("%d: 'A'\n", i);
        break;

      case 'e':
        printf("%d: 'E'\n", i);
        break;

      case 'i':
        printf("%d: 'I'\n", i);
        break;

      case 'o':
        printf("%d: 'O'\n", i);
        break;

      case 'u':
        printf("%d: 'U'\n", i);
        break;

      case 'y':
        if (i > 2) {
          // It's only sometimes Y
          printf("%d: 'Y'\n", i);
          break;
        }
      default:
        printf("%d: %c is not a vowel\n", i, letter);
    }
  }
  return 0;
}
