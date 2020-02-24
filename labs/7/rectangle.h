#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
  private:
    float width;
    float height;

  public:
    Rectangle();
    Rectangle(int);
    float get_width();
    float get_height();
    void set_width(float);
    void set_height(float);
    float area();
};

#endif
