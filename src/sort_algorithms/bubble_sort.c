#include <stdio.h>

void bubble_sort(int* haystack, int length);

int main(int argc, char* argv[]) {
    return 0;
}

void bubble_sort(int* haystack, int length) {
    if (length == 0) {
        return;
    }

    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < length - 1 - i; j++) {
            if (haystack[j] > haystack[j + 1]) {
                int tmp = haystack[j];
                haystack[j] = haystack[j + 1];
                haystack[j + 1] = tmp;
            }
        }
    }
}