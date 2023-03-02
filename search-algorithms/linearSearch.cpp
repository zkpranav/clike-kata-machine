#include <iostream>
#include <vector>

bool linearSearch(std::vector<int>& haystack, int needle);

int main(int argc, char* argv[]) {
    std::vector<int> haystack;
    haystack.push_back(1);
    haystack.push_back(2);
    haystack.push_back(69);
    haystack.push_back(3);
    haystack.push_back(420);
    
    int needle;
    std::cout << "Enter a value to search: ";
    std::cin >> needle;

    bool res = linearSearch(haystack, needle);
    res?
        std::cout << "Value found" << std::endl:
        std::cout << "Value not found" << std::endl;
    return 0;
}

bool linearSearch(std::vector<int>& haystack, int needle) {
    for (const auto& i: haystack) {
        if (i == needle) {
            return true;
        }
    }

    return false;
}