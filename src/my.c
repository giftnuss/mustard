
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include <wisper/my.h>
#include <wisper/foundation/message.h>
#include <wisper/foundation/textnode.h>
#include <wisper/leafs/symbol_leaf.h>

#include <wisper/exception/memoryerror.h>

/**
 * Simply copies the given string and returns the
 * created pointer.
 */
char* my_str(const char* str)
{
  char* my = (char*) malloc(strlen(str) + 1);
  if(my != NULL) {
    return strcpy(my,str);
  }
  memoryerror_exception();
  return (char*) NULL;
}

/**
 * Joins the strings with the first argument. Variable argument
 * have to end with 0.
 */
char* my_str_join(const char* with, ...)
{
	va_list args;
	char* my = NULL;
	{
	  char* tmp;	
      node_t msg = new_message();
	  text_t result = new_text();
	  
	  add_placeholder(msg, new_symbol_leaf(with));
	
	  va_start(args,with);
	  while(0 != (tmp = va_arg(args, char*))) {
        add_node(msg, new_textnode_with_text(tmp));
        if(msg->nodes->used > 2) {
		  reuse_placeholder(msg,0);	
		}
      }
      va_end(args);
      
      render_node(msg, result);
      my = my_str(text_get_text(result));
      delete_text(result);
      delete_node(msg);
    }
    return my;
}
