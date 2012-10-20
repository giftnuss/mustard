
#include <wisper/test/node.h>
#include <tap.h>

bool test_node_rendering
  (
    node_t node,
    char* expect,
    char* msg
  )
{
	bool this;
	text_t result = new_text();
	render_node(node, result);
    this = is(text_get_text(result),expect,msg);
    delete_text(result);
    return this;
}
