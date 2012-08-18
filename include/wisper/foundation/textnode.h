
#ifndef _WISPER_FOUNDATION_TEXTNODE_H_
# define _WISPER_FOUNDATION_TEXTNODE_H_

#include <wisper/foundation/node.h>
#include <wisper/foundation/text.h>
#include <wisper/foundation/list_of_nodes.h>

node_t new_textnode();

node_t new_textnode_with_text(const char *);

void add_text_to_node(node_t, const char*);

#endif
