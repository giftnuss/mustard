
#ifndef _WISPER_FOUNDATION_SYMBOL_H_
# define _WISPER_FOUNDATION_SYMBOL_H_

#include <stdlib.h>

struct Symbol {
  char* id;
};

typedef struct Symbol symbol_type;
typedef struct Symbol* symbol_t;

symbol_t new_symbol(const char*);

void delete_symbol(symbol_t);

#endif
