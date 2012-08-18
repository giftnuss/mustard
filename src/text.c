
#include <stdlib.h>
#include <string.h>

#include <wisper/foundation/text.h>
#include <wisper/exception/memoryerror.h>

static text_t _alloc_self()
{
  text_t self = (text_t) malloc(sizeof(text_type));
  if(self != NULL) {
	  return self;
  }
  memoryerror_exception();
  return (text_t) NULL;
}

static char* _alloc_initial_text(size_t size)
{
  char* text = (char*) malloc(sizeof(char) * size);
  if(text != NULL) {
	text[0] = '\0';
    return text;
  }
  memoryerror_exception();
  return (char*) NULL;	
}

static void _realloc_text(text_t self, size_t size)
{
  char* text = (char*) realloc(self->text, sizeof(char) *size);
  if(text != NULL) {
	self->text = text;
	self->text_bufsize = size;
  }
  else {
	memoryerror_exception();
  }
}

text_t new_text()
{
  int bufsize = 32;
  text_t self = _alloc_self();
  self->text = _alloc_initial_text(bufsize);
  self->text_bufsize = bufsize;
  return self;
}

text_t new_text_with_text(const char* text)
{
  int bufsize = strlen(text) + 1;
  text_t self = _alloc_self();
  self->text = _alloc_initial_text(bufsize);
  strcat(self->text,text);
  self->text_bufsize = bufsize;
  return self;
}

void text_add_text(text_t self, const char* text)
{	
  int need = strlen(self->text) + strlen(text) + 1;
  if(self->text_bufsize < need) {
	_realloc_text(self,need);
  }
  strcat(self->text,text);
}

char* text_get_text(text_t self)
{
  return self->text;
}

void text_dim(text_t self, size_t size)
{
  if(size <= self->text_bufsize) {
	return;
  }
  _realloc_text(self,size);	
}

void delete_text(text_t self)
{
  free(self->text);
  free(self);
}

