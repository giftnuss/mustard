
#include <string.h>
#include <stdio.h>
#include <tap.h>

#include <wisper/foundation.h>

static void check_new_nodelist(int bfs, int u)
{
	char msg[20];
    nodelist_t nl = new_list_of_nodes(bfs);
    snprintf(msg,20,"buffersize == %d",bfs);
    ok(nl->buffersize == bfs,msg);
    snprintf(msg,20,"used == %d",u);
    ok(nl->used == 0,msg);
    ok(nl->list != NULL,"buffer allocated");
    free_list_of_nodes(nl);
} 

int main(int argv, char** argc)
{
  {
    check_new_nodelist(0,0);
    check_new_nodelist(1,1);
    check_new_nodelist(2,2);
    check_new_nodelist(3,3);
    check_new_nodelist(4,4);
    check_new_nodelist(5,5);
    check_new_nodelist(10,10);
    check_new_nodelist(100,100);
    check_new_nodelist(1000,1000);
  } 

  return 0;
}

/*
struct ListOfNodes {
  int buffersize;
  int used;
  struct Node** list;
};

void add_to_list_of_nodes(nodelist_t, struct Node*);

struct Node* get_from_list_of_nodes(nodelist_t, size_t);

void render_list_of_nodes(nodelist_t, text_t result);

void free_list_of_nodes(nodelist_t);
*/
