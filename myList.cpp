#include "myList.hpp"

//default constructor
myList::myList(){
  myList_ = nullptr;
}

//destructor
myList::~myList(){
  delete[] myList_;
  myList_ = nullptr;
}


void myList::listMedian(const std::vector<int> * instructions){
  //iterator starting and ending for instructions. 
  for(auto it = instructions->begin(); it != instructions->end(); ++it){
    //if the first element or not -1, we can normal insert. 
    if(it == instructions->begin() && *it != -1){
      myList_->push_back(*it);
    }
    /* to pop the median. we grab the index of the median of the list by getting
    the iterator at the beginning, and using the advance function to grab the middle element */ 
    else if(*it == -1){
      auto listit = myList_->begin();
      std::advance(listit, myList_->size() /2 );
      myList_->erase(listit);
    }
    //use lowerbound to find the correct spot of where we should put the index. 
    else{
      auto low = std::lower_bound(myList_->begin(), myList_->end(),*it);
      myList_->insert(low, *it);
    
  }
}
}
