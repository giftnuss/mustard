
#include <wisper/html5/tag.h>
#include <wisper/html5/attribute.h>
#include <wisper/foundation/list_of_leaves.h>
#include <wisper/bits/bitfield64.h>

#include <wisper/my.h>
#include <wisper/exception/memoryerror.h>

struct HtmlNode {
  char* element_name;
  leaflist_t attributes;
  bitfield64 attribute_field;
};

typedef struct HtmlNode html_node_type;
typedef struct HtmlNode* html_node_t;

static char* _begin_tag = "<";
static char* _close_tag = ">";
static char* _close_stag = "/>";
static char* _begin_endtag = "</";

static void _render_single_tag(node_t self, text_t result)
{
  html_node_t node = (html_node_t) self->node;
  text_add_text(result, _begin_tag);
  text_add_text(result, node->element_name);
  text_add_text(result, _close_stag);
  render_list_of_nodes(self->nodes, result);
}

static void _render_double_tag(node_t self, text_t result)
{
  html_node_t node = (html_node_t) self->node;
  text_add_text(result, _begin_tag);
  text_add_text(result, node->element_name);
  text_add_text(result, _close_tag);
  render_list_of_nodes(self->nodes, result);
  text_add_text(result, _begin_endtag);
  text_add_text(result, node->element_name);
  text_add_text(result, _close_tag);
}

static void (*(_renderer[]))(node_t, text_t) = {
  _render_double_tag, /* a */
  _render_double_tag, /* body */
  _render_single_tag, /* br */
  _render_double_tag, /* canvas */
  _render_double_tag, /* dd */
  _render_double_tag, /* dfn */
  _render_double_tag, /* div */
  _render_double_tag, /* dl */
  _render_double_tag, /* dt */
  _render_double_tag, /* form */
  _render_double_tag, /* head */
  _render_double_tag, /* html */
  _render_single_tag, /* input */
  _render_double_tag, /* li */
  _render_single_tag, /* meta */
  _render_double_tag, /* ol */
  _render_double_tag, /* option */
  _render_double_tag, /* ruby */
  _render_double_tag, /* rp */
  _render_double_tag, /* rt */
  _render_double_tag, /* script */
  _render_double_tag, /* select */
  _render_double_tag, /* span */
  _render_double_tag, /* style */
  _render_double_tag, /* textarea */
  _render_double_tag, /* ul */
  _render_double_tag, /* video */
  _render_single_tag  /* wbr */
};

static html_node_t alloc_node(html5_element_type id)
{
  html_node_t node = (html_node_t) malloc(sizeof(html_node_type));
  if(node != NULL) {
	node->element_name = wisper_html_element_name[id];
	node->attributes = NULL;
	return node;
  }
  memoryerror_exception();
  return (html_node_t) NULL;
}

static void set_renderer(node_t self, html5_element_type id)
{
  self->render = _renderer[id];
}

/**
 * element_name wird extern verwaltet, bzw ist zu 99% statisch.
 */
static void _free_node(node_t self)
{
   html_node_t node = (html_node_t) self->node;
   if(node->attributes != NULL) {
      free_list_of_leaves(node->attributes);
   }
   free(self->node); 
}

node_t new_html5_tag(html5_element_type id)
{
  node_t self = new_node();
  self->node = alloc_node(id);
  set_renderer(self,id);
  self->free_node = _free_node;
  return self;
}

void
set_html5_attribute
    ( 
      node_t self, 
      html5_attribute_type id, 
      const char* val
    )
{
  html_node_t node = (html_node_t) self->node;
  leaf_t attr;

  if(node->attributes == NULL) {
    node->attributes = new_list_of_leaves(3);	  
  }
  if(bitfield64_value(node->attribute_field,id)) {
    int c = node->attributes->buffersize - 1;
    for(; c >= 0; c--) {
	  attr = get_from_list_of_leaves(node->attributes, c);
	  if( has_html5_attribute_type(attr, id) ) {
		set_html5_attribute_value(attr,val);
        return;
	  }
	}
  }
  else {
    attr = new_html5_attribute(id);
    set_html5_attribute_value(attr,val);
    add_to_list_of_leaves(node->attributes, attr);
    bitfield64_set_value(&node->attribute_field, id, 1);
  }
}
