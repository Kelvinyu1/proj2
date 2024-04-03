#ifndef MYHEAP_HPP
#define MYHEAP_HPP

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class myHeap {
public:
  // default constructor
  myHeap();
  // will check if this is really needed
  ~myHeap();
  // the function to either insert or pop the median.
  void heapMedian(const std::vector<int> *instructions);

private:
  // max heap contains the integers <= median
  std::priority_queue<int> my_max_heap_;
  // min heap contains integers > median
  std::priority_queue<int, std::vector<int>, std::greater<int>> my_min_heap_;
};

#endif
