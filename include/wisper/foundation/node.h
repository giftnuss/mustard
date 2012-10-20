 
#ifndef _WISPER_FOUNDATION_NODE_H_
# define _WISPER_FOUNDATION_NODE_H_

#include <wisper/foundation/list_of_nodes.h>
#include <wisper/foundation/text.h>
#include <wisper/bool.h>

struct Node {
  nodelist_t nodes;
  void* node;
  void (*render)(struct Node*, text_t);
  /**
   * Die Methode gibt den Rückabewert an ob die Nodelist (nodes)
   * aufgeräumt werden müssen.
   * @see delete_node
   */
  bool (*free_node)(struct Node*);
};

typedef struct Node node_type;
typedef struct Node* node_t;

node_t new_node();

node_t new_constant_node();

int add_node(node_t outer, node_t inner);

void render_node(node_t node, text_t result);

void delete_node(node_t);

bool is_constant_node(node_t);

bool default_free_node_method(node_t);

#endif
