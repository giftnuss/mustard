
#ifndef _WISPER_HTML5_H_
# define _WISPER_HTML5_H_

#include <wisper/html5/tags.h>
#include <wisper/html5/tag.h>
#include <wisper/html5/document.h>

#include <wisper/foundation/textnode.h>

enum 
{
	HTML_DOCUMENT,
	HTML_DOCUMNT_HTML,
	HTML_DOCUMENT_HEAD,
	HTML_DOCUMENT_BODY
};

node_t build_html_document_layout();

#endif
