#include "myVector.hpp"
#include <algorithm>


void vectorMedian(const std::vector<int> *instructions) {
  std::vector<int> * myVector_;
  // iterator for going through instructions
  for (auto it = instructions->begin(); it != instructions->end(); ++it) {
    // if statement for the beginning and to avoid -1 as an edge case
    if (it == instructions->begin() && *it != -1) {
      myVector_->push_back(*it);
    }
    // add the starting iterator + the middle index to erase
    else if (*it == -1) {
      myVector_->erase(myVector_->begin() + myVector_->size() / 2);

    }
    // use lower bound to find the correct index. use insert function easy
    else {

      auto low = std::lower_bound(myVector_->begin(), myVector_->end(), *it);
      myVector_->insert(low, *it);
    }
  }
}
