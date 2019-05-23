
/*
 * HIP/SLEEK standard library for C program
 * 
 * Created: Oct. 31, 2013.
 */

//do not use typedef, S2 has not supported it yet
typedef
/*D_tag node */
struct node {
   int key;
   struct node * next;
} Node;

void* malloc(int size) __attribute__ ((noreturn))
/*@
  case {
    size <= 0 -> requires true ensures res = null;
    size >  0 -> requires true ensures res::memLoc<h,s> & (res != null) & h;
  }
*/;

//wrong spec here
Node * split(Node * x)
 /*@
    requires x::lseg<_>
    ensures res::lseg<x>;
*/
;

// the spec looks weird
Node * merge(Node * a, Node * b) 
  /*@
    requires a::lseg<_> * b::lseg<_>
    ensures res::lseg<a>;
*/
;

void free(Node * p) __attribute__ ((noreturn))
/*@
 requires p::memLoc<h,s> ensures p = null;
*/;

struct GList {
  int key;
  struct GList* prev;
  struct GList* next;
};


/*@ lseg<p> == emp & self=p 
   or self::node<_,n> * n::lseg<p> & self!=null; */


int random()
/*@
  requires true
  ensures true;
*/;
