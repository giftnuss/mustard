
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <wisper/bits/bitfield64.h>

int bitfield64_value(bitfield64 field,int idx)
{
  assert(idx >= 0 && idx < 64);
  
  {
	int pattern = 1 << idx;
	return (field & pattern) == 0 ? 0 : 1;
  }
}

void bitfield64_set_value(bitfield64* field, int idx, int val)
{
  bitfield64 pattern = 1 << idx;
  if(val == 0) {
	*field = *field & (~0 ^ pattern);
  }
  else {
	*field = *field | pattern;
  }
}

char* bitfield64_hex_format(bitfield64 field)
{
  unsigned int lower = field;
  unsigned int higher = field >> 32;
  char *result = (char*) malloc(sizeof(char)*19);
  sprintf(result,"0x%08x%08x",higher,lower);
  return result;
}
