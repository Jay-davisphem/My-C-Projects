#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void strcat1(char *dest, const char *src) {
   // char *saved = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++));
    *dest = '\0';
}

void strcpy1(char *dest, const char *src){
  while((*dest++ = *src++));
}

char *strcatAlloc(const char *s1, const char *s2){
  char *src;
  src = malloc(strlen(s1)+strlen(s2)+1);

  strcpy1(src, s1);
  strcat1(src, s2);

  return src;
}

int main(){
  const char *s1 = "femi";
  const char *s2 = " joshua";
  char *hj = strcatAlloc(s1, s2);
  puts(hj);
  free(hj);

  const char *q = "Laide";
  char *r = malloc(strlen(s2)*2);

  strcpy1(r, q);
  strcat1(r, " ");
  strcat1(r, "Bakare");
  printf("%d\n", sizeof(char));
  puts(r);
}
