#include <stdlib.h> // for malloc & free
#include <stdbool.h>
#include <assert.h>
#include "../include/binary_search_tree.h"

struct binary_search_tree* bst_init(void) {
    struct binary_search_tree *bst = malloc(sizeof(*bst));
    if (bst == NULL) {
        return NULL;
    }

    bst->root = NULL;
}

void bst_cleanup(struct binary_search_tree *bst) {
    assert(bst != NULL);
    assert(bst->root == NULL);
    free(bst);
}

bool bst_isempty(struct binary_search_tree *bst) {
    assert(bst != NULL);
    return (bst->root == NULL);
}

////////////////////////////////////////////////////////////////
/* Internal */
static void bst_insert_rec(struct binary_node* node, struct binary_node* insert_node) {
    assert(node != NULL);
    assert(insert_node != NULL);

    if (insert_node->value <= node->value) {
        if (node->left != NULL) {
            bst_insert_rec(node->left, insert_node);
        } else {
            node->left = insert_node;
        }
    } else {
        if (node->right != NULL) {
            bst_insert_rec(node->right, insert_node);
        } else {
            node->right = insert_node;
        }
    }
}

static struct binary_node* bst_find(struct binary_node *node, int needle) {
    assert(node != NULL);

    struct binary_node *ret = NULL;
    do {
        if (needle == node->value) {
            ret = node;
        } else if (needle < node->value) {
            node = node->left;
        } else {
            node = node->right;
        }
    } while (node != NULL);

    return ret;
}

////////////////////////////////////////////////////////////////
/* Public */
void bst_insert(struct binary_search_tree *bst, int value) {
    assert(bst != NULL);

    struct binary_node *node = malloc(sizeof(*node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    if (bst->root == NULL) {
        bst->root = node;
    } else {
        bst_insert_rec(bst->root, node);
    }
}

bool bst_search(struct binary_search_tree *bst, int value) {
    assert(bst != NULL);
    assert(bst->root != NULL);

    struct binary_node *node = bst_find(bst->root, value);
    if (node == NULL) {
        return false;
    } else {
        return true;
    }
}

