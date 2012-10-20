

#include <wisper/html5/attribute.h>

#include <wisper/constant/strings.h>
#include <wisper/foundation/list_of_leaves.h>
#include <wisper/my.h>

#include <wisper/exception/memoryerror.h>

static char* _attr_start = "=\"";
static char* _attr_end = "\"";

struct HtmlAttributeStruct {
    html5_attribute_type name_id;
    union {
        char* string;
        leaflist_t list;
    } value;
};

typedef struct HtmlAttributeStruct html_attr_type;
typedef struct HtmlAttributeStruct* html_attr_t;

static html_attr_t _alloc_attribute(html5_attribute_type id)
{
	html_attr_t leaf = (html_attr_t) malloc(sizeof(*leaf));
	if( NULL != leaf ) {
		leaf->name_id = id;
		leaf->value.string = NULL;
		return leaf;
	}
	memoryerror_exception();
	return (html_attr_t) NULL;
}

static void _free_attr(leaf_t self)
{
    html_attr_t attr = (html_attr_t) self->leaf;
    if(attr->value.string != NULL) {
        free(attr->value.string);
    }
    free(attr);
}

static void _free_class_attr(leaf_t self)
{
	html_attr_t attr = (html_attr_t) self->leaf;
	if(attr->value.list != NULL) {
        free_list_of_leaves(attr->value.list);
    }
    free(attr);
}

static void _render(leaf_t self, text_t result)
{
	html_attr_t attr = (html_attr_t) self->leaf;
    text_add_text(result, wisper_html_attribute_name[ attr->name_id ]);
    text_add_text(result, _attr_start);
    if(attr->value.string != NULL) {
	    text_add_text(result, attr->value.string);
	}
	text_add_text(result, _attr_end);
}

static void _render_class_attr(leaf_t self, text_t result)
{
	
	html_attr_t attr = (html_attr_t) self->leaf;
    text_add_text(result, wisper_html_attribute_name[ attr->name_id ]);
    text_add_text(result, _attr_start);
    if(attr->value.list != NULL) {

	}
	text_add_text(result, _attr_end);
}

leaf_t new_html5_attribute(html5_attribute_type id)
{
    leaf_t self = new_leaf();
    self->leaf = _alloc_attribute(id);
    switch(id) {
		case attribute_class:
			self->free_leaf = _free_class_attr;
	        self->render = _render_class_attr;		
			break;
		default:
			self->free_leaf = _free_attr;
			self->render = _render;    	
	}
	return self;
}

bool has_html5_attribute_type(leaf_t self, html5_attribute_type id)
{
	html_attr_t attr = (html_attr_t) self->leaf;
	return attr->name_id == id;
}

void set_html5_attribute_value(leaf_t self, const char* val)
{
	html_attr_t attr = (html_attr_t) self->leaf;
    switch(attr->name_id) {
		case attribute_class:
		// ...
			break;
		default:
		    attr->value.string = my_str(val); 	
	}
}

void render_list_of_attributes(leaflist_t attrlist, text_t result)
{
  int upper = attrlist->buffersize;

  for(int c = 0; c < upper; ++c) {
    if(attrlist->list[c] != NULL) {
	  text_add_text(result, constant_str_space);
      render_leaf(attrlist->list[c],result);
    }
  }
}


