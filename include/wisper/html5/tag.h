
#ifndef _WISPER_HTML5_TAG_H_
# define _WISPER_HTML5_TAG_H_

#include <wisper/foundation/node.h>
#include <wisper/html5/tags.h>

node_t new_html5_tag(html5_element_type);

void set_html5_attribute(node_t, html5_attribute_type, const char*);

#endif

