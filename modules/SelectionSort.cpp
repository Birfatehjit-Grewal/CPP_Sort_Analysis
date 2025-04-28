#include <iostream>
using namespace std;
#include "SelectionSort.h"
// Function to perform Selection Sort using pointers
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int* minPtr = arr + i;

        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) < *minPtr) {
                minPtr = arr + j;
            }
        }

        if (minPtr != arr + i) {
            // Swap using pointers
            int temp = *(arr + i);
            *(arr + i) = *minPtr;
            *minPtr = temp;
        }
    }
}

