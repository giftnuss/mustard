
#include <string.h>
#include <tap.h>

#include <wisper/constant/nodes.h>
#include <wisper/test/node.h>

int main(int argv, char** argc)
{ 
  test_node_rendering(const_node_space()," ","const_node_space");
  test_node_rendering(const_node_newline(),"\n","const_node_newline");
  test_node_rendering(const_node_empty(),"","const_node_empty");

  { 
	text_t result = new_text();
	node_t space = const_node_space();
	render_node(space, result);
    is(text_get_text(result)," ","space");
    delete_node(space);
    delete_text(result);
  }
  
  {
	text_t result = new_text();
	node_t nl = const_node_newline();
	render_node(nl, result);
    is(text_get_text(result),"\n","newline");
    delete_node(nl);
    delete_text(result);
  }

  {
	text_t result = new_text();
	node_t empty = const_node_empty();
	render_node(empty, result);
	is(text_get_text(result),"","empty string");
	delete_node(empty);
	delete_text(result);
  }

  return 0;
}
