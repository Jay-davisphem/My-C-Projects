#include <stdio.h>
#include "sd.h"

int main(){
  int ar[5] = {
    5,5,4,4,2
  };
  int ans = sum(5, ar);

  printf("Sum is %d\n", ans);
}
