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
  name = "Pit";
  percept = "You feel a breeze.";
}
void set_percept(string p){
  percept = p;
}

/*******************************************************************
Function: pit::percept()
Description: prints out the hint that a pit is in an adjacent room
********************************************************************/
void pit::get_percept(){
 cout percept;
}
/*******************************************************************
Function: pit::encounter()
Description:

********************************************************************/
void pit::encounter(){

}
