#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(){
  set_name("new_rectangle");
  set_color("Red");
  height = 0;
  width = 0;
}
Rectangle::Rectangle(int square){
  set_name("new_square");
  set_color("Square Colored");
  height = square;
  width = square;
}
float Rectangle::get_width(){
  return width;
}
float Rectangle::get_height(){
  return height;
}
void Rectangle::set_width(float a){
  width = a;
}
void Rectangle::set_height(float a){
  height = a;
}
float Rectangle::area(){
  return width * height;
}
