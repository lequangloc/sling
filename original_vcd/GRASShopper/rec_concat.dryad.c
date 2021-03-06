// ---- Definitions for GRASShopper examples  ----
#include <vcc.h>
#include <stdlib.h>

typedef
/*D_tag node */
struct node {
  struct node * next;
} Node;

/*D_defs
define pred list^(x): 
  ( 
  ((x l= nil) & emp) | 
          ((x |-> loc next: nxt) * list^(nxt))
  ) ;
  

define relation lseg^(head, tail): 
  ( 
  (((head l= tail) | ((head l= nil) & (tail l= nil))) & emp) | 
          ((head |-> loc next: nxt) * lseg^(nxt, tail))  
  ) 
axiom: ( 
      (list^(tail) -* list^(head)) &
      (((tail |-> loc next: virtual tn) * list^(tn)) -* ((lseg^(head, tn) * list^(tn)))) 
     ) ;
*/

// -----------------------------------------------

_(dryad) 
Node * find_last(Node * a)
  /*D_requires ((~ (a l= nil)) & lseg^(a, nil)) */
  /*D_ensures  (lseg^(a, ret) * (ret |-> loc next: nil)) */
{ 
    if(a->next != NULL) {
      Node * n2 = find_last(a->next);
      return n2;
    } else {
      return a;
    }
} 

_(dryad)
void rec_concat(Node * a, Node * b)
  /*D_requires (((~ (a l= nil)) & lseg^(a, nil)) * (lseg^(b, nil))) */
  /*D_ensures  (lseg^(a, b) * lseg^(b, nil)) */
{
  Node * l = find_last(a);
  l->next = b;
}
