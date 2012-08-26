

#ifndef _WISPER_FOUNDATION_LEAF_H_
# define _WISPER_FOUNDATION_LEAF_H_

#include <wisper/foundation/text.h>

struct Leaf {
  void* leaf;
  void (*render)(struct Leaf*, text_t);
  void (*free_leaf)(struct Leaf*);
};

typedef struct Leaf leaf_type;
typedef struct Leaf* leaf_t;

leaf_t new_leaf();

void render_leaf(leaf_t, text_t);

void delete_leaf(leaf_t);

#endif

