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
 set_ent(3);
}
/*******************************************************************
Function: wumpus::encounter()
Description:
********************************************************************/
void wumpus::encounter(){
 cout << "The Wumpus wakes up and eats you!\nGame over.\n";
}
