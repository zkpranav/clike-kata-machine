// Best case: O(n)
// Worst case: O(n^2)
// Technique: Incremental
// Loop invariant: subarray a[0: i] contains the same elements, and is always sorted.

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* records, size_t length);

int main(int argc, char* argv[]) {
    

    return 0;
}

void insertion_sort(int* records, size_t length) {
    if (length <= 0) {
        return;
    }

    for (size_t i = 1; i < length; ++i) {
        int key = records[i];
        size_t j = i - 1;
        for (; j >= 0; --j) {
            if (records[j] > key) {
                records[j + 1] = records[j];
            } else {
                break;
            }
        }

        records[j + 1] = key;
    }
}

