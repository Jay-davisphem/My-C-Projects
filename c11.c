// Working with arrays and string
#include <stdio.h>

int main(int argc, char *argv[]) {
  int numbers[4] = { 0 };
  char name[4] = { 'a', 'a', 'a', 'a' };

  // Let's print them out raw!
  printf("numbers: %d %d %d %d\n",
         numbers[0], numbers[1], numbers[2], numbers[3]);

  printf("name each: %c %c %c %c\n",
         name[0], name[1], name[2], name[3]);

  printf("name: %s\n", name);

  // Let's setup numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // Let's setup name
  name[0] = 98;
  name[1] = 'a';
  name[2] = 'v';
  name[3] = 5;
  // Let's print them out initialized
  printf("numbers: %d %d %d %d\n",
         numbers[0], numbers[1], numbers[2], numbers[3]);
  
  printf("name each: %c %c %c %c\n",
         name[0], name[1], name[2], name[3]);

  printf("name: %s\n", name);

  // Another way to use name
  char *another = "Dav";

  printf("another: %s\n", another);

  printf("another each: %c %c %c %c\n",
         another[0], another[1], another[2], another[3]);
  return 0;
}
