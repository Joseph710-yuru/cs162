/*******************************************************************
file: pit.cpp
description: implementation for pit class
*******************************************************************/
#include "pit.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function: encounter
Description: default constructor for pit type
********************************************************************/
pit::pit(){
  set_percept("You feel a breeze.");
  set_symbol('p');
}
/*******************************************************************
Function: encounter
Description: returns the encounter for the pit type
             int is for use in game class
********************************************************************/
int pit::encounter(){
  cout << "You fall into a deep pit and die.\n";
  cout << "Game Over\n";
  return 3;
}
