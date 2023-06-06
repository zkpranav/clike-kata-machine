#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* prev;
};
struct node* head;

void push(int value);
int pop();
int peek();

int main(int argc, char* argv[]) {
    head = NULL;
    return 0;
}

void push(int value) {
    struct node* n = (struct node*) malloc(sizeof(struct node));

    if (n == NULL) {
        return;
    }

    n->value = value;
    n->prev = head;
    head = n;
}

int pop() {
    if (head == NULL) {
        return -1;
    }

    struct node* n = head;
    int tmp = n->value;
    head = head->prev;
    n->prev = NULL;
    free(n);

    return tmp;
}

int peek() {
    if (head == NULL) {
        return -1;
    }

    return head->value;
}