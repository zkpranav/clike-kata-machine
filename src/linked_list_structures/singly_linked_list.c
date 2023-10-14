#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* head;
size_t length;

void prepend(int value);
void append(int value);
void insert_at(int idx, int value);
int get_at(int idx);
int remove_at(int idx);
int remove_value(int value);

int main(int argc, char* argv[]) {
    head = NULL;
    length = 0;

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

    if (head == NULL) {
        head = node;
        return;
    }

    node->next = head;
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

    if (head == NULL) {
        head = node;
        return;
    }

    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = node;
}

void insert_at(int idx, int value) {
    if (idx < 0 || idx > length) {
        return;
    } else if (idx == length) {
        return append(value);
    } else if (idx == 0) {
        return prepend(value);
    }

    struct Node* curr = head;
    size_t i = 0;
    while (true) {
        if (i == (idx - 1)) {
            break;
        }

        curr = curr->next;
        i += 1;
    }

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        return;
    }

    length += 1;
    node->value = value;
    node->next = curr->next;
    curr->next = node;
}

int get_at(int idx) {
    if (
        head == NULL ||
        idx < 0 ||
        idx >= length
    ) {
        return -1;
    }

    struct Node* curr = head;
    size_t i = 0;
    while (true) {
        if (i == idx) {
            break;
        }

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
        int ret = node->value;

        head = head->next;
        length -= 1;

        node->next = NULL;
        free(node);
        return ret;
    }
    
    struct Node* curr = head;
    size_t i = 0;
    while (true) {
        if (i == (idx - 1)) {
            break;
        }

        curr = curr->next;
        i += 1;
    }

    struct Node* node = curr->next;
    int ret = node->value;

    length -= 1;
    curr = curr->next->next;

    node->next = NULL;
    free(node);
    return ret;
}

int remove_value(int value) {
    if (head == NULL) {
        return -1;
    }

    struct Node* curr = head;
    size_t i = 0;
    do {
        if (curr->value == value) {
            return remove_at(i);
        }

        curr = curr->next;
        i += 1;
    } while (curr->next);

    return -1;
}