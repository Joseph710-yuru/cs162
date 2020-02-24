#include "circle.h"

using namespace std;

Circle::Circle(){
  set_name("new_circle");
  set_color("Yellow-ish");
  radius=0;
}

float Circle::get_radius(){
  return radius;
}

void Circle::set_radius(float a){
  radius = a;
}

float Circle::area(){
  return 3.141 * (radius * radius);
}
