#include "stdhipmem.h"

/*@
HeapPred HX(node a).
HeapPred HY(node a).
HeapPred H1(node a).
HeapPred H2(node a).
HeapPred H3(node a, node b).
HeapPred H4(node a, node b).
HeapPred G1(node a, node b,node a, node b).
*/


SNnode * reverse_sorted(SNnode * l)
/*
 infer[@shape]
 requires true
 ensures true;
 */
/*@
  //infer[H1,H2]
  //requires H1(x)*H2(y)
  infer[H3]
  requires H3(x,y)
  ensures true;
*/
{
	SNnode * r = NULL;

	while(l != NULL)
    /*
     infer[@shape]
     requires true
     ensures true;
     */
     /*@
     // infer[HX,HY,G1]
    //  requires HX(l)*HY(r)
      infer[H4,G1]
      requires H4(l,r)
      ensures G1(l,l',r,r');
    */
	{
		SNnode * t = l->next;
		
		l->next = r;
		r = l;
		l = t;
	}
	return r;
}

