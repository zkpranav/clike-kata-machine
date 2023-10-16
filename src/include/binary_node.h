#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_

/*
 * Binary node with left and right links set to NULL as terminal values.
 * 
 * Extend the value field to be a void* (A satellite value).
 * Extend the definition to include a count per node.
 */
struct binary_node {
    int value;
    struct binary_node *left;
    struct binary_node *right;
};

#endif /* _BINARY_NODE_H_ */