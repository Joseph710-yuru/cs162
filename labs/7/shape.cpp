#include <string>
#include <iostream>
#include "shape.h"

using namespace std;
/**************************
Constructor for Shape class
***************************/
Shape::Shape(){
  name = "nameless";
  color = "colorless";
}
/**************************
Acessor for private variable name
***************************/
string Shape::get_name(){
  return name;
}
/**************************
Accessor for private variable color
***************************/
string Shape::get_color(){
  return color;
}
/**************************
Mutator for private variable name
***************************/
void Shape::set_name(string a){
  name = a;
}
/**************************
Mutator for private variable color
***************************/
void Shape::set_color(string a){
  color = a;
}
/**************************
Function to return area of shape
***************************/
int Shape::area(){
  return 0;
}

bool Shape::operator< (Shape &a){
  if (this->area() < a.area()) return true;
  else return false;
}
