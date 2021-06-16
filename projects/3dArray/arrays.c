#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// free two dimentional array
static void free2d(void **a){
  // free the rows(all blocks given to )a[0]
  free(a[0]);

  // free array of pointers i.e malloc(sizeof(void *) * numOfRows)
  free(a);
}

static void **malloc2d(size_t numRows, size_t rowSize){

  void **a;
  size_t i;
  // „a„ is an array of void * pointers that point to the rows
  a = malloc(sizeof(void *) * numRows);
  if(a == 0){
    // malloc failed
    return 0;
  }

  // let's allocate rows now
  // we allocate one big block to a[0] which extend through
  // the other rows
  a[0] = malloc(numRows * rowSize);
  if(a[0] == 0){
    free(a);

    return 0;
  }

  // fill in the remaining pointers
  for(i = 1; i < numRows; i++){
    // compute offset for each rows asides from a[0]
    // it's already done in line 28!!!
    a[i] = a[0] + rowSize * i;
  }

  return a;
}

int main(int argc, char **argv){
  int rows;
  int cols;
  int **arr2;
  void print3dArray(size_t, size_t, int **);
  // 1. Using the built-in 2d-arrays
  if(argc != 3){
    fprintf(stderr, "Usage: %s rows cols\n", argv[0]);
    return 1;
  }

  rows = atoi(argv[1]);
  cols = atoi(argv[2]);

  int arr1[rows][cols]; // declaring builtin-2d array
  int i, j;
  puts("Using builtin-2d array array[i][j]\n");
  for(i = 0; i < rows; i++)
    for(j = 0; j < cols; j++)
      arr1[i][j] = (i + 1) * 10 + (j + 1);

  for(i = 0; i < rows; i++){
    for(j = 0; j < cols; j++)
      printf("%4d", arr1[i][j]);
    putchar('\n');
  }

  // 2. Using an array of pointers to rows
  arr2 = (int **) malloc2d(rows, cols * sizeof(int));
  puts("\nUsing array of pointers to rows void **array\n");
  print3dArray(rows, cols, arr2);

  free2d((void **)arr2);
}

void print3dArray(size_t rows, size_t cols, int **a){
  int i, j;
  for(i = 0; i < rows; i++)
    for(j = 0; j < cols; j++)
      a[i][j] = (i + 1) * 10 + (j + 1);

  for(i = 0; i < rows; i++){
    for(j = 0; j < cols; j++)
      printf("%4d", a[i][j]);
    putchar('\n');
  }

  printf("size of void * = %d\n", sizeof(void *));
}
