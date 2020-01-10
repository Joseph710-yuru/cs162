/******************************************************
** Program: 1.cpp
** Author: Garrett Martin
** Date: 01/08/2020
** Description:
** Input:
** Output:
******************************************************/
#include "header1.h"

int main(){
  user *loser = new user;

  delete loser;
  return 0;
}

bool get_login(user *newuser){
  int fail=0, repeat=0, uvalid=0, pvalid=0;
  if (fail < 3){

  } else if (fail >= 3){
    cout << "Too many failed attempts to log in";
    return false;
  }
}

void get_username(user *newuser){
  cout << "User ID: ";
  cin << (*newuser).user;

}

void get_password(user *newuser){


}
