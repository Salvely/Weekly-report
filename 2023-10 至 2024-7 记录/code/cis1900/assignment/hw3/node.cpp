#include "node.hpp"
#include <iostream>

node::node(int val) : val{val} { std::cout << "cons called" << std::endl; }

node::~node() {
  if (this->left != nullptr) {
    this->left->~node();
    delete this->left;
    this->left = nullptr;
  }
  if (this->right != nullptr) {
    this->right->~node();
    delete this->right;
    this->right = nullptr;
  }
  std::cout << "de cons called on " << this->val << std::endl;
}

bool node::search(int i) const {
  bool left_find = false;
  bool right_find = false;
  if (i != this->val) {
    if (this->left != nullptr)
      left_find = this->left->search(i);
    else if (this->right != nullptr)
      right_find = this->right->search(i);
    else {
      return false;
    }
    return left_find || right_find;
  } else {
    return true;
  }
}

void node::insert(int i) {
  if (i < this->val) {
    if (this->left == nullptr) {
      this->left = new node(i);
    } else {
      this->left->insert(i);
    }
  } else if (i > this->val) {
    if (this->right == nullptr) {
      this->right = new node(i);
    } else {
      this->right->insert(i);
    }
  }
}
