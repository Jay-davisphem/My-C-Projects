#ifndef _devices_macro_h
#define _devices_macro_h

#include <stdio.h>
#ifdef USEduffs
#define dev(n, count) (count + (n - 1)) / n
#define realDef(exp, count, size) {\
  arr = dev(size, count);\
  switch(count % size){\
    case 0:\
      do {\
        exp;\
        i = size - 1;\
        while (i != 0){\
          case i: exp; i--;\
        }\
      } while(--arr > 0);\
  }\
  return count;
}
#endif
#endif
