
#include <wisper/foundation/message.h>
#include <wisper/foundation/textnode.h>
#include <wisper/leafs/symbol_leaf.h>

#include <stdio.h>

int main(int argc, char** argv)
{
  char* greet;
  printf("%d %s\n",argc,argv[0]);
  if(argc > 1) {
	  greet = argv[1];
  }
  else {
	  greet = "world";
  }
  
  {
	node_t message = new_message();
	text_t result = new_text();

	add_node(message,new_textnode_with_text("Hello "));
	add_node(message,new_textnode_with_text("!"));
	add_placeholder(message,new_symbol_leaf(greet));
	
	render_node(message,result);
	printf("%s\n",text_get_text(result));
	
	delete_text(result);
	delete_node(message);
  }
  
  
  return 0;
}
