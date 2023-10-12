#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool binarySearch(int* haystack, int haystackLen, int needle);

int main(int argc, char* argv[]) {
    return 0;
}

bool binarySearch(int* haystack, int haystackLen, int needle) {
    int low = 0;
    int high = haystackLen;
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