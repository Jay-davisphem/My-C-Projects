#include <stdio.h>
#include "printFixed.h"
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SP (20)

static
const char* rev(char *str){
  int len = strlen(str);
  char *new = malloc(sizeof(char)*len);
  for(int i = 0; i < len; i++){
    new[i] = str[len - i - 1];
  }

  new[len] = '\0';
  return new;
}

static
const char* toString(long long num){
  if(num < 10){
    char *str = malloc(2*sizeof(char));
    str[0] = (char)num + '0';
    str[1] = '\0';
    return str;
  }
  char * str;
  str = malloc(MAX_SP * sizeof(char));
  int use, i;

  for(i = 0; num > 0; i++){
    use = num % 10;
    num /= 10;
    str[i] = '0' + use;
  }

  str[i] = '\0';
  return rev(str);
}

static
long long* outputs(long long num, unsigned int precision){
  long long divS = (long long)pow((double)10, (double)precision);
  long long rem = num % divS;
  long long divD = num / divS;
  static long long vals[2];
  vals[0] = divD;
  vals[1] = rem;
  return vals;
}
static
char* multchar(char s, int times){
  char* chr = malloc(sizeof(char)*times);
  int i;
  for(i = 0; i < times; i++){
    chr[i] = s;
  }
  chr[i] = '\0';
  return chr;
}
static
const char* rem(long long div, unsigned int precision){
  char * str = (char *)toString(div);
  int len = strlen(str);
  static char* new;
  if(len < precision)
    new = strcat(multchar('0', precision - len), str);
  else
    new = str;
  return new;
}

static
const char* partition(long long num, char separator){
  if(num < 1000){
    return toString(num);
  }
  char * str = (char *)toString(num);
  int len = strlen(str);
  int r = ((len % 3 == 0) ? 3 : (((len - 1) % 3 == 0) ? 1 : 2));
  char* first = malloc(sizeof(char)*(r));
  int remN = len - r + (len - r)/3;
  char * rem = malloc(sizeof(char)*remN);
  int i = 0;
  for(i = 0; i < r; i++)
    first[i] = str[i];
  first[i++] = separator;
  first[i] = '\0';

  int count = 0;
  for(int j = 0; j < remN; j++){
    if(count && count % 3 == 0){
      rem[j] = separator;
      count = 0;
      i--;
    }else{
      rem[j] = str[j+i-1];
      count++;
    }
  }
  rem[--remN] = '\0';
  return strcat(first, rem);
}

void printFixed(long long number,
    char separator, char decimalPoint, unsigned int precision){
  char sign = '\0';;
  if(number < 0)
    sign = '-';
  long long * vals = outputs(number, precision);
  long long dividend = vals[0];
  long long remainder = vals[1];
  printf("%c%s", sign, partition(dividend, separator));
  putchar(decimalPoint);
  printf("%s\n", rem(remainder, precision));
}
int main(int argc, char **argv){
  if(argc < 5){
    printf("Usage: %s [number] [separator] [decimalPoint] [precision]\n", argv[0]);
    exit(1);
  }
  long long num;
  int len = strlen(argv[1]);
  char new[len];
  short int sign = 1;
  if(argv[1][0] == '-'){
    sign = -1;
    int i;
    for(i = 1; i < len; i++){
      new[i-1] = argv[1][i];
    }
    new[i-1] = '\0';
    num = atoi(new);
  }else
    num = atoi(argv[1]);
  char sep = argv[2][0];
  char decP = argv[3][0];
  unsigned int presc = atoi(argv[4]);

  printFixed(sign*num, sep, decP, presc);
}
