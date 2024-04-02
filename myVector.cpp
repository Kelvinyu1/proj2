#incldude "myVector.hpp"
#include <algorithm>

myVector::myVector(){
  myVector_ = nullptr;
} 

myVector::~myVector(){
  delete[] myVector_;
  myVector_ = nullptr;
}


void myVector::vectorMedian(const std::vector<int> * instructions){
  for(auto it = instructions.begin(); it != instructions.end(); ++it){
    if (*it = instructions.begin() && *it != -1){
      myvector_.push_back(*it);
      auto low = std::lower_bound(myvector_begin(), myvector.end(), *it);
      myvector_.insert(low, *it);
      }
    else {
      myvector_.erase(myvector_.begin() + floor(myvector_.size() / 2);
    }
      
    
  }
  
  } 
}
