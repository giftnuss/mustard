

#include <wisper/foundation/list_of_leaves.h>
#include <wisper/foundation/message.h>
#include <wisper/exception/memoryerror.h>
#include <wisper/exception/overflow.h>
#include <wisper/bits/bitlist64.h>

struct Placeholders {
  leaflist_t placeholders;
  bitlist64 uselist;
};

typedef struct Placeholders placeholders_type;
typedef struct Placeholders* placeholders_t;

static placeholders_t _new_placeholders()
{
  placeholders_t node = (placeholders_t) malloc(sizeof(placeholders_type));
  if(node != NULL) {
    node->placeholders = NULL;
    node->uselist = 0;
    return node;
  }
  memoryerror_exception();
  return (placeholders_t) NULL;
}

static void _render(node_t self, text_t result)
{
  nodelist_t nodes = self->nodes;
  int cnt = 0, end = nodes->used;
  placeholders_t node = (placeholders_t) self->node;
  
  for(; cnt < end; ++cnt) {
	int plidx = bitlist64_value(node->uselist,cnt);
	render_node(nodes->list[cnt],result);
    if(plidx >= 0) {
      leaf_t leaf = get_from_list_of_leaves(node->placeholders, plidx);
      if(leaf != NULL) {
		render_leaf(leaf,result);
	  }
    }
  }
}

static void _free(node_t self)
{
  placeholders_t node = (placeholders_t) self->node;
  if(node->placeholders != NULL) {
	free_list_of_leaves(node->placeholders);
  }
  free(self->node);
}

static void my_methods(node_t self)
{
  self->render = _render;
  self->free_node = _free;
}

node_t new_message()
{
  node_t self = new_node();
  self->node = _new_placeholders();
  my_methods(self);
  return self;	
}

void add_placeholder(node_t self, leaf_t placeholder)
{
  placeholders_t node = (placeholders_t) self->node;

  if(node->placeholders == NULL) {
	size_t size = self->nodes->used;
    if(size < 1) {
	  size = 1;
    }
	node->placeholders = new_list_of_leaves(size);  
  }
  if(bitlist64_add_value(&(node->uselist), 
    add_to_list_of_leaves(node->placeholders, placeholder)) == bln_false()) {
	  overflow_exception();  
  }
}

void reuse_placeholder(node_t self, size_t plidx)
{
  placeholders_t node = (placeholders_t) self->node;
  
  if(bitlist64_add_value(&(node->uselist), plidx) == bln_false()) {
	overflow_exception();  
  }
}

