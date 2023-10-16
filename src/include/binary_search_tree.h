#ifndef _BST_H_
#define _BST_H_

#include "binary_node.h"
#include <stdbool.h>

/*
 * Symbol table implementation of a BST.
 * Left node <= root and right node > root.
 * BST implementation is not self balancing.
 * 
 * Implements Hibbard's approach for deletion.
 * 
 * Time complexities -
 * search - O(log(n)) to O(h)
 * insert - O(log(n)) to O(h)
 * remove - O(log(n)) to O(h)
 * where,
 * n -> # of nodes
 * h -> tree height
 */
struct binary_search_tree {
    struct binary_node *root;
};

/* Initialize and cleanup a BST */
struct binary_search_tree* bst_init(void);
/* Requires BST to be empty */
void bst_cleanup(struct binary_search_tree *bst);

bool bst_isempty(struct binary_search_tree *bst);

void bst_insert(struct binary_search_tree *bst, int value);
bool bst_search(struct binary_search_tree *bst, int value);
void bst_remove(struct binary_search_tree *bst, int value);

#endif /* _BST_H_ */