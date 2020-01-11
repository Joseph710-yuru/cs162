/******************************************************
** Program: 1.cpp
** Author: Garrett Martin
** Date: 01/08/2020
** Description:
** Input:
** Output:
******************************************************/
#include "header1.h"
#include <fstream>
using namespace std;

int main(){
  user *loser = new user;
  if (get_login(loser)==false) return 0;
  else {
    cout << "User: " << loser.name << endl;
    cout << "User ID: " << loser.id << endl;


}
  delete loser;
  return 0;
}

void get_userid(user *newuser){
  cout << "User ID: ";
  cin << (*newuser).id;

}

void get_password(user *newuser){


}
