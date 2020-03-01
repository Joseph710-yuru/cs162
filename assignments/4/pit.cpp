/*******************************************************************
file: pit.cpp
description: implementation for pit class
*******************************************************************/
#include "pit.h"

#include <iostream>

using namespace std;

/*******************************************************************
Function: pit::percept()
Description: prints out the hint that a pit is in an adjacent room
********************************************************************/
void pit::percept(){
 cout << "You feel a breeze." << endl;
}
/*******************************************************************
Function: pit::encounter()
Description:

********************************************************************/
void pit::encounter(){

}
/*******************************************************************
Function: contains
Description: Returns the type of event
*******************************************************************/
string pit::contain(){
  return "pit";
}
