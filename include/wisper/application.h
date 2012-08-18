
#ifndef _WISPER_APPLICATION_H_
# define _WISPER_APPLICATION_H_

struct Application {
	char *name;
	char *version;
	char *home_directory;
};

typedef struct Application application_type;
typedef struct Application* application_t;

application_t new_application(const char* , const char*);

void delete_application(application_t);

#endif
