
#ifndef _WISPER_BITS_BITLIST64_H_
# define _WISPER_BITS_BITLIST64_H_

#include <stdint.h>
#include <wisper/bool.h>

typedef uint64_t bitlist64;

int bitlist64_value(bitlist64,int);

bool bitlist64_add_value(bitlist64*, int);

char* bitlist64_hex_format(bitlist64);

#endif
