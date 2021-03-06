// ---- Definitions for glib/gslist examples  ----
#include <vcc.h>
#include <stdlib.h>

typedef
/*D_tag node */
struct node {
  int key;
  struct node * next;
} Node;

/*D_defs 
define pred list^(x): 
  ( 
  ((x l= nil) & emp) | 
  ((x |-> loc next: nxt; int key: ky) * list^(nxt))
  )
  axiom: (lseg^(x, x) * (      ((x l= nil) & (length^(x) i= 0)) 
                          | ((~ (x l= nil)) & (0 < length^(x)))
                        )
          );
  

define set-fun keys^(x):
  (case (x l= nil): emptyset;
   case ((x |-> loc next: nxt; int key: ky) * true): 
    ((singleton ky) union keys^(nxt));
   default: emptyset
  ) ;

define int-fun length^(x):
  (case (x l= nil): 0;
   case ((x |-> loc next: nxt; int key: ky) * true): 
    (1 + length^(nxt));
   default: 0
  ) ;

define relation lseg^(head, tail): 
  ( 
     (((head l= tail) | ((head l= nil) & (tail l= nil))) & emp) 
    | ((head |-> loc next: nxt; int key: ky) * lseg^(nxt, tail))  
  ) 
axiom: ( 
  ((((head l= tail) => (emp & ((lseg-length^(head, tail) i= 0) 
                            & (lseg-keys^(head, tail) s= emptyset)))) 
    &
    ((tail l= nil) => (list^(head) & ((length^(head) i= lseg-length^(head, tail)) 
                          & (keys^(head) s= lseg-keys^(head, tail)))))) 
     &
    (list^(tail) -* (list^(head) & 
                     ((keys^(head) s= (lseg-keys^(head, tail) union keys^(tail))) 
                     & (length^(head) i= (lseg-length^(head, tail) + length^(tail))))))
  ) 
  &          
  (((tail |-> loc next: virtual tn; int key: virtual tk) 
     * list^(tn)) 
       -* ((lseg^(head, tn) & 
           ((lseg-keys^(head, tn) s= (lseg-keys^(head, tail) union (singleton tk))) & 
            (lseg-length^(head, tn) i= (lseg-length^(head, tail) + 1))) ) 
         * list^(tn)))
     ) ;

define bin-set-fun lseg-keys^(head, tail):
  (case ((head l= tail) | ((head l= nil) & (tail l= nil))) : emptyset;
   case ((head |-> loc next: nxt; int key: ky) * true): 
    ((singleton ky) union lseg-keys^(nxt, tail));
   default: emptyset
  ) ;

define bin-int-fun lseg-length^(head, tail):
  (case (head l= tail) : 0;
   case ((head |-> loc next: nxt; int key: ky) * true): 
    (1 + lseg-length^(nxt, tail));
   default: 0
  ) ;
*/
// ------------------------------------------------

_(dryad)
Node * g_slist_last(Node * list)
  /*D_requires list^(list) */
  /*D_ensures ((list^(old(list)) & (old(keys^(list)) s= keys^(old(list)))) & (((old(list) l= nil) => (ret l= nil)) &
                       ((~ (old(list) l= nil)) => (lseg^(old(list), ret) 
                                              * ((ret |-> loc next: temp; int key: kx) & (temp l= nil)))))) */
{

  if (list != NULL) 
  {
    while(list->next != NULL) 
      /*D_invariant (((~ (old(list) l= nil)) & (list^(old(list)) & (old(keys^(list)) s= keys^(old(list))))) 
                      & (lseg^(old(list), list) * ((list |-> loc next: temp; int key: kx) * list^(temp)))) */
    {
      list = list->next;
    }
   
  }
  return list;
}
