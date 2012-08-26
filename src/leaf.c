
#include <stdlib.h>

#include <wisper/foundation/leaf.h>
#include <wisper/exception/memoryerror.h>

static leaf_t _alloc_self()
{
  leaf_t self = (leaf_t) malloc(sizeof(leaf_type));
  if(self != NULL) {
	  return self;
  }
  memoryerror_exception();
  return (leaf_t) NULL;
}

leaf_t new_leaf()
{
  leaf_t self = _alloc_self();
  self->leaf = NULL;
  self->render = NULL;
  self->free_leaf = NULL;
  return self;
}

void render_leaf(leaf_t self, text_t result)
{
  self->render(self,result);
}

void delete_leaf(leaf_t self)
{
  self->free_leaf(self);
  free(self);
}
