#include "myList.hpp"

void listMedian(const std::vector<int> *instructions) {
  const auto t1_start = std::chrono::steady_clock::now();
  std::vector<int> median;
  std::list<int> *myList_ = new std::list<int>();
  // iterator starting and ending for instructions.
  for (auto it = instructions->begin(); it != instructions->end(); ++it) {
    // if the first element or not -1, we can normal insert.
    if (it == instructions->begin() && *it != -1) {
      myList_->push_back(*it);
    }
    /* to pop the median. we grab the index of the median of the list by getting
    the iterator at the beginning, and using the advance function to grab the
    middle element */
    else if (*it == -1) {
      auto listit = myList_->begin();
      std::advance(listit, (myList_->size() - 1) / 2);
      median.push_back(*listit);
      myList_->erase(listit);
    }
    // use lowerbound to find the correct spot of where we should put the index.
    else {
      auto low = std::lower_bound(myList_->begin(), myList_->end(), *it);
      myList_->insert(low, *it);
    }
  }

  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();

  // std::cout << "Time to insert and pop medians for List: " << t1 << " microseconds" << std::endl;
  for (auto c : median) {
    std::cout << c << " ";
  }
  delete myList_;
  myList_ = nullptr;
}
