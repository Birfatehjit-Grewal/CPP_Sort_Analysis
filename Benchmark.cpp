#include <fstream>

#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <cstring>
using namespace std;
using namespace std::chrono;

#include "Sorts.h"

void fillRandom(int* arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

int main() {
    ofstream outfile("results.txt");
    if (!outfile) {
        cerr << "Error creating results file.\n";
        return 1;
    }

    int sizes[] = {1000, 5000, 10000, 20000,100000,200000};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);

    //Saves the time in the following format into results.txt
    //[sort, N, time]
    for (int i = 0; i < numTests; i++) {
        const int N = sizes[i];
        int* original = new int[N];
        fillRandom(original, N);

        int* arr1 = new int[N];
        int* arr2 = new int[N];
        int* arr3 = new int[N];
        int* arr4 = new int[N];

        memcpy(arr1, original, N * sizeof(int));
        memcpy(arr2, original, N * sizeof(int));
        memcpy(arr3, original, N * sizeof(int));
        memcpy(arr4, original, N * sizeof(int));

        auto start1 = high_resolution_clock::now();
        insertionSort(arr1, N);
        auto end1 = high_resolution_clock::now();
        outfile << "[insertion, " << N << ", " << duration_cast<milliseconds>(end1 - start1).count() << "]\n";

        auto start2 = high_resolution_clock::now();
        HeapSort(arr2, N);
        auto end2 = high_resolution_clock::now();
        outfile << "[heap, " << N << ", " << duration_cast<milliseconds>(end2 - start2).count() << "]\n";

        auto start3 = high_resolution_clock::now();
        mergeSort(arr3, 0, N - 1);  // fix index
        auto end3 = high_resolution_clock::now();
        outfile << "[merge, " << N << ", " << duration_cast<milliseconds>(end3 - start3).count() << "]\n";

        auto start4 = high_resolution_clock::now();
        selectionSort(arr4, N);
        auto end4 = high_resolution_clock::now();
        outfile << "[selection, " << N << ", " << duration_cast<milliseconds>(end4 - start4).count() << "]\n";

        delete[] original;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;

        cout << "\nCompleted N = " << N << "\n";
    }

    outfile.close();
    cout << "\nResults saved to 'results.txt'\n";
    return 0;
}