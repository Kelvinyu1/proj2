#include "myVector.hpp"
#include <algorithm>

void vectorMedian(const std::vector<int> *instructions) {
  const auto t1_start = std::chrono::steady_clock::now();
  std::vector<int> median;
  std::vector<int> *myVector_ = new std::vector<int>();
  // iterator for going through instructions
  for (auto it = instructions->begin(); it != instructions->end(); ++it) {
    // if statement for the beginning and to avoid -1 as an edge case
    if (it == instructions->begin() && *it != -1) {
      myVector_->push_back(*it);
    }
    // add the starting iterator + the middle index to erase
    else if (*it == -1) {
      int copy = *(myVector_->begin() + (myVector_->size() - 1) / 2);
      // std::cout << "size: " <<myVector_->size() << std::endl;
      // std::cout << "size index: " << (myVector_->size() - 1) / 2 << std::endl;
      // std::cout << "median: " << copy << std::endl;
      // for (const auto &i : *myVector_) {
        // std::cout << i << ' ';
      // }
      // std::cout << std::endl;
      median.push_back(copy);
      myVector_->erase(myVector_->begin() + (myVector_->size() - 1) / 2);

    }
    // use lower bound to find the correct index. use insert function easy
    else {

      auto low = std::lower_bound(myVector_->begin(), myVector_->end(), *it);
      myVector_->insert(low, *it);
    }
  }

  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();

  // std::cout << "Time to insert and pop medians for Vector: " << t1 << " microseconds" << std::endl;
  for (auto c : median) {
    std::cout << c << " ";
  }
  delete myVector_;
  myVector_ = nullptr;
}
