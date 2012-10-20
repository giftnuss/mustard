
#include <wisper/constant/nodes.h>

static void _render(node_t self, text_t result)
{
  char* text = (char *) self->node;
  text_add_text(result,text);
}

static node_type _space = 
{
	NULL, " ", _render, default_free_node_method
};

node_t const_node_space() { return &_space; }

static node_type _newline = 
{
	NULL, "\n", _render, default_free_node_method
};

node_t const_node_newline() { return &_newline; }

static node_type _empty =
{
	NULL, "", _render, default_free_node_method
};

node_t const_node_empty() { return &_empty; }
