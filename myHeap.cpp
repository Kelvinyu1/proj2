#include "myHeap.hpp"
#include <cstdint>


// param: vector<int> instructions. called as a pointer
void heapMedian(const std::vector<int> *instructions) {
  
  // max heap contains the integers <= median
  std::priority_queue<int> my_max_heap_;
  // min heap contains integers > median
  std::priority_queue<int, std::vector<int>, std::greater<int>> my_min_heap_;
  // iterator: starts from the beginning of the vector to the end.
  for (auto it = instructions->begin(); it != instructions->end(); ++it) {
    /* if empty and not -1, we add. mainly for inserting the first element from
    instructions
    or for edge cases where -1 could be the first or second element in
    instructions */
    if (my_max_heap_.size() == 0 && *it != -1) {
      my_max_heap_.push(*it);

    }
    /* we pop here. however, if the min heap size is greater than the max heap,
    there is an inbalance. remove the top of the min heap and move it to the max
    heap make sure to pop so that we can */
    else if (*it == -1) {
      my_max_heap_.pop();
      if (my_min_heap_.size() > my_max_heap_.size()) {
        auto heapy = my_min_heap_.top();
        my_min_heap_.pop();
        my_max_heap_.push(heapy);
      }
    }
    /* do insert here. there a couple different cases. similar to the max heap
    size > min heap size, if min heap size is greater than the max heap size +
    1, we need to do the opposite*/
    else {
      if (*it > my_max_heap_.top()) {
        my_min_heap_.push(*it);
        if (my_min_heap_.size() > my_max_heap_.size()) {

          auto heapy = my_min_heap_.top();
          my_min_heap_.pop();
          my_max_heap_.push(heapy);
        }
      } else {
        my_max_heap_.push(*it);
        if (my_max_heap_.size() > my_min_heap_.size() + 1) {
          auto heapyjeepy = my_max_heap_.top();
          my_max_heap_.pop();
          my_min_heap_.push(heapyjeepy);
        }
      }
    }
  }
}
