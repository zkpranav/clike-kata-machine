#include <stdio.h>
#include <stdbool.h>

bool linearSearch(int* haystack, int haystackLen, int needle);

int main(int argc, char* argv[]) {
    return 0;
}

bool linearSearch(int* haystack, int haystackLen, int needle) {
    bool status = false;

    for (size_t i = 0; i < haystackLen; i++) {
        if (haystack[i] == needle) {
            status = true;
            break;
        }
    }

    return status;
}