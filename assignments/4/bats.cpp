/*******************************************************************
file: bats.cpp
description: implementation for bats class
*******************************************************************/
#include "bats.h"

#include <iostream>

using namespace std;

/*******************************************************************
Function: bats::percept()
Description: prints out the hint that bats are in an adjacent room
********************************************************************/
void bats::percept(){
  cout << "You hear wings flapping.\n";
}
/*******************************************************************
Function:
Description:
********************************************************************/
void bats::encounter(){

}
/*******************************************************************
Function: contain
Description: Returns the type of event
*******************************************************************/
string bats::contain(){
  return "bats";
}
