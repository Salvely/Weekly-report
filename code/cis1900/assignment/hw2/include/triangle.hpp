#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include "shape.hpp"
class triangle : public shape {
public:
  triangle() : shape() {}
  triangle(int l) : shape(l) {}
  double getArea() override;
  void draw() override;
};

#endif