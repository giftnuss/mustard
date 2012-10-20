
#include <string.h>
#include <tap.h>
#include <stdio.h>

#include <wisper/html5/tags.h>
#include <wisper/html5/tag.h>

#define _en wisper_html_element_name

void check_tag_names()
{ 
  is(_en[ html_a     ],"a","a tag");
  is(_en[ html_address ],"address","address tag");
  is(_en[ html_base  ],"base","base");
  is(_en[ html_body  ],"body","body tag");
  is(_en[ html_br    ],"br","br");
  is(_en[ html_button ],"button","button");
  is(_en[ html_canvas ],"canvas","canvas");
  is(_en[ html_dd    ],"dd","dd");
  is(_en[ html_dfn   ],"dfn","dfn");
  is(_en[ html_div   ],"div","div");
  is(_en[ html_dl    ],"dl","dl");
  is(_en[ html_dt    ],"dt","dt");
  is(_en[ html_fieldset ],"fieldset","fieldset");
  is(_en[ html_form  ],"form","form");
  is(_en[ html_head  ],"head","head");
  is(_en[ html_hr    ],"hr","hr");
  is(_en[ html_html  ],"html","html");
  is(_en[ html_img   ],"img","img");
  is(_en[ html_input ],"input","input");
  is(_en[ html_legend ],"legend","legend");
  is(_en[ html_li    ],"li","li");
  is(_en[ html_link  ],"link","link");
  is(_en[ html_meta  ],"meta","meta");
  is(_en[ html_ol    ],"ol","ol");
  is(_en[ html_optgroup ],"optgroup","optgroup");
  is(_en[ html_option ],"option","option");
  is(_en[ html_ruby  ],"ruby","ruby");
  is(_en[ html_rp    ],"rp","rp");
  is(_en[ html_rt    ],"rt","rt");
  is(_en[ html_script ],"script","script");
  is(_en[ html_select ],"select","select");
  is(_en[ html_span  ],"span","span");
  is(_en[ html_style ],"style","style");
  is(_en[ html_table ],"table","table");
  is(_en[ html_tbody ],"tbody","tbody");
  is(_en[ html_td    ],"td","td");
  is(_en[ html_textarea ],"textarea","textarea");
  is(_en[ html_tfoot ],"tfoot","tfoot");
  is(_en[ html_th    ],"th","th");
  is(_en[ html_tr    ],"tr","tr");
  is(_en[ html_ul    ],"ul","ul");
  is(_en[ html_video ],"video","video");
  is(_en[ html_wbr   ],"wbr","wbr");
}
	

void clean_tag(html5_element_type id,const char* expect)
{
  node_t tag = new_html5_tag(id);
  text_t result = new_text();
  render_node(tag,result);
  is(text_get_text(result),expect,expect);
  delete_node(tag);
  delete_text(result);
}

void class_one(html5_element_type id, const char* expect)
{
  node_t tag = new_html5_tag(id);
  set_html5_attribute(tag,attribute_class,"std");
  text_t result = new_text();
  render_node(tag,result);
  is(text_get_text(result),expect,expect);
  delete_node(tag);
  delete_text(result);
}

void id_one(html5_element_type id, const char* expect)
{
  node_t tag = new_html5_tag(id);
  set_html5_attribute(tag,attribute_id,"slf");
  text_t result = new_text();
  render_node(tag,result);
  is(text_get_text(result),expect,expect);
  delete_node(tag);
  delete_text(result);
}

static void check_clean_tags()
{
  clean_tag(html_a, "<a></a>");
  id_one(html_a,"<a id=\"slf\"></a>");
  class_one(html_a, "<a class=\"std\"></<a>");
  return;
  clean_tag(html_body, "<body></body>");
  class_one(html_body, "<body class=\"std\"></<body>");
  clean_tag(html_br, "<br/>");
  class_one(html_br, "<br class=\"std\"/>");
  clean_tag(html_canvas, "<canvas></canvas>");
  class_one(html_canvas, "<canvas class=\"std\"></<canvas>");
  clean_tag(html_dd, "<dd></dd>");
  class_one(html_dd, "<dd class=\"std\"></<dd>");
  clean_tag(html_dfn, "<dfn></dfn>");
  class_one(html_dfn, "<dfn class=\"std\"></<dfn>");
  clean_tag(html_div, "<div></div>");
  class_one(html_div, "<div class=\"std\"></<div>");
  clean_tag(html_dl, "<dl></dl>");
  class_one(html_dl, "<dl class=\"std\"></<dl>");
  clean_tag(html_dt, "<dt></dt>");	
  class_one(html_dt, "<dt class=\"std\"></<dt>");
  clean_tag(html_form, "<form></form>");
  class_one(html_form, "<form class=\"std\"></<form>");
  clean_tag(html_head, "<head></head>");	
  class_one(html_head, "<head class=\"std\"></<head>");
  clean_tag(html_html, "<html></html>");
  class_one(html_html, "<html class=\"std\"></<html>");
  clean_tag(html_input, "<input/>");
  class_one(html_input, "<input class=\"std\"></<input>");
  clean_tag(html_li, "<li></li>");
  class_one(html_li, "<li class=\"std\"></<li>");
  clean_tag(html_meta, "<meta/>");
  class_one(html_meta, "<meta class=\"std\"></<meta>");
  clean_tag(html_ol, "<ol></ol>");
  class_one(html_ol, "<ol class=\"std\"></<ol>");
  clean_tag(html_option,"<option></option>");
  class_one(html_option, "<option class=\"std\"></<option>");
  clean_tag(html_ruby, "<ruby></ruby>");
  class_one(html_ruby, "<ruby class=\"std\"></<ruby>");
  clean_tag(html_rp, "<rp></rp>");
  clean_tag(html_rt, "<rt></rt>");
  clean_tag(html_script, "<script></script>");
  clean_tag(html_select, "<select></select>");	
  clean_tag(html_span, "<span></span>");	
  clean_tag(html_style, "<style></style>");
  clean_tag(html_textarea, "<textarea></textarea>");
  clean_tag(html_ul, "<ul></ul>");
  clean_tag(html_video, "<video></video>");
  clean_tag(html_wbr, "<wbr/>");
}

int main(int argv, char** argc)
{
  //check_tag_names();
  check_clean_tags();
}
