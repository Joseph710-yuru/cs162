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
    tranny[i].date = temp_string;
    getline(fin, temp_string, ' ');
    tranny[i].amount = stof(temp_string);
    getline(fin, temp_string, ' ');
    tranny[i].description = temp_string;
    getline(fin, temp_string, '\n');
    tranny[i].category = temp_string;
  }
}
/*******************************************************************
Function: delete_info()
Description: frees all allocated memory not previously deleted
Parameters: user**, budget**, int
Pre-Conditions:
Post-Conditions: so much free memory.
********************************************************************/
void delete_info(user** loser, budget** budgy, int users){
  delete [] loser;
  for (int i=0; i < users; i++){
    for (int j=0; j < budgy[i] -> num_transactions; j++){
//      delete [] budgy[i] -> t[j];
    }
    delete [] budgy[i] -> t;
    delete [] budgy[i];
  }
  delete [] budgy;
}
/*******************************************************************
Function: compare_user()
Description: compares two users, sort of
Parameters: user*, user *, int
Pre-Conditions:
Post-Conditions: return true if users are same, false if not
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
Function: get_userid()
Description: prompts for user id and stores for later use
Parameters: user *
Pre-Conditions: pointer of type user provided as parameter
Post-Conditions: user id stored in a user struct for later use
********************************************************************/
void get_userid(user *newuser){
  cout << "User ID: ";
  cin >> (*newuser).id;
}
/*******************************************************************
Function: get_password()
Description: prompts user for password and then stores for later use
Parameters: user *
Pre-Conditions: takes a pointer of type user as parameter
Post-Conditions: stores password in a user struct for later use
********************************************************************/
void get_password(user *newuser){
  cout << "Password: ";
  cin >> (*newuser).password;
}
/*******************************************************************
Function: check_login()
Description: checks user provided user info against user file info
Parameters: user *, int &, string
Pre-Conditions:
Post-Conditions: either user is authenticated and we gucci or they're
                 not, and results in program termination
********************************************************************/
bool check_login(user *newuser, int &accounts_num, string file){
  ifstream fin;
  string temp_string;
  int fail=0;
// open users.txt and confirm it's open.
  fin.open(file);
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
Function: get_user_data()
Description: assigns all users in user file to a temporary user type to compare
             against.
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
Function: print_options()
Description: just prints all the program options to terminal
Parameters: n/a
Pre-Conditions:
Post-Conditions: prints all the program options to terminal
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
void select_option(budget *budgy, int selection, int &repeat, int id) {
  if (selection == 1){
    category_sort(budgy, id);
  } else if (selection == 2) {
    date_sort(budgy, id);
  } else if (selection == 3) {
    dollar_sort(budgy, id);
  } else if (selection == 4) {
    repeat = 0;
  } else {
    cout << "Try again, ding dong\n";
  }
}
/*******************************************************************
Function: get_budget_index()
Description: gets the specific index for the current user in the budget array
Parameters: budget *, user *, int
Pre-Conditions: accepts those parameters
Post-Conditions: returns budget index that corresponds to current user
********************************************************************/
int get_budget_index(budget *budgy, user *loser, int users){
  for (int i=0; i < users; i++){
    if (budgy[i].id == (*loser).id) {
      return i;
    }
  }
}
/*******************************************************************
Function: swap()
Description: swaps transactions
Parameters: transaction *, transaction *
Pre-Conditions: accepts two transactions
Post-Conditions: swaps the location of both transactions
********************************************************************/
void swap(transaction *a, transaction *b)
{
    transaction temp = *a;
    *a = *b;
    *b = temp;
}
/*******************************************************************
Function: dollarsorter()
Description: sorts transactions by dollar amount
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: all user transactions sorted by dollar amount
********************************************************************/
void dollarsorter(transaction *t, int n){
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < n-i-1; j++){
      if (t[j].amount > t[j+1].amount){
        swap(&t[j], &t[j+1]);
      }
    }
  }
}
/*******************************************************************
Function: dollar_sort()
Description: handles set up for dollarsorter() and whether user wants to print
Parameters: budget *, int
Pre-Conditions:
Post-Conditions: dollars get sorted things get printed.
********************************************************************/
void dollar_sort(budget *budgy, int id){
  int select;
  string doc;

  dollarsorter(budgy[id].t, budgy[id].num_transactions);
  cout << "Print options:\n\t(1) Print to terminal\n\t(2) Write to document\n";
  cout << "Option: ";
  get_int_range(select, 1, 2);

  if (select==1){
    print_trans(budgy[id].t, budgy[id].num_transactions);
  } else if (select==2){
    write_to_doc(budgy[id].t, budgy[id].num_transactions);
  }
}
/*******************************************************************
Function: category_sort()
Description: handles the set up for categorysorter() and whether user wants to print
Parameters: budget *, int
Pre-Conditions:
Post-Conditions: categories get sorted, things get printed
********************************************************************/
void category_sort(budget *budgy, int id){
  int select;
  string doc;

  categorysorter(budgy[id].t, budgy[id].num_transactions);
  cout << "Print options:\n\t(1) Print to terminal\n\t(2) Write to document\n";
  cout << "Option: ";
  get_int_range(select, 1, 2);

  if (select==1){
    print_trans(budgy[id].t, budgy[id].num_transactions);
  } else if (select==2){
    write_to_doc(budgy[id].t, budgy[id].num_transactions);
  }
}
/*******************************************************************
Function: categorysorter()
Description: sorts transactions by category
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: sorts all them transactions in alphabetical order by category
********************************************************************/
void categorysorter(transaction *t, int n){
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < n-i-1; j++){
      if (t[j].category.at(0) > t[j+1].category.at(0)){
        swap(&t[j], &t[j+1]);
      }
    }
  }
}
/*******************************************************************
Function: date_sort()
Description: handles the set up for datesorter() and whether user wants to print
Parameters: budget *, int
Pre-Conditions:
Post-Conditions: dates get sorted, things get printed
********************************************************************/
void date_sort(budget *budgy, int id){
  int select;
  string doc;

  datesorter(budgy[id].t, budgy[id].num_transactions);
  cout << "Print options:\n\t(1) Print to terminal\n\t(2) Write to document\n";
  cout << "Option: ";
  get_int_range(select, 1, 2);

  if (select==1){
    print_trans(budgy[id].t, budgy[id].num_transactions);
  } else if (select==2){
    write_to_doc(budgy[id].t, budgy[id].num_transactions);
  }
}
/*******************************************************************
Function: datesorter()
Description: sorts transactions by date
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: dates r sorted
********************************************************************/
void datesorter(transaction *t, int n){
  string temp1, temp2;
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < n-i-1; j++){
      temp1 = t[j].date.substr(6,9) + t[j].date.substr(3,4) + t[j].date.substr(0,1);
      cout << temp1 << endl;
      temp2 = t[j+1].date.substr(6,9) + t[j+1].date.substr(3,4) + t[j+1].date.substr(0,1);
      if (stoi(temp1) > stoi(temp2)){
        swap(&t[j], &t[j+1]);
      }
    }
  }
}
/*******************************************************************
Function: print_trans()
Description: prints user transactions to terminal
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: prints user transactions to terminal
********************************************************************/
void print_trans(transaction *t, int n){
  for (int i=0; i < n; i++){
    cout << "Date: " << t[i].date << endl;
    cout << "Amount: $" << t[i].amount << endl;
    cout << "Description: " << t[i].description << endl;
    cout << "Category: " << t[i].category << endl;
    cout << endl;
  }
}
/*******************************************************************
Function: write_to_doc()
Description: writes user transactions to a specified doc
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: writes user transactions to a specified doc
********************************************************************/
void write_to_doc(transaction *t, int n){
  string doc;
  ofstream o;

  cout << "Name of document to write to: ";
  cin >> doc;
  o.open(doc, ofstream::app);

  for (int i=0; i < n; i++){
    o << "Date: " << t[i].date << "\n";
    o << "Amount: $" << t[i].amount << "\n";
    o << "Description: " << t[i].description << "\n";
    o << "Category: " << t[i].category << "\n";
    o << "\n";
  }
}
/*******************************************************************
Function: check_args()
Description: verifies existence of cmd line args, prompts if they dont exist
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: ufile and bfile have inputs
********************************************************************/
int check_args(int argc, char** argv, string &ufile, string &bfile){
  if (argc==3){
    ufile = argv[1];
    bfile = argv[2];
    return 1;
  } else if (argc != 3){
    cout << "Error: Invalid number of arguments provided.\n";
    return 0;
  }
}
/*******************************************************************
Function: check_args()
Description: verifies existence of cmd line args, prompts if they dont exist
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: ufile and bfile have inputs
********************************************************************/
void get_bfile(string &bfile){
  cout << "Unable to open " << bfile << "\nPlease provide new budget file\n";
  cin >> bfile;
}
/*******************************************************************
Function: check_filenames()
Description: checks if you can open the provided file names.
Parameters: transaction *, int
Pre-Conditions:
Post-Conditions: return true if openable, false otherwise
********************************************************************/
bool check_filenames(string ufile, string bfile){
  ifstream fin;
  fin.open(ufile);
  if (!fin.is_open()){
    cout << "Error, unable to open " << ufile << "\n";
    return false;
  }
  fin.close();
  fin.open(bfile);
  if (!fin.is_open()){
    cout << "Error, unable to open " << bfile << "\n";
    return false;
  }
  return true;
}
