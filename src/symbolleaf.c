
#include <wisper/foundation/symbol.h>
#include <wisper/leafs/symbol_leaf.h>

static void _render(leaf_t self, text_t result)
{
  symbol_t symbol = (symbol_t) self->leaf;
  text_add_text(result, symbol->id);	
}

static void _free_symbol_leaf(leaf_t self)
{
  delete_symbol(self->leaf);
}

leaf_t new_symbol_leaf(const char* symbol)
{
  leaf_t self = new_leaf();
  self->leaf = new_symbol(symbol);
  self->render = _render;
  self->free = _free_symbol_leaf;
  return self;
}
