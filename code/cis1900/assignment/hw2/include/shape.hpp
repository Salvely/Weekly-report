#ifndef __SHAPE_H__
#define __SHAPE_H__
class shape {
protected:
  int length;

public:
  shape(int l);
  shape();
  void setSideLength(int);
  virtual double getArea() = 0;
  virtual void draw() = 0;
};
#endif