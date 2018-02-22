#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct b_node {
  struct b_node * left;
  struct b_node * right;
  int key;
} BNode;

BNode * create_tree(int size);
BNode * bst_remove_root(BNode * x);
BNode * find_smallest(BNode * x);
BNode * bst_delete_rec(BNode * x, int k);
int bst_find_rec(BNode * x, int k);
BNode * bst_insert_rec(BNode * x, int k);
BNode * bst_remove_root_rec(BNode * x);
BNode * bst_find_iter(BNode * x, int k);

#endif