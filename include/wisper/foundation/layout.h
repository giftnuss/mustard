

#ifndef _WISPER_FOUNDATION_LAYOUT_H_
#define  _WISPER_FOUNDATION_LAYOUT_H_

/**
 * @brief
 */

node_t new_layout();
 
node_t layout_get(size_t);

int layout_add_node(size_t, node_t);

void set_layout_root(size_t, node_t);

void set_layout_branch(size_t, node_t);

#endif


