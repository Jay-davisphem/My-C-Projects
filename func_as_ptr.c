#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void die(char *message){
  if (errno)
    perror(message);
  else{
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

// a typedef create a fake type of a funtion pointer
typedef int (* compare)(int a, int b);

// Bubble sort algorithm
int *bubble_sort(int *numbers, int count, compare cmp){
  int temp = 0; int i = 0; int j = 0;
  int *target = malloc(count * sizeof(int));
  if (!target)
    die("Memory error!");
  memcpy(target, numbers, count * sizeof(int));

  for (i = 0; i < count; i++){
    for (j = 0; j < count - 1; j++){
      if (cmp(target[j], target[j + 1]) > 0){
        temp = target[j];
        target[j] = target[j + 1];
        target[j + 1] = temp;
      }
    }
  }
  return target;
}

int *insert_sort(int *numbers, int count, compare cmp){
  int temp = 0; int i = 0; int j = 0;
  int *target = malloc(count * sizeof(int));
  if (!target)
    die("Memory error!");
  memcpy(target, numbers, count * sizeof(int));
  for (i = 1; i < count; i++){
    j = i;
    while (j > 0 && cmp(target[j - 1], target[j]) > 0){
      temp = target[j];
      target[j] = target[j - 1];
      target[j - 1] = temp;
      j--;
    }
  }
  return target;
}

int sorted_order(int a, int b){
  return a - b;
}
int reverse_order(int a, int b){
  return b - a;
}
int strange_order(int a, int b){
  if (a == 0 || b == 0)
    return 0;
  else
    return a % b;
}

typedef int *(* sort_func)(int *a, int b, compare cmp);
void test_sorting(int *numbers, int count, sort_func sort, compare cmp){
  int i = 0;
  int *sorted = sort(numbers, count, cmp);
  if (!sorted)
    die("Failed to sort as requested!");

  for (i = 0; i < count; i++){
    printf("%d ", sorted[i]);
  }
  printf("\n");
  free(sorted);

  // wanna do something with function 'cmp'
  unsigned char *data = (unsigned char *)cmp;
  for (i = 0; i < 25; i++){
    printf("%02x:", data[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]){
  if (argc < 2) die("Usage: <fileexecutable> 9 3 5 1 8");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;
  int *numbers = malloc(count * sizeof(int));
  if (!numbers) die("Memory error!");

  for (i = 0; i < count; i++){
    numbers[i] = atoi(inputs[i]);
  }
  test_sorting(numbers, count, bubble_sort, sorted_order);
  test_sorting(numbers, count, insert_sort, reverse_order);
  test_sorting(numbers, count, bubble_sort, strange_order);

  free(numbers);
  return 0;
}
