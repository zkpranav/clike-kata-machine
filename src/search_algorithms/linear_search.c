#include <stdio.h>
#include <stdbool.h>

bool linear_Search(int* haystack, int haystack_len, int needle);

int main(int argc, char* argv[]) {
    return 0;
}

bool linear_search(int* haystack, int haystack_len, int needle) {
    bool status = false;

    for (size_t i = 0; i < haystack_len; i++) {
        if (haystack[i] == needle) {
            status = true;
            break;
        }
    }

    return status;
}