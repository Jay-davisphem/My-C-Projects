#include <stdlib.h>
#include <math.h>
#include "testi.h"
/* print out all bits of n */
void print_binary(unsigned int n){
    unsigned int mask = 0;

    /* this grotesque hack creates a bit pattern 1000... */
    /* regardless of the size of an unsigned int */
    printf("%0x %0x ", ~mask, (~mask >> 1));
    mask = ~mask ^ (~mask >> 1);
    printf("%0x\n\n", mask);
    for(; mask != 0; mask >>= 1) {
        printf("%0x\n", mask);
        puts((n & mask) ? "(1)" : "(0)");
    }
}

uint64_t factorial(int n) { 
  int i; long long product;
  if(n < 2) return n; 
  /* else */ 
  product = 1; 
  for(i = 2; i <= n; i++) {
    product *= i; 
  }
  return product;
}
int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        return 1;
    }

    char nc[5] = {'r', 'u', 'b', 'y', '\0'};
    char *ad[30];
    char ui = 'u';
    4[ad] = &nc[2];
    *(ad+1) = &ui;
    printf("two char: %c %c\n", **(ad+4), *1[ad]);
    print_binary(atoi(argv[1]));
    putchar('\n');
    int x = 6;
    const char * const string = "femi";
    const int *p = &x;
    x = 78;
    printf("%lf %lf, %s, %i\n", NAN, INFINITY, string, *p);
    int a[6] = {0,1,2,3,5,6};
    int i =0;
    a[i] = i++;
    putchar('A');
    printf("%d %d %lld", a[i], a[1], factorial(13));
    return 0;
}

