#include <stdio.h>

#define MAXN (10)
int main(int argc, char **argv){
  int n;

  for(n = -MAXN; n <= MAXN; n++){
    if(n == 0) continue;
    printf("1.0/%3d = %+.4f\n", n, 1.0/n);
  }
  return 0;
}
