#include <iostream>
#include <string>
#include "player.h"

using namespace std;
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player::player(){
  name = "Computer";
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player::~player(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
const hand player::get_hand(){
  return h;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
const string player::get_name(){
  return name;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void player::set_hand(){

}
/*******************************************************************
Function: set_name()
Description: mutator for name member variable
Parameters: string n
Pre-Conditions: accepts string as parameter
Post-Conditions: value of name is changed to the value of n
********************************************************************/
void player::set_name(string n){
  name = n;
}
