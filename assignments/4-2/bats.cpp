#include "bats.h"

#include <iostream>

using namespace std;

bats::bats(){
  set_percept("You hear wings flapping.");
  set_symbol('b');
}

int bats::encounter(){
  cout << "You enter a room full of spooky scary bats.\n";
  cout << "They carry you away to another room.\n";
  return 1;
}
