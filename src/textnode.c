
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <wisper/foundation/node.h>
#include <wisper/foundation/text.h>
#include <wisper/foundation/textnode.h>

static void _render(node_t self, text_t result)
{
  text_t text = (text_t) self->node;
  text_add_text(result,text_get_text(text));
  render_list_of_nodes(self->nodes,result);
}

static void _free(node_t self)
{
  delete_text(self->node);
}

static void my_methods(node_t self)
{
  self->render = _render;
  self->free_node = _free;
}

node_t new_textnode()
{
  node_t self = new_node();
  self->node = new_text();
  my_methods(self);
  return self;
}

node_t new_textnode_with_text(const char* text)
{
  node_t self = new_node();
  self->node = new_text_with_text(text);
  my_methods(self);
  return self;
}

void add_text_to_node(node_t self, const char* text)
{
  text_add_text(self->node, text);
}
