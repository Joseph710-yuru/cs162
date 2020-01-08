/******************************************************
** Program: 1.cpp
** Author: Garrett Martin
** Date: 01/08/2020
** Description:
** Input:
** Output:
******************************************************/

struct user{
   string name;
   int id;
   string password;
}

struct budget{
   int id;
   float balance;
   int num_transactions;
   struct transaction *t;
}

struct transaction{
   float amount;
   string date;
   string category;
   string description;
}

budget* create_budgets(int);
void get_budget_data(budget*, int, ifstream &);
transaction* create_transactions(int);
void get_transaction_data(transaction*, int, ifstream &);
void delete_info(user**, int, budget**, int);
