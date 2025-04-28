#include <algorithm>
#include <iostream>
using namespace std;

#include "HeapSort.h"

// Heapify a subtree rooted at index i using pointers
void heapify(int* arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child is larger than root
    if (left < n && *(arr + left) > *(arr + largest))
        largest = left;

    // If right child is larger than largest so far
    if (right < n && *(arr + right) > *(arr + largest))
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(*(arr + i), *(arr + largest));
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Main function to perform Heap Sort
void HeapSort(int* arr, int n) {
    // Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(*(arr), *(arr + i));  // Move current root to end
        heapify(arr, i, 0);        // Call heapify on the reduced heap
    }
}

