 
#ifndef _WISPER_FOUNDATION_NODE_H_
# define _WISPER_FOUNDATION_NODE_H_

#include <wisper/foundation/list_of_nodes.h>
#include <wisper/foundation/text.h>

struct Node {
  nodelist_t nodes;
  void* node;
  void (*render)(struct Node*, text_t);
  void (*free)(struct Node*);
};

typedef struct Node node_type;
typedef struct Node* node_t;

node_t new_node();

int add_node(node_t outer, node_t inner);

void render_node(node_t node, text_t result);

void delete_node(node_t);

#endif
