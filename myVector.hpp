#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <vector>
#include <iostream> 


class myVector {
  public: 
    myVector(); //default constructor 
    void vectorMedian (const std::vector<int> * instructions); 
  // param: takes in a pointer to a vector of ints 
  // return: none 

  

  private: 
    std::vector<int> * myVector_;
}

#endif
