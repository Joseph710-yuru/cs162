// implementation for zoo class

#include "zoo.h"
#include "animal.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*****************************************
      CONSTRUCT/DESTRUCT BLOCK
*****************************************/
/*************
constructor for zoo,
*************/
zoo::zoo(){
  tigers = new tiger [1024];
  sealions = new sealion [1024];
  blackbears = new blackbear [1024];
  n_tigers = 0;
  n_sealions = 0;
  n_blackbears = 0;
  bank = 100000;
  food_base = 80;
  boom = 0;
  month = 0;
}
/*************
d-struct dat zoo
*************/
zoo::~zoo(){
 delete [] tigers;
 tigers = NULL;
 delete [] sealions;
 sealions = NULL;
 delete [] blackbears;
 blackbears = NULL;

}
/*****************************************
            ACCESSOR BLOCK
*****************************************/
int zoo::get_n_tigers(){
  return n_tigers;
}
int zoo::get_n_blackbears(){
  return n_blackbears;
}
int zoo::get_n_sealions(){
  return n_sealions;
}
int zoo::get_bank(){
  return bank;
}
float zoo::get_food_base(){
  return food_base;
}
int zoo::get_boom(){
  return boom;
}
int zoo::get_month(){
  return month;
}
//tiger, blackbear and sealion accessors need to be added
/*****************************************
            MUTATOR BLOCK
*****************************************/
void zoo::set_n_tigers(int a){
 n_tigers = a;
}
void zoo::set_n_blackbears(int a){
  n_blackbears = a;
}
void zoo::set_n_sealions(int a){
  n_sealions = a;
}
void zoo::set_bank(int a){
  bank = a;
}
void zoo::set_food_base(float a){
  food_base = a;
}
void zoo::set_boom(int a){
  boom = a;
}
void zoo::set_month(int a){
  month = a;
}
//tiger, blackbear and sealion accessors need to be added
/*****************************************
            SICK BLOCK
*****************************************/
//sick_animal() - randomly selects a type of animal that gets sick
void zoo::sick_animal(int a){
  switch(a) {
    case 0: sick_sealion();
            break;
    case 1: sick_tiger();
            break;
    case 2: sick_blackbear();
            break;
    default: sick_sealion();
            break;
  }
}
/*************
sick_sealion() - If you have at least one sea lion, selects one that gets sick
and then determines if you have enough dough to save its dang life
*************/
void zoo::sick_sealion(){
  if (n_sealions > 0) {
    int numbo = rand() % n_sealions;
    cout << "Your sea lion, " << sealions[numbo].get_name() << " has fallen ill.\n";
    if (sealions[numbo].is_baby() == true){
      if (bank < 700) {
        cout << "\tYou can't afford health care for poor baby " << sealions[numbo].get_name() << ".\n";
        kill_sealion(numbo);
      } else if (bank >= 700) {
        cout << "\tThe $700 veterinarian bill has been deducted from your bank account.\n";
        bank -= 700;
      }
    } else {
      if (bank < 350) {
        cout << "\tYou can't afford health care for " << sealions[numbo].get_name() << ".\n";
        kill_sealion(numbo);
      } else if (bank >= 350){
        cout << "\tThe $350 veterinarian bill has been deducted from your bank.\n";
        bank -= 350;
      }
    }
  } else {
    cout << "You heard reports of sea lions getting sick, luckily you don't own any\n";
  }
}
/*************
sick_blackbear() - If you have at least one blackbear, selects one that gets
sick and then determines if you have enough dough to save its dang life
*************/
void zoo::sick_blackbear(){
  if (n_blackbears > 0) {
    int numbo = rand() % n_blackbears;
    cout << "Your black bear, " << blackbears[numbo].get_name() << " has fallen ill.\n";
    if (blackbears[numbo].is_baby() == true){
      if (bank < 5000) {
        cout << "\tYou can't afford health care for poor baby " << blackbears[numbo].get_name() << ".\n";
        kill_blackbear(numbo);
      } else if (bank >= 5000) {
        cout << "\tThe $500 veterinarian bill has been deducted from your bank account.\n";
        bank -= 2500;
      }
    } else {
      if (bank < 2500) {
        cout << "\tYou can't afford health care for " << blackbears[numbo].get_name() << ".\n";
        kill_blackbear(numbo);
      } else if (bank >= 2500){
        cout << "\tThe $2500 veterinarian bill has been deducted from your bank account.\n";
        bank -= 2500;
      }
    }
  } else {
    cout << "You heard reports of black bears getting sick, luckily you don't own any\n";
  }
}
/*************
sick_tiger() - If you have at least one tiger, selects one that gets sick and
then determines if you have enough dough to save its dang life
*************/
void zoo::sick_tiger(){
  if (n_tigers > 0) {
    int numbo = rand() % n_tigers;
    cout << "Your tiger, " << tigers[numbo].get_name() << " has fallen ill.\n";
    if (tigers[numbo].is_baby() == true){
      if (bank < 12000){
        cout << "\tYou can't afford health care for poor baby " << tigers[numbo].get_name() << ".\n";
        kill_tiger(numbo);
      } else if (bank >= 12000) {
        cout << "\tThe $12000 veterinarian bill has been deducted from your bank account.\n";
        bank -= 12000;
      }
    } else {
      if (bank < 6000) {
        cout << "\tYou can't afford health care for " << tigers[numbo].get_name() << ".\n";
        kill_tiger(numbo);
      } else if (bank >= 6000){
        cout << "\tThe $6000 veterinarian bill has been deducted from your bank account.\n";
        bank -= 6000;
      }
    }
  } else {
    cout << "You heard reports of tigers getting sick, luckily you don't own any\n";
  }
}
/*****************************************
            BIRTH BLOCK
*****************************************/
/*************
determines which of the three animals have been chosen to have a baby
*************/
void zoo::birth_animal(int a){
  switch(a) {
    case 0: birth_sealion();
            break;
    case 1: birth_tiger();
            break;
    case 2: birth_blackbear();
            break;
    default: birth_sealion();
            break;
  }
}
/*************
adds a baby tiger to the tiger array
*************/
void zoo::birth_tiger(){
  int adults = 0;
  for (int i=0; i < n_tigers; i++) if (tigers[i].is_adult() == true) adults++;
  if (adults >= 2) {
    cout << "One of your tigers had cubs!\n";
    for (int i = 0; i < 3; i++){
      tigers[n_tigers].birth();
      cout << "\tTiger " << tigers[n_tigers].get_name() << " has been born!\n";
      n_tigers++;
    }
  } else {
    cout << "You should probably get a couple adult tigers so they can multiply\n";
  }
}
/*************
adds a baby sealion to the sealion array
*************/
void zoo::birth_sealion(){
  int adults=0;
  for (int i=0; i < n_sealions;i++) if (sealions[i].is_adult() == true) adults++;
  if (adults >= 2){
    cout << "One of your sea lions had pups!\n";
    sealions[n_sealions].birth();
    cout << "\tSea lion " << sealions[n_sealions].get_name() << " has been born!\n";
    n_sealions++;
  } else {
    cout << "You should probably get a couple adult sea lions so they can multiply\n";
  }
}
/*************
adds a baby blackbear to the blackbear array
*************/
void zoo::birth_blackbear(){
  int adults = 0;
  for (int i=0; i < n_blackbears; i++) if (blackbears[i].is_adult() == true) adults++;
  if (adults >= 2) {
    cout << "One of your black bears had cubs!\n";
    for (int i=0; i < 2; i++){
      blackbears[n_blackbears].birth();
      cout << "\tBlack bear " << blackbears[n_blackbears].get_name() << " has been born!\n";
      n_blackbears++;
    }
  } else {
    cout << "You should probably get a couple adult black bears so they can multiply\n";
  }
}
/*****************************************
        KILL BLOCK
*****************************************/
/*************
kill_sealion(), removes a specific sealion from the array
*************/
void zoo::kill_sealion(int a){
  sealions[a].kill();
  clean(sealions, n_sealions);
  n_sealions--;
}
/*************
kill_tiger(), removes a specific tiger from the array
*************/
void zoo::kill_tiger(int a){
  tigers[a].kill();
  clean(tigers, n_tigers);
  n_tigers--;
}
/*************
kill_blackbear(), removes a specific blackbear from the array
*************/
void zoo::kill_blackbear(int a){
  blackbears[a].kill();
  clean(blackbears, n_blackbears);
  n_blackbears--;
}
/*****************************************
        MONTHLY OPERATIONS
*****************************************/
/*************
 runs all the necessary functions to go through one month of the game
*************/
void zoo::run_month(){
  cout << "Month: " << month  << endl;
  age();
  special_event();
  revenue();
  buy_animals();
  print_stats();
  buy_food();
  boom = 0;
  month++;
}
/*************
// age() - Ages each animal in the zoo by one month.
*************/
void zoo::age(){
  for (int i=0;i<n_tigers;i++) tigers[i].set_age(tigers[i].get_age() + 1);
  for (int i=0;i<n_sealions;i++) sealions[i].set_age(sealions[i].get_age() + 1);
  for (int i=0;i<n_blackbears;i++) blackbears[i].set_age(blackbears[i].get_age() + 1);
}
/*************
// special_event() - determines which event you get in a given month
*************/
void zoo::special_event(){
  switch ((rand() % 3)) {
    case 0: sick_animal((rand() % 3));
            break;
    case 1: birth_animal((rand() % 3));
            break;
    case 2: boom = 1;
            cout << "There's been a boom in visitors this month!\n";
            break;
  }
}
/*************
// revenue() -- Calculates the revenue generated that month.
*************/
void zoo::revenue(){
  int t=0,s=0,b=0, rev=0;
// default revenue calculation
  for (int i=0; i < n_tigers; i++) if (tigers[i].is_baby() == true) t++;
  for (int i=0; i < n_sealions; i++) if (sealions[i].is_baby() == true) s++;
  for (int i=0; i < n_blackbears; i++) if (blackbears[i].is_baby() == true) b++;
  rev = ((n_tigers + t) * 1200) + ((n_blackbears + b) * 500) + ((n_sealions + s) * 140);
  // calculate additional revenue during boom month
  if (boom==1) for (int i=0; i < n_sealions; i++) rev = rev + rand() % 250 + 150;
  cout << "You earned $" << rev << " in revenue\n";
  bank = bank + rev;
  cout << "Your current bank balance is: $" << bank << endl;
}
/*************
// buy_food() - Buys food, subtracts from bank, sets new food_base
*************/
void zoo::buy_food(){
  float num = n_tigers + n_blackbears + n_sealions;
  cout << "Food purchased for " << num << " animals at $";
  num = (n_tigers * 5) + (n_blackbears * 3) + n_sealions;
  num = num * food_base;
  cout << food_base << " per unit totaling: $" << num << endl;
  bank = bank - num;
  food_base = food_base * ((rand() % 5 + 8)/10.0);
}
/*************
// bankrupt() - Returns true if you're bankrupt, otherwise false
*************/
bool zoo::bankrupt(){
  if (bank <= 0) {
    cout << "You've gone bankrupt! Game over!\n";
    return true;
  }
  else return false;
}
/*************
// clean() - sorts uninitialized animals towards the back of the array
*************/
void zoo::clean(animal *a, int num){
  for (int i=0; i < num; i++){
    if (a[i].get_age() == -1) {
      swap_animal(a[i], a[num - 1]);
    }
  }
}
/*************
// swap_animal() - it's a swap, but for animals
*************/
void zoo::swap_animal(animal &a, animal &b){
  animal temp = a;
  a = b;
  b = temp;
}
/************
// buy_animals() - general function for monthly option to buy new animals
************/
void zoo::buy_animals(){
  int yes=-1, buy = -1;
  cout << "Would you like to buy any animals? (0-no, 1-yes): ";
  gimmean_int(yes);
  if (yes == 1){
    cout << "Select animal to buy:\n\t1. Sea Lion(s).\n\t2. Black bear(s)\n\t3. Tiger(s)\n";
    cout << "Animal: ";
    gimmean_int(buy);
    if (buy == 1) buy_sealions();
    else if (buy == 2) buy_blackbears();
    else if (buy == 3) buy_tigers();
    else cout << "Bad selection, no animals purchased this month.\n";
  }
}
/************
// buy_tigers() - runs through the process of buying 1 or 2 tigers
************/
void zoo::buy_tigers(){
  int repeat = 1, num;
  if (bank >= 12000) {
    while (repeat==1){
      cout << "Would you like 1 or 2 tigers? ";
      gimmean_int(num);
      if (num == 1) {
        tigers[n_tigers].bought();
        cout << "\tTiger " << tigers[n_tigers].get_name() << " purchased!\n";
        bank = bank - 12000;
        n_tigers++;
        repeat = 0;
      } else if (num == 2 && bank >= 24000) {
        tigers[n_tigers].bought();
        tigers[n_tigers+1].bought();
        cout << "\tTigers " << tigers[n_tigers].get_name() << " and ";
        cout << tigers[n_tigers+1].get_name() << " purchased!\n";
        n_tigers = n_tigers + 2;
        bank = bank - 24000;
        repeat = 0;
      } else if (num == 2 && bank < 24000) cout << "\tYou cannot afford that.\n";
    }
  } else {
    cout << "You do not have enough money to buy a tiger.\n";
    buy_animals();
  }
}
/************
// buy_sealions() - runs through the process of buying 1 or 2 sea lions
************/
void zoo::buy_sealions() {
  int repeat = 1, num;
  if (bank >= 700) {
    while (repeat==1){
      cout << "Would you like 1 or 2 sea lions? ";
      gimmean_int(num);
      if (num == 1) {
        sealions[n_sealions].bought();
        cout << "\tSea lion " << sealions[n_sealions].get_name() << " purchased!\n";
        n_sealions++;
        bank = bank - 1400;
        repeat = 0;
      } else if (num == 2 && bank >= 1400) {
        sealions[n_sealions].bought();
        sealions[n_sealions+1].bought();
        cout << "\tSea lions " << sealions[n_sealions].get_name() << " and ";
        cout << sealions[n_sealions+1].get_name() << " purchased!\n";
        n_sealions = n_sealions + 2;
        bank = bank - 1400;
        repeat = 0;
      } else if (num == 2 && bank < 1400) cout << "\tYou cannot afford that.\n";
    }
  } else {
    cout << "You do not have enough money to buy a sea lion.\n";
    buy_animals();
  }
}
/************
// buy_blackbears() - runs through the process of buying 1 or 2 black bears
************/
void zoo::buy_blackbears(){
  int repeat = 1, num;
  if (bank >= 5000) {
    while (repeat==1){
      cout << "Would you like 1 or 2 black bears? ";
      gimmean_int(num);
      if (num == 1) {
        blackbears[n_blackbears].bought();
        cout << "\tBlack bear " << blackbears[n_blackbears].get_name() << " purchased!\n";
        n_blackbears++;
        bank = bank - 5000;
        repeat = 0;
      } else if (num == 2 && bank >= 10000) {
        blackbears[n_blackbears].bought();
        blackbears[n_blackbears+1].bought();
        cout << "\tBlack bears " << blackbears[n_blackbears].get_name() << " and ";
        cout << blackbears[n_blackbears+1].get_name() << " purchased!\n";
        n_blackbears = n_blackbears + 2;
        bank = bank - 10000;
        repeat = 0;
      } else if (num == 2 && bank < 10000) cout << "\tYou cannot afford that.\n";
    }
  } else {
    cout << "You do not have enough money to buy a black bear.\n";
    buy_animals();
  }
}
/***********
// gimmean_int() - gets an int.
***********/
void zoo::gimmean_int(int &num) {
  int repeat = 1;

  cin >> num;

  while (repeat == 1) {
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000000000,'\n');
      cout << "\tERROR: Non-Integer Input\n\tInput an integer: ";
      cin >> num;
    } else {
      repeat = 0;
    }
  }
}
/***********
// print_stats() - prints out your monthly stats. # of animals, bank.
***********/
void zoo::print_stats(){
  cout << "Bank: $" << bank << endl;
  cout << "You have:\n\tSea lions: " << n_sealions << endl;
  cout << "\tBlack bears: " << n_blackbears << endl;
  cout << "\tTigers: " << n_tigers << endl;
}
