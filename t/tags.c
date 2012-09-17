
#include <string.h>
#include <tap.h>
#include <stdio.h>

#include <wisper/html5/tags.h>
#include <wisper/html5/tag.h>

#define _en wisper_html_element_name

void clean_tag(html5_element_type id,const char* expect)
{
  node_t tag = new_html5_tag(id);
  text_t result = new_text();
  render_node(tag,result);
  is(text_get_text(result),expect,expect);
  delete_node(tag);
}

static void check_clean_tags()
{
  clean_tag(html_a, "<a></a>");	
  clean_tag(html_body, "<body></body>");	
  clean_tag(html_br, "<br/>");
  clean_tag(html_canvas, "<canvas></canvas>");
  clean_tag(html_div, "<div></div>");	
  clean_tag(html_head, "<head></head>");	
  clean_tag(html_html, "<html></html>");
  clean_tag(html_meta, "<meta/>");
  clean_tag(html_ruby, "<ruby></ruby>");
  clean_tag(html_rp, "<rp></rp>");
  clean_tag(html_rt, "<rt></rt>");
  clean_tag(html_script, "<script></script>");	
  clean_tag(html_span, "<span></span>");	
  clean_tag(html_style, "<style></style>");
  clean_tag(html_video, "<video></video>");
  clean_tag(html_wbr, "<wbr/>");
}

int main(int argv, char** argc)
{
  is(_en[ html_a     ],"a","a tag");
  is(_en[ html_body  ],"body","body tag");
  is(_en[ html_br    ],"br","br");
  is(_en[ html_canvas ],"canvas","canvas");
  is(_en[ html_div   ],"div","div");
  is(_en[ html_head  ],"head","head");
  is(_en[ html_html  ],"html","html");
  is(_en[ html_meta  ],"meta","meta");
  is(_en[ html_ruby  ],"ruby","ruby");
  is(_en[ html_rp    ],"rp","rp");
  is(_en[ html_rt    ],"rt","rt");
  is(_en[ html_script ],"script","script");
  is(_en[ html_span  ],"span","span");
  is(_en[ html_style ],"style","style");
  is(_en[ html_video ],"video","video");
  is(_en[ html_wbr   ],"wbr","wbr");
  
  check_clean_tags();
}