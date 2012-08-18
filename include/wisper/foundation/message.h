
#ifndef _WISPER_FOUNDATION_MESSAGE_H_
# define _WISPER_FOUNDATION_MESSAGE_H_

#include <wisper/foundation/node.h>
#include <wisper/foundation/leaf.h>

node_t new_message();

void add_placeholder(node_t, leaf_t);

void reuse_placeholder(node_t, size_t);

#endif
