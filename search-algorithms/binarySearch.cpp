#include <iostream>
#include <vector>
#include <cmath>

bool binarySearch(std::vector<int>& haystack, int needle);

int main(int argc, char* argv[]) {
    std::vector<int> haystack;
    haystack.push_back(0);
    haystack.push_back(1);
    haystack.push_back(5);
    haystack.push_back(69);
    haystack.push_back(72);
    haystack.push_back(420);
    haystack.push_back(1000);

    int needle;
    std::cout << "Enter a value to search: ";
    std::cin >> needle;

    bool res = binarySearch(haystack, needle);
    res?
        std::cout << "Value found" << std::endl:
        std::cout << "Value not found" << std::endl;

    return 0;
}

bool binarySearch(std::vector<int>& haystack, int needle) {
    int low = 0;
    int high = haystack.size();

    while(low < high) {
        int mid = floor(low + (high - low) / 2);
        
        if (haystack[mid] == needle) {
            return true;
        } else if (haystack[mid] < needle) {
            low = mid + 1;
        } else  {
            high = mid;
        }
    }

    return false;
}