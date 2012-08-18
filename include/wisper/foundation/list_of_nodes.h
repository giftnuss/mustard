
#ifndef _WISPER_FOUNDATION_LIST_OF_NODES_H_
# define _WISPER_FOUNDATION_LIST_OF_NODES_H_

#include <stdlib.h>

#include <wisper/foundation/text.h>

struct ListOfNodes {
  int buffersize;
  int used;
  struct Node** list;
};

typedef struct ListOfNodes nodelist_type;
typedef struct ListOfNodes* nodelist_t;

nodelist_t new_list_of_nodes();

void add_to_list_of_nodes(nodelist_t, struct Node*);

struct Node* get_from_list_of_nodes(nodelist_t, size_t);

void render_list_of_nodes(nodelist_t, text_t result);

void free_list_of_nodes(nodelist_t);

#endif
