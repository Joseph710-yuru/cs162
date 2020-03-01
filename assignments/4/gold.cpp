/*******************************************************************
file: gold.cpp
description: implementation for gold class
*******************************************************************/
#include "gold.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function:
Description:
*******************************************************************/
gold::gold(){
  name = "Gold";
}
/*******************************************************************
Function: gold::percept()
Description: prints out the hint that the gold horde is in an adjacent room

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
