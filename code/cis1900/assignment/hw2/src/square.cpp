#include "square.hpp"
#include <iostream>
#include <string>

double square::getArea() { return length * length; }

void square::draw() {
  for (int i = 0; i < length; i++)
    std::cout << std::string(5, '*') << std::endl;
}
