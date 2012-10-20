
#include <wisper/foundation/list_of_nodes.h>
#include <wisper/foundation/node.h>
#include <wisper/exception/memoryerror.h>
#include <wisper/exception/invalidindex.h>

/**
 * @todo
 * - check int boundary
 */

static nodelist_t _alloc_self()
{
  nodelist_t self = (nodelist_t) malloc(sizeof(nodelist_type)); 
  if(self != NULL) {
	  return self;
  }
  memoryerror_exception();
  return (nodelist_t) NULL;
}

static node_t* _alloc_data
    (
        node_t* buf, /* real nodelist buffer */
        int current_size, /* current allocated nodecount */
        int* new_size /* new size */
    )
{
  if(*new_size <= current_size) {
      if(current_size == 0) {       *new_size =   4; }
      else if(current_size < 5) {   *new_size =   9; }
      else if(current_size < 10) {  *new_size =  35; }
      else if(current_size < 128) { *new_size = 128; }
      else { *new_size += 128; }
  }
  buf = (node_t*) realloc((void *)buf, *new_size * sizeof(node_t));
  if(buf != NULL) {
	  return buf;
  }
  memoryerror_exception();
  return (node_t*) NULL;
}

nodelist_t new_list_of_nodes()
{
  nodelist_t list = _alloc_self();
  int bufsize = 0;

  list->list = _alloc_data(NULL, 0, &bufsize);
  list->buffersize = bufsize;
  list->used = 0;
  return list;  
}

void dim_list_of_nodes(nodelist_t list, size_t newsize)
{
	
}

void insert_into_list_of_nodes(nodelist_t list, size_t idx, node_t node)
{
	
}

void add_to_list_of_nodes(nodelist_t list, node_t node)
{
  if(list->used == list->buffersize) {
    list->list = _alloc_data(list->list, list->used, &list->buffersize);
  }
  list->list[list->used] = node;
  list->used++;
}

node_t get_from_list_of_nodes(nodelist_t list, size_t idx)
{
  if(idx >= list->used) {
    invalidindex_exception();
    return (node_t) NULL;
  }
  return list->list[idx];
}

void render_list_of_nodes(nodelist_t self, text_t result)
{
  int cnt = 0, end = self->used;
  for(; cnt < end; ++cnt) {
	render_node(self->list[cnt],result);  
  }
}

void free_list_of_nodes(nodelist_t list)
{
  int cnt = list->used - 1;
  for(; cnt >= 0; cnt--) {
    delete_node(list->list[cnt]);
  }
  free(list->list);
  free(list);
}
