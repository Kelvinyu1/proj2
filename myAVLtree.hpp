#ifndef MYAVLTREE_HPP
#define MYAVLTREE_HPP
#include <chrono>
#include <algorithm>
#include <iostream>
#include <vector>

struct AvlNode {
  int element;
  AvlNode *left;
  AvlNode *right;
  int height;

  AvlNode(const int &ele, AvlNode *lt, AvlNode *rt, int h = 0)
      : element{ele}, left{lt}, right{rt}, height{h} {}

  AvlNode(int &&ele, AvlNode *lt, AvlNode *rt, int h = 0)
      : element{std::move(ele)}, left{lt}, right{rt}, height{h} {}
};

int height(AvlNode *t);
void insert(const int &x, AvlNode *&t);
void balance(AvlNode *&t);
void rotateWithLeftChild(AvlNode *& k2);
void rotateWithRightChild(AvlNode *& k2);
void doubleWithLeftChild(AvlNode *& k2);     
void doubleWithRightChild(AvlNode *& k2);
void remove(const int &x, AvlNode *&t);
void rotateWithLeftChild(AvlNode *& k2);
AvlNode *findMin(AvlNode *t);
void treeMedian(const std::vector<int> * instructions); 

#endif 
