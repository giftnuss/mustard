

#ifndef _WISPER_FOUNDATION_LIST_OF_LEAVES_H_
# define _WISPER_FOUNDATION_LIST_OF_LEAVES_H_

#include <stdlib.h>

#include <wisper/foundation/leaf.h>
#include <wisper/bool.h>

struct ListOfLeaves {
  leaf_t* list;
  int buffersize;
  bool gaps;
};

typedef struct ListOfLeaves leaflist_type;
typedef struct ListOfLeaves* leaflist_t;

leaflist_t new_list_of_leaves(size_t);

int add_to_list_of_leaves(leaflist_t, leaf_t);

leaf_t get_from_list_of_leaves(leaflist_t, size_t);

void free_list_of_leaves(leaflist_t);

#endif
