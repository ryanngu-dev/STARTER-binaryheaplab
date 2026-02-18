CXX = g++
CXXFLAGS = -Wall -std=c++11

all: examheap

examheap: examheap.o heap.o
	$(CXX) $(CXXFLAGS) examheap.o heap.o -o examheap

examheap.o: examheap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c examheap.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

clean:
	rm -f *.o examheap