#include <stdio.h>
#include <stdint.h>

uint32_t binToGrey(uint32_t bin){
  // return `bin` XOR (`bin` right-shift once)
  return bin ^ (bin >> 1);
}

uint32_t greyToBin(uint32_t grey){
  uint32_t hold = grey;

  while (hold){
    // rightshift the temp `hold` once
    hold >>= 1;
    // take the exclusive or (`XOR`) of the new temp
    // and the original grey code
    grey ^= hold;
  }

  return grey;
}

int main(int argc, char *argv[]){
  uint32_t bin = 47;
  uint32_t grey = 56;
  printf("Grey to Bin %u ---> %u\n\n", grey, greyToBin(grey));
  printf("Bin to Grey %u ---> %u\n", bin, binToGrey(bin));
}
