

#include <wisper/html5.h>
#include <tap.h>

static void check_clean_doc()
{
   text_t result = new_text();
   html5_document_t doc = new_html5_core_document();
   
   char* expect =
      "<?doctype html?><html><head></head><body></body></html>";
   render_node(doc->document,result);
   is(text_get_text(result),expect,"clean document");
   
   delete_html5_document(doc); 
   delete_text(result);
}



int main()
{
   check_clean_doc();
   
   
}
