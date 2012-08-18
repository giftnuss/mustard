
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include <wisper/my.h>
#include <wisper/application.h>
#include <wisper/exception/memoryerror.h>

static char* _default_home_directory()
{
  char* home_dir = NULL;
  struct passwd *pwent;
  uid_t uid = getuid();
  if( (pwent=getpwuid(uid)) != NULL) {
    home_dir = pwent->pw_dir;
  }
  return home_dir;
}

static application_t _alloc_application()
{
  application_t self = (application_t) malloc(sizeof(application_type));
  if(self != NULL) {
    return self;
  }
  memoryerror_exception();
  return (application_t) NULL;
}

application_t new_application(const char* name, const char* version)
{
  application_t self = _alloc_application();
  self->name = my_str(name);
  self->version = my_str(version);
  self->home_directory = _default_home_directory();
  return self;
}

void delete_application(application_t self)
{
  free(self->home_directory);
  free(self->version);
  free(self->name);
  free(self);
}


