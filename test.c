#include <stdio.h>
#include <stdint.h>
/*int main(int argc, char * argv[]){
  int arr[] = {76, 45, 93, 4, 6, 4, 45, 5};
  char rt[5] = {'r', 'i', 'y', 'o', '\0'};
  int *arr_ptr = arr;
  printf("%s %d %d %p\n",rt, sizeof(arr)/sizeof(arr_ptr), arr[1], arr_ptr);
  int aba = 56;
  int *ptaba = &aba;
  printf("%d %p\n", *ptaba, ptaba);
  uint32_t i;
  scanf("%u", &i);
  printf("%u\n", ~i);

  FILE *cur;
  
  fopen(filename, "r+");
  fputs("Oluwafemi Boy.\nI love you o.", cur);
  printf("%d %s\n", TMP_MAX, filename);*/

  static int j;
  static int k;
  void up(){
    j++;
    k++;

    printf("up() called.   k= %2d, j= %2d\n", k , j);
  }

  void down(){
    j--;
    k--;

    printf("down() called. k= %2d, j= %2d\n", k , j);
  }
int main(void){
/*  int i = 0;
  for (i = 0; i < 3; i++) up();
  for (i = 0; i < 2; i++) down();*/

  printf("UINT32_MAX: %u\n", UINT32_MAX);
  printf("INT32_IN: %i\n", INT32_MIN);
  printf("INT32_MAX: %i\n", INT32_MAX);
 // printf("INT64_MIN: %lg", INT64_MIN);
}
