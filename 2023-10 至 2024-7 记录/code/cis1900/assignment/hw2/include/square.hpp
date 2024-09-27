#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "shape.hpp"
class square : public shape {
public:
  square() : shape() {}
  square(int l) : shape(l) {}
  double getArea() override;
  void draw() override;
};
#endif