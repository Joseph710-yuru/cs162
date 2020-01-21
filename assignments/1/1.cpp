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
  int repeat=1, selection=-1, users=0, id;
  ifstream fin;
  //(*loser).id = 19882017;
  //(*loser).password = "100pthat1";

  if (check_login(loser, users)==false) {
    cout << "Should've provided a good log in.\n";
    delete loser;
    return 0;
  }

  cout << "Log in for ID: " << (*loser).id << " successful!\n";

// write budget data to budget data type array
  fin.open("budgets.txt");
  budget *budgy = create_budgets(users);
  get_budget_data(budgy, users, fin);
  fin.close();
  id = get_budget_index(budgy, loser, users);
  while (repeat==1){
    cout << "Welcome, " << (*loser).name << endl;
    cout << "Your current balance is: $" << budgy[id].balance << endl;
    print_options();
    get_int_range(selection, 1, 4);
    select_option(selection, repeat);
  }

  delete budgy;
  delete loser;
  return 0;
}
