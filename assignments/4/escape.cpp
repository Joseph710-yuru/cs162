#include "escape.h"

#include <iostream>

using namespace std;

escape::escape(){
  set_symbol('e');
}

int escape::encounter(){
  cout << "You enter the room with the escape rope.\n";
  return 5;
}
