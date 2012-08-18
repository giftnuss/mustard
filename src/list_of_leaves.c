
#include <stdlib.h>

#include <wisper/foundation/list_of_leaves.h>

#include <wisper/exception/memoryerror.h>
#include <wisper/exception/invalidindex.h>

static leaflist_t _alloc_self()
{
  leaflist_t self = (leaflist_t) malloc(sizeof(leaflist_type));
  if(self != NULL) {
	  return self;
  }
  memoryerror_exception();
  return (leaflist_t) NULL;
}

static leaf_t* _alloc_data(leaf_t* buf, size_t new_size)
{
  buf = (leaf_t*) realloc((void *)buf, new_size * sizeof(leaf_t));
  if(buf != NULL) {
	  return buf;
  }
  memoryerror_exception();
  return (leaf_t*) NULL;
}

leaflist_t new_list_of_leaves(size_t bufsize)
{
  leaflist_t self = _alloc_self();
  self->list = _alloc_data(NULL,bufsize);
  self->buffersize = bufsize;
  self->gaps = bln_true();
  {
    int c = 0, end = bufsize;
    for(; c < end; ++c) { self->list[c] = NULL; }
  }
  return self;
}

/**
 * @return index of added leaf
 */
int add_to_list_of_leaves(leaflist_t self, leaf_t a_leaf)
{
  int c = 0, end = self->buffersize;

  if(self->gaps) {
    for(; c < end; ++c) {
      if(self->list[c] == NULL) {
        self->list[c] = a_leaf;
        return c;
      }
    }
    self->gaps = bln_false();
  }
  c = end + 1;
  self->list = _alloc_data(self->list, c);
  self->list[end] = a_leaf;
  self->buffersize = c;
  return end;
}

leaf_t get_from_list_of_leaves(leaflist_t self, size_t idx)
{
  if(idx >= self->buffersize) {
    invalidindex_exception();
    return (leaf_t) NULL;
  }
  return self->list[idx];
}

void free_list_of_leaves(leaflist_t self)
{
  int c = self->buffersize - 1;

  for(; c >= 0; --c) {
    if(self->list[c] != NULL) {
      delete_leaf(self->list[c]);
    }
  }
  free(self);
}

