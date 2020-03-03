/*******************************************************************
file: bats.cpp
description: implementation for bats class
*******************************************************************/
#include "bats.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function: encounter
Description: default constructor for bats type
********************************************************************/
bats::bats(){
  set_percept("You hear wings flapping.");
  set_symbol('b');
}
/*******************************************************************
Function: encounter
Description: returns the encounter for the bats type
             int is for use in game class
********************************************************************/
int bats::encounter(){
  cout << "You enter a room full of spooky scary bats.\n";
  cout << "They carry you away to another room.\n";
  return 1;
}
