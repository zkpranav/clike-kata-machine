#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void mergeSort(int* arr, size_t p, size_t r);
void merge(int* arr, size_t p, size_t q, size_t r);

int main(int argc, char* argv[]) {
    
    return 0;
}

// Assume inclusion: [p, r]
void mergeSort(int* arr, size_t p, size_t r) {
    if (p >= r) {
        // Array only has 1 element or invalid
        return;
    }

    // Divide: O(1)
    size_t q = (size_t) floor((p + r) / 2);
    // Conqure : O(log(n))
    // printf("%zu, %zu\n", p, q);
    mergeSort(arr, p, q);
    // printf("%zu, %zu\n", q + 1, r);
    mergeSort(arr, q + 1, r);
    // // Combine: O(n)
    merge(arr, p, q, r);
}

void merge(int* arr, size_t p, size_t q, size_t r) {
    size_t lArrlength = q - p + 1;
    size_t rArrLength = r - q;
    int lArr[lArrlength];
    int rArr[rArrLength];
    size_t i, j, k;

    for (i = 0; i < lArrlength; ++i) {
        lArr[i] = arr[p + i];
    }
    for (j = 0; j < rArrLength; ++j) {
        rArr[j] = arr[(q + 1) + j];
    }

    k = p;
    i = 0;
    j = 0;
    while (i < lArrlength && j < rArrLength) {
        if (lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i += 1;
        } else {
            arr[k] = rArr[j];
            j += 1;
        }

        k += 1;
    }

    // Only one of the loops below will run
    while (i < lArrlength) {
        arr[k] = lArr[i];
        i += 1;
        k += 1;
    }
    while (j < rArrLength) {
        arr[k] = rArr[j];
        j += 1;
        k += 1;
    }
}