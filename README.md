# CPP_Sort_Analysis
This program sorts identical arrays using different sorting algorithms in C++ and benchmarks there run time. The results are stored in `results.txt` in the format `[sort, N, time]` where sort is the type of sort being used, N is the number of elements being sorted and time is the number of  it took to sort the array.

## How to run the code
The code has already been complied using g++ compiler and can be executed by using the command `./Benchmark.o` in a Lunix Terminal.

The repository also includes a **Makefile** that allows you to easily recompile the code by running the command `make` in the terminal. Additionaly, you may chose to do a clean make by first running `make clean` in the terminal to remove all the .o object files and then compileing the code using `make`.

The Benchmark.cpp currently uses N = 1000, 5000, 10000, 20000, 100000, 200000 as the different array sizes but you can change them by editing the following line of code in Benchmark.cpp.
```
int sizes[] = {1000, 5000, 10000, 20000,100000,200000};
```

Make sure to recompile the code after making any changes.

## Results of Sorting Algorithms
**Time in MilliSeconds**

| Sort | N = 1000 | 5000 | 10000 | 20000 | 100000 | 200000 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| Selection | 0 | 15 | 63 | 254 | 6836 | 27579 |
| Insertion | 0 | 2 | 10 | 42 | 1235 | 4648 |
| Heap | 0 | 0 | 0 | 0 | 6 | 12 |
| Merge | 0 | 0 | 0 | 1 | 12 | 17 |