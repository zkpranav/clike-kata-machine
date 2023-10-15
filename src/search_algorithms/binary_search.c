#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool binary_search(int* haystack, int haystack_len, int needle);

int main(int argc, char* argv[]) {
    return 0;
}

bool binary_search(int* haystack, int haystack_len, int needle) {
    int low = 0;
    int high = haystack_len;
    bool status = false;

    while (low < high) {
        int mid = (int) floor(low + (high - low) / 2);
        int value = haystack[mid];

        if (needle == value) {
            status = true;
            break;
        } else if (needle < value) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return status;
}