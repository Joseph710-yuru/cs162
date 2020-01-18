/******************************************************
** Program: 1.cpp
** Author: Garrett Martin
** Date: 01/08/2020
** Description:
** Input:
** Output:
******************************************************/
#include "header1.h"
#include <string>
#include <fstream>
using namespace std;

int main(){
  user *loser = new user;
  (*loser).id = 19882017;
  (*loser).password = "100pthat1";

  if (check_login(loser)==false) {
    cout << "Error retrieving valid user log in.\n";
    return 0;
  } else {
    cout << "User: " << (*loser).name << endl;
    cout << "User ID: " << (*loser).id << endl;


}
  delete loser;
  return 0;
}

bool check_login(user *newuser){
  ifstream fin;
  string temp_string;
  //get_userid(newuser);
  //get_password(newuser);

// open users.txt and confirm it's open.
  fin.open("users.txt");
  if (!fin.is_open()){
    cout << "Error, unable to open users.txt\n";
    return false;
  }
// extract number of users listed in users.txt, build array
  getline(fin, temp_string, '\n');
  int i=0, accounts_num=stoi(temp_string);
  user *tempuser = new user [accounts_num];
// assign users.txt log in info to separate a users array
  while (i < accounts_num){
    getline(fin, temp_string, ' ');
    tempuser[i].name = temp_string;
    getline(fin, temp_string, ' ');
    tempuser[i].id = stoi(temp_string);
    getline(fin, temp_string, '\n');
    tempuser[i].password = temp_string;
    cout << tempuser[i].name << "\n" << tempuser[i].id << "\n" << tempuser[i].password << "\n";
    i++;
  }
// check if user provided log in is valid
  fin.close();
  if (compare_user(newuser, tempuser, accounts_num)==true) {
    delete [] tempuser; // currently still leaks
    return true;
  } else {
    delete [] tempuser; // currently still leaks
    return false;
  }
}

bool compare_user(user *user1, user *user2, int num){
  for (int i=0; i < num; i++){
    if ((*user1).id == user2 -> id[i]) {
      if ((*user1).password == (*user2) {
        return true;
      }
    }
  }
  return false;
}

void get_userid(user *newuser){
  cout << "User ID: ";
  cin >> (*newuser).id;
}

void get_password(user *newuser){


}
