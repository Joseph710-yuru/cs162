#include "pit.h"

#include <iostream>

using namespace std;

pit::pit(){
  set_percept("You feel a breeze.");
  set_symbol('p');
}

int pit::encounter(){
  cout << "You fall into a deep pit and die.\n";
  cout << "Game Over\n";
  return 3;
}
