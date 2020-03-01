/*******************************************************************
file: wumpus.cpp
description: implementation for wumpus class
*******************************************************************/
#include "wumpus.h"

#include <iostream>
#include <string>

using namespace std;

/*******************************************************************
Function:
Description:
********************************************************************/
wumpus::wumpus(){
 set_name("wumpus");
 set_percept("You smell a great stench.");
 alive = true;
}
/*******************************************************************
Function: wumpus::encounter()
Description:
********************************************************************/
int wumpus::encounter(){
 cout << "The Wumpus wakes up and eats you!\nGame over.\n";
 return 3;
}
/*******************************************************************
Function: wumpus::kill()
Description: You killed the wumpus, good job
********************************************************************/
void wumpus::kill(){
  cout << "The arrow pierces the Wumpus' heart and kills the monster.\n";
}
/*******************************************************************
Function: wumpus::wake_up()
Description:
********************************************************************/
bool wumpus::wake_up(){
  return true;
}
