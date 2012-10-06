
#ifndef _WISPER_HTML5_TAGS_H_
# define _WISPER_HTML5_TAGS_H_

enum HtmlElement {
  html_a,
  html_body,
  html_br,
  html_canvas,
  html_dd,
  html_dfn,
  html_div,
  html_dl,
  html_dt,
  html_form,
  html_head,
  html_html,
  html_input,
  html_li,
  html_meta,
  html_ol,
  html_option,
  html_ruby,
  html_rp,
  html_rt,
  html_script,
  html_select,
  html_span,
  html_style,
  html_textarea,
  html_ul,
  html_video,
  html_wbr,
  html_element_count
};

enum HtmlAttribute {
  attribute_action,
  attribute_alt,
  attribute_class,
  attribute_id,
  attribute_method,
  attribute_style,
  attribute_target,
  attribute_title
};

typedef enum HtmlElement html5_element_type;
typedef enum HtmlAttribute html5_attribute_type;

extern char* wisper_html_element_name[];
extern char* wisper_html_attribute_name[];

#endif
