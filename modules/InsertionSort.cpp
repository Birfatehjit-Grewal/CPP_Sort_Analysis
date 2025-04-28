#include <iostream>
using namespace std;

#include "InsertionSort.h"

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = *(arr + i);       // current element
        int j = i - 1;

        // Shift elements that are greater than key
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }

        // Insert the key at the correct location
        *(arr + j + 1) = key;
    }
}