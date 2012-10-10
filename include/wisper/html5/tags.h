
#ifndef _WISPER_HTML5_TAGS_H_
# define _WISPER_HTML5_TAGS_H_

enum HtmlElement {
  html_a,
  html_address,
  html_base,
  html_body,
  html_br,
  html_button,
  html_canvas,
  html_dd,
  html_dfn,
  html_div,
  html_dl,
  html_dt,
  html_fieldset,
  html_form,
  html_head,
  html_hr,
  html_html,
  html_img,
  html_input,
  html_legend,
  html_li,
  html_link,
  html_meta,
  html_ol,
  html_optgroup,
  html_option,
  html_ruby,
  html_rp,
  html_rt,
  html_script,
  html_select,
  html_span,
  html_style,
  html_table,
  html_tbody,
  html_td,
  html_textarea,
  html_tfoot,
  html_th,
  html_title,
  html_tr,
  html_ul,
  html_video,
  html_wbr,
  html_element_count
};

enum HtmlAttribute {
  attribute_action,
  attribute_alt,
  attribute_charset,
  attribute_class,
  attribute_dir,
  attribute_disabled,
  attribute_href,
  attribute_id,
  attribute_lang,
  attribute_method,
  attribute_name,
  attribute_readonly,
  attribute_rel,
  attribute_rev,
  attribute_src,
  attribute_style,
  attribute_tabindex,
  attribute_target,
  attribute_title,
  attribute_type
};

typedef enum HtmlElement html5_element_type;
typedef enum HtmlAttribute html5_attribute_type;

extern char* wisper_html_element_name[];
extern char* wisper_html_attribute_name[];

#endif
