
#include <wisper/html5/document.h>
#include <wisper/html5/tag.h>
#include <wisper/foundation/textnode.h>

#include <wisper/exception/memoryerror.h>

#include <stdlib.h>

node_t new_html5_doctype()
{
   return new_textnode_with_text("<?doctype html?>");
}

static html5_document_t alloc_html5_document()
{
   html5_document_t self = (html5_document_t) malloc(sizeof(*self));
   if(self != NULL) {
      return self;	   
   }	
   memoryerror_exception();
   return (html5_document_t) NULL;
}

html5_document_t new_html5_core_document()
{
   html5_document_t self = alloc_html5_document();
   node_t html = new_html5_tag( html_html );

   self->document = new_html5_doctype();
   self->head = new_html5_tag( html_head );
   self->body = new_html5_tag( html_body );
   
   add_node(self->document, html);
   add_node(html, self->head);
   add_node(html, self->body);
   
   return self;
}

void delete_html5_document(html5_document_t doc)
{
   	delete_node(doc->document);
   	free(doc);
} 

