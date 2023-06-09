#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};
struct node* head;
struct node* tail;

void enqueue(int value);
int dequeue();
int peek();

int main(int argc, char* argv[]) {
    head = NULL;
    tail = NULL;

    return 0;
}

void enqueue(int value) {
    struct node* n = (struct node*) malloc(sizeof(struct node));
    if (n == NULL) {
        return;
    }

    n->value = value;
    n->next = NULL;

    if (tail == NULL) {
        tail = n;
        head = n;
        return;
    }

    tail->next = n;
    tail = n;
}

int dequeue() {
    if (head == NULL) {
        return -1;
    }

    struct node* n = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }

    n->next = NULL;
    int value = n->value;
    free(n);

    return value;
}

int peek() {
    if (head == NULL) {
        return -1;
    }

    return head->value;
}