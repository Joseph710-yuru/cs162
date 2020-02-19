#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

#include <iostream>

using namespace std;

void print_shape_info(Shape &);

int main() {
  try {
    Shape *shap [3];
    Rectangle rect;
    Circle circ;
    Square squar(5);
  } catch (int a) {
    cout << "Error occured on construction of shape.\n";
  }
  
  rect.set_height(2);
  rect.set_width(8);
  circ.set_radius(5);

  shap[0] = &rect;
  shap[1] = &circ;
  shap[2] = &squar;

  print_shape_info((*shap[0]));
  print_shape_info((*shap[1]));
  print_shape_info((*shap[2]));

  return 0;
}

void print_shape_info(Shape &a){
  cout << "Name: " << a.get_name() << endl;
  cout << "Color: " << a.get_color() << endl;
  cout << "Area: " << a.area() << endl << endl;
}
