/*******************************************************************
file: pit.cpp
description: implementation for pit class
*******************************************************************/
#include "pit.h"

#include <iostream>
#include <string>

using namespace std;

/*******************************************************************
Function:
Description:
*******************************************************************/
pit::pit(){
  set_name("Pit");
  set_percept("You feel a breeze.");
}
/*******************************************************************
Function: pit::encounter()
Description:

********************************************************************/
int pit::encounter(){
  cout << "You fall into a large pit and die.\n";
  return 3;
}
