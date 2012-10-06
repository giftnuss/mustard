
#ifndef _WISPER_HTML5_DOCUMENT_H_
# define _WISPER_HTML5_DOCUMENT_H_

#include <wisper/foundation/node.h>

struct Html5Document {
    node_t document;
    node_t head;
    node_t body;
};

typedef struct Html5Document html5_document_type;
typedef struct Html5Document* html5_document_t;

node_t new_html5_doctype();

html5_document_t new_html5_core_document();

void delete_html5_document(html5_document_t); 

#endif

