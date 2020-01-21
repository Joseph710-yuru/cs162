#include <iostream>
#include <string>
#include "header1.h"

using namespace std;

/*******************************************************************
Function: create_budgets()
Description: allocates memory for a new array of type budgets
Parameters: int num
Pre-Conditions: takes a num as a parameter
Post-Conditions: returns a budget array
********************************************************************/
budget* create_budgets(int num){
  budget *budgy = new budget [num];
  return budgy;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void get_budget_data(budget* budgy, int users, ifstream &fin){
  int budget_num, trans_num;
  string temp_string;

  getline(fin, temp_string, '\n');
  budget_num = stoi(temp_string);

  for (int i=0; i < budget_num; i++){
    getline(fin, temp_string, ' ');
    budgy[i].id = stoi(temp_string);
    getline(fin, temp_string, ' ');
    budgy[i].balance = stof(temp_string);
    getline(fin, temp_string, '\n');
    budgy[i].num_transactions = stoi(temp_string);
    budgy[i].t = create_transactions(budgy[i].num_transactions);
    get_transaction_data(budgy[i].t, budgy[i].num_transactions, fin);
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
transaction* create_transactions(int num){
  transaction *tranny = new transaction [num];
  return tranny;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void get_transaction_data(transaction* tranny, int num_transactions, ifstream &fin){
  string temp_string;
  for (int i=0;i<num_transactions;i++){
    getline(fin, temp_string, ' ');
    (*tranny).date = temp_string;
    getline(fin, temp_string, ' ');
    (*tranny).amount = stof(temp_string);
    getline(fin, temp_string, ' ');
    (*tranny).description = temp_string;
    getline(fin, temp_string, '\n');
    (*tranny).category = temp_string;
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void delete_info(user**, int, budget**, int){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
bool compare_user(user *user1, user *user2, int num){
  for (int i=0; i < num; i++){
    if ((*user1).id == user2[i].id) {
      if ((*user1).password == user2[i].password) {
        (*user1).name  = user2[i].name;
        return true;
      }
    }
  }
  return false;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void get_userid(user *newuser){
  cout << "User ID: ";
  cin >> (*newuser).id;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void get_password(user *newuser){
  cout << "Password: ";
  cin >> (*newuser).password;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
bool check_login(user *newuser, int &accounts_num){
  ifstream fin;
  string temp_string;
  int fail=0;
// open users.txt and confirm it's open.
  fin.open("users.txt");
  if (!fin.is_open()){
    cout << "Error, unable to open users.txt\n";
    return false;
  }
// assign the user data to an array to compare against
  getline(fin, temp_string, '\n');
  accounts_num=stoi(temp_string);

  user *tempuser = new user [accounts_num];

  get_user_data(tempuser, accounts_num, fin);
// check if user provided log in is valid
  fin.close();
  while(fail<3){
    get_userid(newuser);
    get_password(newuser);
    if (compare_user(newuser, tempuser, accounts_num)==true) {
      delete [] tempuser; // currently still leaks
      return true;
    } else {
      fail += 1;
      if (fail < 3){
        cout << "Invalid log in provided.\nYou have " << 3-fail << " attempts left\n";
      }
    }
  }
  delete [] tempuser;
  return false;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void get_user_data(user* tempuser, int num, ifstream& fin){
  int i=0;
  string temp_string;

  while (i < num){
    getline(fin, temp_string, ' ');
    tempuser[i].name = temp_string;
    getline(fin, temp_string, ' ');
    tempuser[i].id = stoi(temp_string);
    getline(fin, temp_string, '\n');
    tempuser[i].password = temp_string;
    i++;
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void print_options() {
  cout << "Please select from the following options:\n";
  cout << "\t(1) Sort transactions by category\n";
  cout << "\t(2) Sort transactions by date\n";
  cout << "\t(3) Sort transactions by dollar amount\n";
  cout << "\t(4) Quit program\n";
  cout << "Option: ";
}
/****************************************************************************
Function: check_range()
Description: Determines if a value lay within a certain range
Parameters: int test_value, int lower_bound, int upper_bound
Pre-Conditions: Take three integers
Post-Conditions: Return true if test_value is between upper and lower bound
***************************************************************************/
bool check_range(int test_value, int lower_bound, int upper_bound) {
  if (upper_bound >= test_value && lower_bound <= test_value) {
    return true;
  } else {
    return false;
  }
}
/****************************************************************************
Function: is_int()
Description: Indicates if a given string is an integer
Parameters: string num
Pre-Conditions: take string
Post-Conditions: Return true if string value is within range of integers
***************************************************************************/
bool is_int(int num) {
  for (int i=0; i < num; ++i) {
    if (num >= 48 && num <= 57) {
      return true;
    }
  }
}
/****************************************************************************
Function: get_int()
Description: Takes a ref int as a parameter, has user assign it and checks if that
             bad boi is a real int or not then assigns that value to the ref.
Parameters: int &num
Pre-Conditions: takes integer variable as parameter
Post-Conditions: returns provided integer
***************************************************************************/
void get_int(int &num) {
  int repeat = 1;

  cin >> num;

  while (repeat == 1) {
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000000000,'\n');
      cout << "\tERROR: Non-Integer Input\nInput an integer: ";
      cin >> num;
    } else {
      repeat = 0;
    }
  }
}
/****************************************************************************
Function: get_int_range()
Description: Takes a ref int as a parameter, has user assign it and checks if that
             bad boi is a real int or not then assigns that value to the ref.
             also checks range.
Parameters: int &num
Pre-Conditions: takes integer variable as parameter
Post-Conditions: returns provided integer, so long as it's within range
***************************************************************************/
void get_int_range(int &num, int lower, int upper) {
  int temp=-1;
  while(check_range(temp, lower, upper)==false){
    if (temp != -1){
      cout << "Invalid input, try again: ";
    }
    get_int(temp);
    num = temp;
  }
}
/*******************************************************************
Function: select_option()
Description: built this explicitly to reduce line-count in main(), it just
             prints the options the user can make
Parameters: int selection, int &repeat
Pre-Conditions: takes an int and a reference to an int as parameters
Post-Conditions: prints a bunch of junk and maybe signals the program to quit
********************************************************************/
void select_option(int selection, int &repeat) {
  if (selection == 1){
    cout << "1\n";
    //category_sort()
  } else if (selection == 2) {
    cout << "2\n";
    //date_sort()
  } else if (selection == 3) {
    cout << "3\n";
    //dollar_sort()
  } else if (selection == 4) {
    repeat = 0;
  } else {
    cout << "Try again, ding dong\n";
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
int get_budget_index(budget *budgy, user *loser, int users){
  for (int i=0; i < users; i++){
    if (budgy[i].id == (*loser).id) {
      return i;
    }
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
