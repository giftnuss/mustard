

#include <wisper/bits/bitlist64.h>

#include <stdlib.h>
#include <stdio.h>


char* bitlist64_hex_format(bitlist64 bl)
{
  unsigned int lower = bl;
  unsigned int higher = bl >> 32;
  char *result = (char*) malloc(sizeof(char)*19);
  sprintf(result,"0x%08x%08x",higher,lower);
  return result;
}

int bitlist64_value(bitlist64 bits, int pos)
{
  bitlist64 match = 1;
  int c = 0, bit = 0, start = 0;
  
  for(; bit < 64; ++bit) {
	if(bits & match) {
        if(c == pos) {
          return bit - start; 			
        }
        else {
		  c++; start = bit + 1;
	    }
	}
	match <<= 1;
  }
  return -1;
}

bool bitlist64_add_value(bitlist64* bits, int value)
{
  bitlist64 match = 0;
  
  if(*bits | match) {
	match = 0x1000000000000000;
    for(; match; match >>= 1) {
      if(*bits & match) {
		  match <<= 1;
          break;		  
      }
    } 
  }
  else {
	match = 1;
  }
  for(; match; match <<= 1, --value) {
	if(value == 0) {
      *bits |= match;
      return bln_true();
    }
  }
  return bln_false();
}
