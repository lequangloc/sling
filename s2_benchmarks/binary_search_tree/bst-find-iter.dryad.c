#include "stdhipmem.h"


/*@
HeapPred HX(b_node a, int b).
HeapPred G1(b_node a, b_node b, int g, int h).
*/
BNode * bst_find_iter(BNode * x, int k)
/*@
 infer[@shape]
 requires true
 ensures true;
 */
{
  BNode * curr = x;
  while(curr != NULL)
  /*
   infer[@shape]
   requires true
   ensures true;
   */
    /*@
      infer[HX,G1]
      requires HX(curr, k)
   ensures G1(curr, curr', k, k');
     */
  {
    if (curr->key == k) {
      return curr;
    } else if (k < curr->key) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
  
  return curr;
}

