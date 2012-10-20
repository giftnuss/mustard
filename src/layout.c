
#include <wisper/foundation/layout.h>

static void _render_layout()
{
	
}

static bool _free_layout()
{

   return false;	
}

node_t new_layout()
{
   node_t self = new_node();
   self->free_node = _free_layout;
}

node_t layout_get(size_t idx)
{
	
}

void set_layout_root(size_t idx, node_t root)
{
	
}

void set_layout_branch(size_t idx, node_t branch)
{
	
}

int layout_add_node(size_t idx, node_t add)
{
	
}
