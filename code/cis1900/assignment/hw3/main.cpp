#include "node.hpp"
#include <iostream>
int main(void) {
  node root(5);
  root.insert(3);
  root.insert(8);
  root.insert(6);
  root.insert(2);

  std::cout << std::boolalpha << root.search(2) << std::endl;
  std::cout << std::boolalpha << root.search(1) << std::endl;
  std::cout << std::boolalpha << root.search(4) << std::endl;
  std::cout << std::boolalpha << root.search(8) << std::endl;
}