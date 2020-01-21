/******************************************************
** Program: 1.cpp
** Author: Garrett Martin
** Date: 01/08/2020
** Description: a program to sort user transactions three ways and
                then maybe write them
** Input: two command line arguments for two different text files
** Output: sorted transactions printed to terminal or written to a file
******************************************************/
#include "header1.h"
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
  user *loser = new user;
  int repeat=1, selection=-1, users, id;
  ifstream fin;
  string ufile, bfile;
// bunch of checks to make sure we ain't just gon' quit on out.
  if (check_args(argc, argv, ufile, bfile) != 1) return 0;
  if (check_login(loser, users, ufile)==false) {
    cout << "Should've provided a good log in.\n";
    delete loser;
    return 0;
  }
  if (check_filenames(ufile,bfile)==false) return 0;
// brief celebration
  cout << "Log in for ID: " << (*loser).id << " successful!\n";
// write budget data to budget data type array
  fin.open(bfile);
  budget *budgy = create_budgets(users);
  get_budget_data(budgy, users, fin);
  fin.close();
  id = get_budget_index(budgy, loser, users);
// main program stuff here
  while (repeat==1){
    cout << "Welcome, " << (*loser).name << endl;
    cout << "Your current balance is: $" << budgy[id].balance << endl;
    print_options();
    get_int_range(selection, 1, 4);
    select_option(budgy, selection, repeat, id);
  }
// delete and close
//  delete_info(&loser, &budgy, users);
// still a leaky ship and it causes an abrupt error
  return 0;
}
