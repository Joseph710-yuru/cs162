#include "wumpus.h"

#include <iostream>

using namespace std;

wumpus::wumpus(){
  set_percept("You smell a terrible stench.");
  set_symbol('w');
}

int wumpus::encounter(){
  cout << "You enter the same room as the sleeping Wumpus.\n";
  cout << "It awakes in a fury and devours you!\nGame Over.\n";
  return 3;
}
