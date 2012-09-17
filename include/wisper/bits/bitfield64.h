
#ifndef _WISPER_BITS_BITFIELD64_H_
# define _WISPER_BITS_BITFIELD64_H_

#include <stdint.h>

typedef uint64_t bitfield64;

int bitfield64_value(bitfield64,int);

void bitfield64_set_value(bitfield64*, int, int);

char* bitfield64_hex_format(bitfield64);

#endif
