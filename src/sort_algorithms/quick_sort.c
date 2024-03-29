#include <stdio.h>

void quick_sort(int* arr, int length);
void _sort(int* arr, int low, int high);
int _partition(int* arr, int low, int high);

int main(int argc, char* argv[]) {
    return 0;
}

void quick_sort(int* arr, int length) {
    if (length == 0 || length == 1) {
        return;
    }

    _sort(arr, 0, length - 1);
}

void _sort(int* arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot_idx = _partition(arr, low, high);
    _sort(arr, low, pivot_idx - 1);
    _sort(arr, pivot_idx + 1, high);
}

int _partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int idx = low - 1;

    for (size_t i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            idx += 1;
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }

    idx += 1;
    arr[high] = arr[idx];
    arr[idx] = pivot;

    return idx;
}
