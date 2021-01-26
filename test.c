#include <stdio.h>

int main(int argc, char * argv[]){
  int arr[] = {76, 45, 93, 4, 6, 4, 45, 5};
  char rt[5] = {'r', 'i', 'y', 'o', '\0'};
  int *arr_ptr = arr;
  printf("%s %d %d %p\n",rt, sizeof(arr)/sizeof(arr_ptr), arr[1], arr_ptr);
  int aba = 56;
  int *ptaba = &aba;
  printf("%d %p\n", *ptaba, ptaba);
}
