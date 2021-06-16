#include <stdio.h>
#include <stdlib.h>

/*
 * Sum integers in a file. 
 */

int main(int argc, char **argv){
  FILE *f;
  int x, sum;

  if (argc != 2){
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  f = fopen(argv[1], "r");
  if(f == 0){
    /* perror is a standard C library routine */
    /* that prints a message about the last failed library routine */ 
    /* prepended by its argument */
    perror(argv[1]);
    exit(2);
  }

  sum = 0;
  /* fscanf here read one input and returns '1' 
   * at a time else return 'EOF' 
   */
  while(fscanf(f, "%d", &x) == 1){
    sum += x;
  }
  printf("%d\n", sum);

  fclose(f);

  return 0;
}
