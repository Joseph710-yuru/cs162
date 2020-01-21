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

int get_budget_index(budget *, user *, int);
bool check_range(int, int, int);
bool is_int(int);
void get_int(int &);
void get_int_range(int &, int, int);
void select_option(int, int &);
void print_options();
void get_user_data(user*, int, ifstream&);
void get_password(user *);
void get_userid(user *);
bool compare_user(user *, user *, int);
bool check_login(user *, int &);
budget* create_budgets(int);
void get_budget_data(budget*, int, ifstream &);
transaction* create_transactions(int);
void get_transaction_data(transaction*, int, ifstream &);
void delete_info(user**, int, budget**, int);

#endif
