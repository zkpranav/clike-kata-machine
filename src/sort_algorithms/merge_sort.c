#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void merge_sort(int* arr, size_t p, size_t r);
void merge(int* arr, size_t p, size_t q, size_t r);

int main(int argc, char* argv[]) {
    
    return 0;
}

// Assume inclusion: [p, r]
void merge_sort(int* arr, size_t p, size_t r) {
    if (p >= r) {
        // Array only has 1 element or invalid
        return;
    }

    // Divide: O(1)
    size_t q = (size_t) floor((p + r) / 2);
    // Conqure : O(log(n))
    // printf("%zu, %zu\n", p, q);
    merge_sort(arr, p, q);
    // printf("%zu, %zu\n", q + 1, r);
    merge_sort(arr, q + 1, r);
    // // Combine: O(n)
    merge(arr, p, q, r);
}

void merge(int* arr, size_t p, size_t q, size_t r) {
    size_t l_arr_len = q - p + 1;
    size_t r_arr_len = r - q;
    int l_arr[l_arr_len];
    int r_arr[r_arr_len];
    size_t i, j, k;

    for (i = 0; i < l_arr_len; ++i) {
        l_arr[i] = arr[p + i];
    }
    for (j = 0; j < r_arr_len; ++j) {
        r_arr[j] = arr[(q + 1) + j];
    }

    k = p;
    i = 0;
    j = 0;
    while (i < l_arr_len && j < r_arr_len) {
        if (l_arr[i] <= r_arr[j]) {
            arr[k] = l_arr[i];
            i += 1;
        } else {
            arr[k] = r_arr[j];
            j += 1;
        }

        k += 1;
    }

    // Only one of the loops below will run
    while (i < l_arr_len) {
        arr[k] = l_arr[i];
        i += 1;
        k += 1;
    }
    while (j < r_arr_len) {
        arr[k] = r_arr[j];
        j += 1;
        k += 1;
    }
}