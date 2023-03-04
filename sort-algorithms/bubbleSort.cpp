/*
    Bubble sort - Bubble the largest element of the set to the top on every iteration
    Time complexity -
    Search - O(n^2)
*/

#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr);

int main(int argc, char* argv[]) {
    std::vector<int> arr;
    arr.push_back(87);
    arr.push_back(2);
    arr.push_back(69);
    arr.push_back(11);
    arr.push_back(420);
    arr.push_back(-1000);
    arr.push_back(0);

    std::cout << "Array before sorting: ";
    for (int i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);

    std::cout << "Array after sorting: ";
    for (int i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;    

    return 0;
}

void bubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}