
#include <string.h>
#include <stdio.h>
#include <tap.h>

#include <wisper/html5/tags.h>
#include <wisper/html5/attribute.h>

#define _at wisper_html_attribute_name

static void check_name_def()
{	
  is(_at[ attribute_action ],"action","action attribute");
  is(_at[ attribute_alt    ],"alt","alt attribute");
  is(_at[ attribute_class  ],"class","class attribute");
  is(_at[ attribute_id     ],"id","id attribute");
  is(_at[ attribute_method ],"method","method attribute");
  is(_at[ attribute_style  ],"style","style attribute");
  is(_at[ attribute_target ],"target","target attribute");
  is(_at[ attribute_title  ],"title","title attribute");
}

static void render_attr(html5_attribute_type type, char* expect)
{
  leaf_t attr = new_html5_attribute( type );
  text_t result = new_text();
  render_leaf(attr,result);
  is(text_get_text(result),expect,expect);
  delete_leaf(attr);
  delete_text(result);
}

static void render_attrs()
{
  render_attr(attribute_action, "action=\"\"");
  render_attr(attribute_alt, "alt=\"\"");
  render_attr(attribute_class, "class=\"\"");
  render_attr(attribute_id, "id=\"\"");
  render_attr(attribute_method, "method=\"\"");
  render_attr(attribute_style, "style=\"\"");
  render_attr(attribute_target, "target=\"\"");
  render_attr(attribute_title, "title=\"\"");
}

int main(int argv, char** argc)
{
  check_name_def();
  render_attrs();
}
//leaf_t new_html5_attribute(html5_attribute_type);

//void set_html5_attribute_attribute_value(leaf_t, const char*);
