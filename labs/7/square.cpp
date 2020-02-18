#include "square.h"

using namespace std;

Square::Square(){
  set_width(0);
  set_height(get_width());
}

Square::Square(int a){
  set_width(a);
  set_height(a);
}
