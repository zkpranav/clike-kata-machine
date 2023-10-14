#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

size_t length;
struct Node* head;
struct Node* tail;

void prepend(int value);
void append(int value);
void insert_at(int idx, int value);
int get(int idx);
int remove_at(int idx);
int remove_value(int value);

int main(int argc, char* argv[]) {
    length = 0;
    head = NULL;
    tail = NULL;

    return 0;
}

void prepend(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        return;
    }

    length += 1;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (head == NULL) {
        head = node;
        tail = node;
        return;
    }

    node->next = head;
    head->prev = node;
    head = node;
}

void append(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        return;
    }

    length += 1;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (tail == NULL) {
        tail = node;
        head = node;
        return;
    }

    node->prev = tail;
    tail->next = node;
    tail = node;
}

void insert_at(int idx, int value) {
    if (
        idx < 0 ||
        idx > length
    ) {
        return;
    }

    if (idx == 0) {
        return prepend(value);
    }

    if (idx == length) {
        return append(value);
    }

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        return;
    }

    length += 1;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    struct Node* curr = head;
    size_t i = 0;
    while (i < idx - 1) {
        curr = curr->next;
        i += 1;
    }
    node->prev = curr;
    node->next = curr->next;
    curr->next = node;
    node->next->prev = node;
}

int get(int idx) {
    if (
        head == NULL ||
        idx < 0 ||
        idx >= length
    ) {
        return -1;
    }

    struct Node* curr = head;
    size_t i = 0;
    while (i < idx) {
        curr = curr->next;
        i += 1;
    }

    return curr->value;
}

int remove_at(int idx) {
    if (
        head == NULL ||
        idx < 0 ||
        idx >= length
    ) {
        return -1;
    }

    if (idx == 0) {
        struct Node* node = head;
        int ret = head->value;
        head = head->next;
        length -= 1;

        node->next = NULL;
        node->prev = NULL;
        free(node);

        if (head == NULL) {
            tail = NULL;
        }

        return ret;
    }

    if (idx == length - 1) {
        struct Node* node = tail;
        int ret = tail->value;
        tail = tail->prev;
        length -= 1;

        node->next = NULL;
        node->prev = NULL;
        free(node);

        if (tail == NULL) {
            head = NULL;
        }

        return ret;
    }

    struct Node* curr = head;
    size_t i = 0;
    while (i < idx) {
        curr = curr->next;
        i += 1;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    length -= 1;
    int ret = curr->value;

    curr->next = NULL;
    curr->prev = NULL;
    free(curr);

    return ret;
}

int remove_value(int value) {
    if (head == NULL) {
        return -1;
    }

    struct Node* curr = head;
    size_t i = 0;
    while (curr != NULL) {
        if (curr->value == value) {
            return remove_at(i);
        }

        curr = curr->next;
        i += 1;
    }

    return -1;
}

