#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int g_list_position(DLNode * list, DLNode * link)
{
  //pre
  int i;
  i = 0;
  while(list != NULL)
  {
      //loop
    if (list == link) {
        //post
      return i;
    }
    i ++;
    list = list->next;
  }
  //post
  return -1;
}

int main(int argc, char * argv[]){
    int size = 0;
    sscanf(argv[1],"%d", &size);
    DLNode * hd = create_list(size);
    DLNode * list_node = hd->next->next;
    int res = g_list_position(hd, list_node);
    g_list_position(NULL, list_node);
    return 0;
}
