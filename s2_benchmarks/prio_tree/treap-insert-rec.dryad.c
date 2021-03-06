#include "stdhipmem.h"



BNode * treap_insert_rec(BNode * x, int k, int p)
/*@
 infer[@shape]
 requires true
 ensures true;
 */
{

  if (x == NULL) {
    BNode * leaf = (BNode *) malloc(sizeof(BNode));

    leaf->key = k;
    leaf->prio = p;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
  } else {

    if (k < x->key) {
      BNode * xr = x->right;
      BNode * xl = x->left;
      BNode * tmp = treap_insert_rec(xl, k, p);

      if (tmp->prio <= x->prio) {

        x->left = tmp;

        return x;
      } else {      
        BNode * lr = tmp->right;

        x->left = lr;

        tmp->right = x;

        return tmp;
      }
    } else {
      BNode * xr = x->right;
      BNode * xl = x->left;
      BNode * tmp = treap_insert_rec(xr, k, p);

      if (tmp->prio <= x->prio) {

        x->right = tmp;

        return x;
      } else {
        BNode * rl = tmp->left;

        x->right = rl;

        tmp->left = x;
        
        return tmp;
      }
    } 
  }
}
