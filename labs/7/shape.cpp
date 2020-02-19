#include <string>
#include <iostream>
#include "shape.h"

using namespace std;
/**************************
Constructor for Shape class
***************************/
Shape::Shape(){
  try {
    name = "nameless";
    color = "colorless";
  } catch (int a) {
    cout << "Error occured on construction of shape.\n";
  }
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
float Shape::area(){
  return 0;
}

bool Shape::operator< (Shape &a){
  if (this->area() < a.area()) return true;
  else return false;
}
