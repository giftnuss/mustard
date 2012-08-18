
#include <string.h>
#include <tap.h>

#include <wisper/foundation.h>

int main(int argv, char** argc)
{
  symbol_t alt = new_symbol("alt");
  
  is(alt->id,"alt","normal symbol");
  
  delete_symbol(alt);
  return 0;
}
