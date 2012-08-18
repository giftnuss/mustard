
#include <string.h>
#include <tap.h>

#include <wisper/foundation.h>

int main(int argv, char** argc)
{
  text_t result = new_text();
  node_t t0 = new_textnode();
  node_t t1 = new_textnode_with_text("!");
  
  render_node(t0,result);
  is(text_get_text(result),"","empty textnode");
  render_node(t1,result);
  is(text_get_text(result),"!","! mark");
  
  delete_node(t0);
  delete_node(t1);
  delete_text(result);
  return 0;
}
