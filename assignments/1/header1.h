#ifndef HEADER1_H
#define HEADER1_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct user{
   string name;
   int id;
   string password;
};

struct transaction{
   float amount;
   string date;
   string category;
   string description;
};

struct budget{
   int id;
   float balance;
   int num_transactions;
   struct transaction *t;
};

bool check_filenames(string, string);
void get_bfile(string &);
int check_args(int, char**, string &, string &);
void category_sort(budget *, int);
void date_sort(budget *, int);
void categorysorter(transaction *, int);
void datesorter(transaction *, int);
void write_to_doc(transaction *, int);
void print_trans(transaction *, int);
void dollarsorter(transaction *, int);
void dollar_sort(budget *, int);
int get_budget_index(budget *, user *, int);
bool check_range(int, int, int);
bool is_int(int);
void get_int(int &);
void get_int_range(int &, int, int);
void select_option(budget *, int, int &, int);
void print_options();
void get_user_data(user*, int, ifstream&);
void get_password(user *);
void get_userid(user *);
bool compare_user(user *, user *, int);
bool check_login(user *, int &, string);
budget* create_budgets(int);
void get_budget_data(budget*, int, ifstream &);
transaction* create_transactions(int);
void get_transaction_data(transaction*, int, ifstream &);
void delete_info(user**, budget**, int);

#endif
