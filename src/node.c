
#include <wisper/foundation/node.h>
#include <wisper/foundation/list_of_nodes.h>
#include <wisper/exception/memoryerror.h>

static node_t _alloc_self()
{
  node_t self = (node_t) malloc(sizeof(node_type));
  if(self != NULL) {
	  return self;
  }
  memoryerror_exception();
  return (node_t) NULL;
}

static void _render(node_t self, text_t result)
{
  render_list_of_nodes(self->nodes, result);
}

static void _free(node_t self)
{
  return;
}

static void my_methods(node_t self)
{
  self->render = _render;
  self->free_node = _free;
}

node_t new_node()
{
  node_t self = _alloc_self();
  self->nodes = new_list_of_nodes();
  self->node = NULL;
  my_methods(self);
  return self;
}

node_t new_constant_node()
{
  node_t self = _alloc_self();
  self->nodes = NULL;
  self->node = NULL;
  self->render = NULL;
  self->free_node = NULL;
  return self; 
}

void delete_node(node_t self)
{
  if(!is_constant_node(self)) {
    self->free_node(self);
    free_list_of_nodes(self->nodes);
    free(self);
  }
}

int add_node(node_t outer, node_t inner)
{
  add_to_list_of_nodes(outer->nodes,inner);
  return outer->nodes->used;
}

void render_node(node_t node, text_t result)
{
  node->render(node,result);
}

bool is_constant_node(node_t self)
{
  return self->nodes == NULL;
}

