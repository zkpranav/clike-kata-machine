#include <stdio.h>
#include <stdlib.h>

int* arr;
size_t capacity;
size_t length;

void* doubleCapacity();
void* halfCapacity();

void prepend(int value);
void append(int value);
void insertAt(int idx, int value);

int main(int argc, char* argv[]) {
    capacity = 4;
    length = 0;
    arr = (int*) malloc(sizeof(int) * 4);
    if (arr == NULL) {
        return 1;
    }

    return 0;
}

void* doubleCapacity(ptr) {
    capacity = capacity * 2;
    return realloc(ptr, sizeof(int) * capacity);
}

void prepend(int value) {
    if (length == capacity) {
        void* ptr = doubleCapacity(arr);
        if (ptr == NULL) {
            return;
        }

        arr = ptr;
    }

    length += 1;
    for (size_t i = length - 1; i > 0; i -= 1) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
}

void append(int value) {
    if (length == capacity) {
        void* ptr = doubleCapacity(arr);
        if (ptr == NULL) {
            return;
        }

        arr = ptr;
    }

    arr[length] = value;
    length += 1;
}

void insertAt(int idx, int value) {
    if (idx < 0 || idx > length) {
        return;
    }

    if (idx == 0) {
        return prepend(value);
    } else if (idx == length) {
        return append(value);
    }

    if (length == capacity) {
        void* ptr = doubleCapacity(arr);
        if (ptr == NULL) {
            return;
        }

        arr = ptr;
    }

    length += 1;
    for (size_t i = length - 1; i > idx; i -= 1) {
        arr[i] == arr[i - 1];
    }

    arr[idx] = value;
}

