/*******************************************************************
file: wumpus.cpp
description: implementation for wumpus class
*******************************************************************/
#include "wumpus.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function: wumpus
Description: returns the encounter for the wumpus type
             int is for use in game class
********************************************************************/
wumpus::wumpus(){
  set_percept("You smell a terrible stench.");
  set_symbol('w');
}
/*******************************************************************
Function: encounter
Description: returns the encounter for the escape type
             int is for use in game class
********************************************************************/
int wumpus::encounter(){
  cout << "You enter the same room as the sleeping Wumpus.\n";
  cout << "It awakes in a fury and devours you!\nGame Over.\n";
  return 3;
}
