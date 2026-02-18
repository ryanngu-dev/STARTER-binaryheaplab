// heap.cpp
// Ryan Nguyen

#include "heap.h"
#include <iostream>
#include <algorithm>

using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata.assign(start, end);
  int n = static_cast<int>(vdata.size());
  for (int i = n/2-1; i >= 0; i--){
    int current = i;
    while (true) {
      int left = 2 * current + 1;
      int right = 2 * current + 2;
      int smallest = current;

      if (left < n && start[left] < start[smallest]){
        smallest = left;
      }

      if (right < n && start[right] < start[smallest]){
        smallest = right;
      }

      if (smallest == current) break;

      std::swap(start[current], start[smallest] );

      current = smallest;
    }
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int current = vdata.size() - 1;
  while (current > 0 && vdata[current] < vdata[(current-1)/2]){
    std::swap(vdata[current], vdata[(current-1)/2]);
    current = (current-1)/2;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) return;

  if (vdata.size() == 1){
    vdata.erase(vdata.begin());
    return;
  }

  int current = 0;
  vdata[current] = vdata.back();
  vdata.pop_back();

  while (true){
    int left = current * 2 + 1;
    int right = current * 2 + 2;
    int smallest = current;

    if (left < static_cast<int>(vdata.size()) && vdata[left] < vdata[smallest]){
      smallest = left;
    }

    if (right < static_cast<int>(vdata.size()) && vdata[right] < vdata[smallest]){
      smallest = right;
    }

    if (smallest == current) break;

    std::swap(vdata[current], vdata[smallest]);

    current = smallest;
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty()) return -1;
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.empty()){
    return true;
  } else {
    return false;
  }
}
    