
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
  bool result = (0 == strcmp(arg0,arg1));
  if(result) {
    return ok(result,msg);
  }
  else {
	char* moddle = " is not ";
	char* errmsg = (char*) malloc(
		strlen(arg0) + strlen(moddle) + strlen(arg1) + 5);
	sprintf(errmsg,"´%s´%s´%s´",arg0,moddle,arg1);
	ok(result,msg);
	diag(errmsg);
	return result;
  }	
}

void diag(const char* msg)
{
  printf("# %s\n",msg);
}
