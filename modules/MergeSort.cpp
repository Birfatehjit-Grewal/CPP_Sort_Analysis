using namespace std;

#include "MergeSort.h"
// Merge two halves using pointers
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temp arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);

    // Merge the temp arrays back into arr
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (*(L + i) <= *(R + j)) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        *(arr + k) = *(L + i);
        i++;
        k++;
    }

    while (j < n2) {
        *(arr + k) = *(R + j);
        j++;
        k++;
    }

    // Clean up
    delete[] L;
    delete[] R;
}

// Recursive Merge Sort
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);        // Sort left half
        mergeSort(arr, mid + 1, right);   // Sort right half

        merge(arr, left, mid, right);     // Merge them
    }
}