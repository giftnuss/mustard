

#include <string.h>

#include <wisper/foundation/symbol.h>
#include <wisper/exception/memoryerror.h>

static symbol_t _alloc_self()
{
  symbol_t self = (symbol_t) malloc(sizeof(symbol_type));
  if(self != NULL) {
	return self;
  }
  memoryerror_exception();
  return (symbol_t) NULL;
}

static char* _alloc_id(const char* symbol)
{
  char* buf = (char*) malloc(sizeof(char) * (strlen(symbol) + 1));
  if(buf != NULL) {
	strcpy(buf,symbol);
	return buf;
  }
  memoryerror_exception();
  return (char*) NULL;
}
 
symbol_t new_symbol(const char* symbol)
{
  symbol_t self = _alloc_self();	
  self->id = _alloc_id(symbol);
  return self;
}

void delete_symbol(symbol_t self)
{
  free(self->id);
  free(self);
}
