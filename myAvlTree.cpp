#include "myAvLTree.hpp"

/**
 * Return the height of node t or -1 if nullptr.
 */
int height(AvlNode *t) { return t == nullptr ? -1 : t->height; }

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void insert(const int &x, AvlNode *&t) {
  if (t == nullptr)
    t = new AvlNode{x, nullptr, nullptr};
  else if (x < t->element)
    insert(x, t->left);
  else if (t->element < x)
    insert(x, t->right);

  balance(t);
}

static const int ALLOWED_IMBALANCE = 1;

// Assume t is balanced or within one of being balanced
void balance(AvlNode *&t) {
  if (t == nullptr)
    return;

  if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
    if (height(t->left->left) >= height(t->left->right))
      rotateWithLeftChild(t);
    else
      doubleWithLeftChild(t);
  else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
    if (height(t->right->right) >= height(t->right->left)) {
      rotateWithRightChild(t);
    } else {
      doubleWithRightChild(t);
    }
  }

  t->height = std::max(height(t->left), height(t->right)) + 1;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
void rotateWithLeftChild(AvlNode *&k2) {
  AvlNode *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = std::max(height(k2->left), height(k2->right)) + 1;
  k1->height = std::max(height(k1->left), k2->height) + 1;
  k2 = k1;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
void rotateWithRightChild(AvlNode *&k2) {
  AvlNode *k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  k2->height = std::max(height(k2->right), height(k2->left)) + 1;
  k1->height = std::max(height(k1->right), k2->height) + 1;
  k2 = k1;
}

/**
 * Double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
void doubleWithLeftChild(AvlNode *&k3) {
  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}

/**
 * Double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
void doubleWithRightChild(AvlNode *&k3) {
  rotateWithLeftChild(k3->right);
  rotateWithRightChild(k3);
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void remove(const int &x, AvlNode *&t) {
  if (t == nullptr)
    return; // Item not found; do nothing

  if (x < t->element)
    remove(x, t->left);
  else if (t->element < x)
    remove(x, t->right);
  else if (t->left != nullptr && t->right != nullptr) // Two children
  {
    t->element = findMin(t->right)->element;
    remove(t->element, t->right);
  } else {
    AvlNode *oldNode = t;
    t = (t->left != nullptr) ? t->left : t->right;
    delete oldNode;
  }
  balance(t);
}

AvlNode *findMin(AvlNode *t) {
  if (t == nullptr)
    return nullptr;
  if (t->left == nullptr)
    return t;
  return findMin(t->left);
}

AvlNode *findMax(AvlNode *t) {
  if(t == nullptr)
    return nullptr;
  if(t->right == nullptr)
    return t;
  return findMax(t->right);
}

void treeMedian(const std::vector<int> * instructions){
  AvlNode *max_tree = nullptr;
  AvlNode *min_tree = nullptr;
  int countmax = 0;
  int countmin = 0;
  for(auto it = instructions->begin(); it != instructions->end(); ++it){
    if(max_tree == nullptr && *it != 1){
      insert(*it, max_tree);
      countmax += 1;
    }
    if(*it == -1){
      remove(findMax(max_tree)->element, max_tree);
      countmax -= 1;
    }
    else{
      if (*it < findMax(max_tree)->element){
        insert(*it, max_tree);
        countmax += 1;
        if(countmax > countmin + 1){
          AvlNode *copy = findMax(max_tree);
          remove(findMax(max_tree)->element, max_tree);
          countmax -= 1;
          insert(copy->element, min_tree);
          countmin += 1;
        }
      }
      else if(*it > findMax(max_tree)->element){
        insert(*it, min_tree);
        countmin += 1;
        if(countmin > countmax){
          AvlNode *copy = findMin(min_tree);
          remove(findMin(min_tree)->element, min_tree);
          countmin -= 1;
          insert(copy->element, max_tree);
          countmax += 1;
        }
      }
    }
    
    
  }
} 
