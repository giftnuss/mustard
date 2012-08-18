
#ifndef _WISPER_FOUNDATION_TEXT_H_
# define _WISPER_FOUNDATION_TEXT_H_

#include <stdlib.h>

struct Text {
  char* text;
  int text_bufsize;
};

typedef struct Text text_type;
typedef struct Text* text_t;

text_t new_text();

text_t new_text_with_text(const char*);

void text_add_text(text_t, const char*);

char* text_get_text(text_t);

void text_dim(text_t, size_t);
 
void delete_text(text_t);

#endif
