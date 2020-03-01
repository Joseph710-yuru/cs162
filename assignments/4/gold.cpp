/*******************************************************************
file: gold.cpp
description: implementation for gold class
*******************************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

/*******************************************************************
Function: gold::percept()
Description: prints out the hint that the gold horde is in an adjacent room
Parameters: n/a
Pre-Conditions:
Post-Conditions: print "You see a glimmer nearby."
********************************************************************/
void gold::percept(){
 cout << "You see a glimmer nearby." << endl;
}
/*******************************************************************
Function: gold::encounter()
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void gold::encounter(){

}
/*******************************************************************
Function: contains
Description: Returns the type of event
*******************************************************************/
string gold::contain(){
  return "gold";
}
