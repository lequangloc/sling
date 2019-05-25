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


SNnode * sll_reverse(SNnode * x)
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
	SNnode * y = NULL;
        SNnode * tmp = NULL;
	while (x != NULL)
    /*
     infer[@shape]
     requires true
     ensures true;
     */
      /*@
     // infer[HX,HY,G1]
    //  requires HX(x)*HY(y)
      infer[H4,G1]
      requires H4(x,y)
      ensures G1(x,x',y,y');
    */
	{
		tmp = x->next;
		x->next = y;
		y = x;
		x = tmp;
	}
	return y;
}
