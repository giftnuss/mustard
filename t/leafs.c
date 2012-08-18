

#include <string.h>
#include <tap.h>

#include <wisper/foundation.h>
#include <wisper/leafs.h>

int main(int argv, char** argc)
{
  text_t result = new_text();
  leaf_t t0 = new_symbol_leaf("*");
  
  render_leaf(t0,result);
  ok(0 == strcmp(text_get_text(result),"*"),"* symbol");
  
  delete_leaf(t0);
  delete_text(result);
  return 0;
}
