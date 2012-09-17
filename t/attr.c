
#include <string.h>
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

int main(int argv, char** argc)
{
  check_name_def();
}
//leaf_t new_html5_attribute(html5_attribute_type);

//void set_html5_attribute_attribute_value(leaf_t, const char*);
