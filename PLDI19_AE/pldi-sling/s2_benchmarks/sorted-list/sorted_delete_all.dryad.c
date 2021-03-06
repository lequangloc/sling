#include "stdhipmem.h"



SNnode * sorted_delete_all(SNnode * x, int k)
/*@
 infer[@shape]
 requires true
 ensures true;
 */
{	
	if (x == NULL) {
		return x;
	} else if (x->key == k) {
		SNnode * tmp = sorted_delete_all(x->next, k);
		free(x);
		return tmp;
	} else {
		SNnode * tmp = sorted_delete_all(x->next, k);
		x->next = tmp;
		return x;
	}
}

