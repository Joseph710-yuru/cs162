#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

#include <iostream>

using namespace std;

int main() {
  Shape one, last;
  Rectangle two;
  Circle three;
  Square four(5);

  cout << "name: " << one.get_name() << " color: " << one.get_color() << endl;
  cout << "name: " << two.get_name() << " color: " << two.get_color() << endl;
  cout << "name: " << three.get_name() << " color: " << three.get_color() << endl;

  two.set_height(2);
  two.set_width(8);
  three.set_radius(5);

  cout << "Area of circle: " << three.area() << endl;
  cout << "Area of rectange: " << two.area() << endl;

  cout << "Square: \n\tWidth: " << four.get_width() << endl;
  cout << "\tHeight: " << four.get_height() << endl;

  cout << "Compare Rectangle to Circle: ";
  if (two < three) {
    cout << "the rectangle is larger than the cirlce\n";
  } else cout << "The circle is larger than the rectangle\n";
  return 0;
}
