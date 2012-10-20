
#ifndef _WISPER_HTML5_ATTRIBUTE_H_
# define _WISPER_HTML5_ATTRIBUTE_H_

#include <wisper/bool.h>
#include <wisper/foundation/leaf.h>
#include <wisper/foundation/text.h>
#include <wisper/foundation/list_of_leaves.h>
#include <wisper/html5/tags.h>

leaf_t new_html5_attribute(html5_attribute_type);

void set_html5_attribute_value(leaf_t, const char*);

bool has_html5_attribute_type(leaf_t, html5_attribute_type);

void render_list_of_attributes(leaflist_t, text_t);

#endif

