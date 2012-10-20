
#include <wisper/html5.h>


node_t build_html_document_layout()
{
   node_t self = new_node();
   html5_document_t self = alloc_html5_document();
   node_t html = new_html5_tag( html_html );

   self->document = new_html5_doctype();
   self->head = new_html5_tag( html_head );
   self->body = new_html5_tag( html_body );
}
