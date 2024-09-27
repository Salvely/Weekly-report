#include "square.hpp"
#include "triangle.hpp"
#include <iostream>

int main(void) {
  std::cout << "Initialize a square" << std::endl;
  square sq(5);
  std::cout << "The area of the square is " << sq.getArea() << std::endl;
  sq.draw();
  std::cout << "Initialize a triangle" << std::endl;
  triangle tri(3);
  std::cout << "The area of the square is " << tri.getArea() << std::endl;
  tri.draw();

  std::cout << "Initialize a default square" << std::endl;
  square sq1;
  std::cout << "The area of the square is " << sq1.getArea() << std::endl;
  sq1.draw();
  std::cout << "Initialize a default triangle" << std::endl;
  triangle tri1;
  std::cout << "The area of the square is " << tri1.getArea() << std::endl;
  tri1.draw();
}