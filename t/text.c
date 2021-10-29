
#include <string.h>
#include <tap.h>

#include <wisper/foundation/text.h>

int test_text()
{
  {
    text_t t0 = new_text();
    is(text_get_text(t0),"","empty string");
    delete_text(t0);
  }

  {
    text_t t1 = new_text();
    text_add_text(t1,"test");
    is(text_get_text(t1),"test","test string");
    text_add_text(t1," more");
    is(text_get_text(t1),"test more","test more string");
    delete_text(t1);
  }

  {
    text_t t2 = new_text_with_text("starter");
    is(text_get_text(t2),"starter","start with string");
    delete_text(t2);
  }

  return 0;
}

#ifndef TEST_LIB
  int main(int argv, char** argc)
  {
    test_text();
    return 0;
  }
#endif

