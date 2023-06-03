/*
    Quicksort - A weak sort is performed based on a pivot element, every iteration.
    Every iteration reduces the problem space, by ideally half.
    Time complexity -
    Sort - O(n log(n))
*/

#include <iostream>
#include <cmath>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);

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

    quickSort(arr, 0, arr.size());

    std::cout << "Array after sorting: ";
    for (int i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;    

    return 0;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    size_t counter = low - 1;
    for (size_t i = low; i <= high; i++) {
        if (arr[i] < pivot) {
            counter += 1;
            int temp = arr[i];
            arr[i] = arr[counter];
            arr[counter] = temp;
        }
    }
    counter += 1;
    arr[high] = arr[counter];
    arr[counter] = pivot;

    return counter;
}