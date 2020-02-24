/*******************************************************************
file: wumpus.cpp
description: implementation for wumpus class
*******************************************************************/
#include "wumpus.h"

#include <iostream>

using namespace std;

/*******************************************************************
Function: wumpus::percept()
Description: prints out the hint that the wumpus is in an adjacent room
Parameters: n/a
Pre-Conditions:
Post-Conditions: print "You smell a terrible stench."
********************************************************************/
void wumpus::percept(){
 cout << "You smell a terrible stench." << endl;
}
/*******************************************************************
Function: wumpus::encounter()
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void wumpus::encounter(){
 cout << "The Wumpus wakes up and eats you!\nGame over.\n";
}
/*******************************************************************
Function: wumpus::kill()
Description: You killed the wumpus, good job
Parameters:
Pre-Conditions:
Post-Conditions: print "The arrow pierces the Wumpus' heart
                 and kills the monster"
********************************************************************/
void wumpus::kill(){
  cout << "The arrow pierces the Wumpus' heart and kills the monster.\n";
}
/*******************************************************************
Function: wumpus::wake_up()
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
bool wumpus::wake_up(){
  return true;
}
