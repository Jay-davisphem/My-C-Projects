#include <stdlib.h>
#include <string.h>

#include "myString.h"

struct string{
  int length;
  char *data;
};

struct string *makeString(const char *s){
  struct string *str;

  str = malloc(sizeof(struct string));
  if(!str)
    return 0;
  str->length = strlen(s);
  str->data = malloc(str->length);

  if(!str->data){
    free(str);
    return 0;
  }

  strncpy(str->data, s, str->length);

  return str;
}

void destroyString(struct string *s){
  free(s->data);
  free(s);
}

int stringLength(struct string *s){
  return s->length;
}

int stringCharAt(struct string *s, int index){
  if(index < 0 || index > s->length)
    return -1;
  return s->data[index];
}
