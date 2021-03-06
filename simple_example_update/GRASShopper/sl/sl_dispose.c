#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void dispose(Node * lst)
{
  //pre
  Node * curr = NULL;
  while(lst != NULL)
  {
    //loop
    curr = lst;
    lst = lst->next;
    free(curr);
  }
  //post
}

int main(int argc, char * argv[]){
    int size = 0;
    sscanf(argv[1],"%d",&size);
    Node * lst = create_list(size);
    dispose(lst);
    dispose(NULL);
    return 0;
}
