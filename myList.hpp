#ifndef MYLIST_HPP
#define MYLIST_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

class myList {
public:
  //default constructor
  myList();
  //destructor
  ~myList();
  //function to pop median and insert integers
  void listMedian(const std::vector<int> * instructions);
private:
  //using the List class and creating a pointer for myList_
  std::list<int> * myList_;
};

#endif
