#include <stdio.h>
#include <conio.h>

int main() {
  int a, b, sum;
  clrscr();
  printf("Enter two number: ");
  scanf("%d %d", &a, &b);
  
  sum = a + b;
  printf("sum=%d", sum);
  getch();
}
