
#include <stdlib.h>
#include <stdio.h>

#include <wisper/html5.h>

struct NamedChar {
	int codepoint;
	char* name;
};

typedef struct NamedChar named_char_type;
typedef struct NamedChar* named_char_t;

/*
 * The list is taken from the book "Songs for the butcher's daughter"
 * by Peter Manseau.
 */
static named_char_type alefbeys_list[] = {
	{ 1488, "alef" },
	{ 1489, "beys" },
	{ 1490, "giml" },
	{ 1491, "daled" },
	{ 1492, "hey" },
	{ 1493, "vov" },
	{ 1494, "zayen" },
	{ 1495, "khes" },
	{ 1496, "tes" },
	{ 1497, "yud" },
	{ 1499, "khof" },
	{ 1500, "lamed" },
	{ 1502, "mem" },
	{ 1504, "nun" },
	{ 1505, "samekh" },
	{ 1506, "ayen" },
	{ 1508, "pey" },
	{ 1510, "tsadik" },
	{ 1511, "kof" },
	{ 1512, "reysch" },
	{ 1513, "schin" },
	{ 1514, "tof" },
	{ 0, NULL }
};

static node_t alefbeys()
{
    node_t wrapper = new_html5_tag( html_div );
    int c = 0;
    char buf[16];
    named_char_type letter = alefbeys_list[c]; 
    while( letter.codepoint > 0 ) {
	    node_t ruby = new_html5_tag( html_ruby );
	    node_t rt = new_html5_tag( html_rt );
	    node_t rp_left = new_html5_tag( html_rp );
	    node_t rp_right = new_html5_tag( html_rp );
	    
	    add_node( rp_left, new_textnode_with_text("(") );
	    add_node( rp_right, new_textnode_with_text(")") );
	    add_node( rt, new_textnode_with_text( letter.name ) );
	    
	    sprintf(buf,"&#x%x;", letter.codepoint );
	    add_node( ruby, new_textnode_with_text(buf) );
	    add_node( ruby, rp_left );
	    add_node( ruby, rt );
	    add_node( ruby, rp_right );
	    
	    add_node( wrapper, ruby );
	    add_node( wrapper, new_textnode_with_text(" "));
	    ++c;
	    letter = alefbeys_list[c];
	}
	return wrapper;
}

int main()
{
   text_t result = new_text();
   html5_document_t doc = new_html5_core_document();
   add_node(doc->body,alefbeys());

   render_node(doc->document,result);
   printf("%s\n",text_get_text(result));
   
   delete_html5_document(doc);
   delete_text(result);
   
   return 0;
}

