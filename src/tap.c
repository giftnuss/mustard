
#include <stdio.h>
#include <string.h>
#include <tap.h>

bool ok(bool condition, const char *msg)
{
  if(condition) {
	printf("ok - %s\n",msg);
  }
  else {
	printf("not ok - %s\n",msg);
  }
  return condition;
}

bool is(const char* arg0, const char* arg1, const char* msg)
{
  return ok(0 == strcmp(arg0,arg1),msg);	
}

void diag(const char* msg)
{
  printf("# %s\n",msg);
}
