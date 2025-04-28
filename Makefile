# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -O2

# Output file
TARGET = Benchmark

# Source files
SRCS = Benchmark.cpp \
       modules/InsertionSort.cpp \
       modules/SelectionSort.cpp \
       modules/HeapSort.cpp \
       modules/MergeSort.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
