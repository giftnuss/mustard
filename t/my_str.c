
#include <string.h>
#include <tap.h>

#include <wisper/my.h>

int main(int argv, char** argc)
{
  is(my_str_join("/","ab","cd",0),"ab/cd","join 2 args");
  is(my_str_join("/",0),"","join 0 args");
  is(my_str_join("/","ab",0),"ab/","join 1 arg");
  is(my_str_join("/","ab","cd","ef",0),"ab/cd/ef","join 3 args");
  return 0;
}
