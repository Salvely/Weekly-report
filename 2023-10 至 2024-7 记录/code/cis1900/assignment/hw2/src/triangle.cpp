#include "triangle.hpp"
#include <cmath>
#include <iostream>
#include <string>

double triangle::getArea() { return (sqrt(3) / 4) * length * length; }

void triangle::draw() {
  for (int i = 0; i < length; i++) {
    std::cout << std::string(i + 1, '*') << std::endl;
  }
}
