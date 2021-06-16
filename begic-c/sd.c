#include "sd.h"

int sum(int ind, int *arr){
  int su = 0;
  for(int i=0; i<ind; i++){
    su += *arr++;
  }
  return su;
}
