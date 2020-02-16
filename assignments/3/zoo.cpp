// functions for zoo class

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
  day = 0;
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
//tiger, blackbear and sealion accessors need to be added
/*****************************************
            MUTATOR BLOCK
*****************************************/
//Mutator for n_
void zoo::set_n_tigers(int a){
 n_tigers = a;
}
//Mutator for n_
void zoo::set_n_blackbears(int a){
  n_blackbears = a;
}
//Mutator for n_
void zoo::set_n_sealions(int a){
  n_sealions = a;
}
//Mutator for bank
void zoo::set_bank(int a){
  bank = a;
}
//Mutator for food_base
void zoo::set_food_base(float a){
  food_base = a;
}
//Mutator for boom
void zoo::set_boom(int a){
  boom = a;
}
//tiger, blackbear and sealion accessors need to be added
/*****************************************
            SICK BLOCK
*****************************************/
//Sick animal selector, randomly selects a type of animal that gets sick
void zoo::sick_animal(int a){
  switch(a) {
    case 0: sick_sealion();
    case 1: sick_tiger();
    case 2: sick_blackbear();
    default: sick_sealion();
  }
}
/* sick_sealion()
If you have at least one sea lion, selects one that gets sick and then
determines if you have enough dough to save its dang life
*/
void zoo::sick_sealion(){
  srand(time(0));
  int numbo = rand() % n_sealions;
  if (n_sealions > 0) {
    cout << "Your sea lion, " << sealions[numbo].get_name() << "has fallen ill.\n";
    if (bank < 350) {
      cout << "You can't afford health care for " << sealions[numbo].get_name() << ". ";
      cout << sealions[numbo].get_name() << " dies.\n";
      kill_sealion(numbo);
    } else if (bank >= 350){
      cout << "The $350 veterinarian bill has been deducted from your bank.\n";
      bank -= 350;
    }
  } else {
    cout << "You heard reports of sea lions getting sick, luckily you don't own any\n";
  }
}
/* sick_blackbear()
If you have at least one blackbear, selects one that gets sick and then
determines if you have enough dough to save its dang life
*/
void zoo::sick_blackbear(){
  srand(time(0));
  int numbo = rand() % n_blackbears;
  if (n_blackbears > 0) {
    cout << "Your black bear, " << blackbears[numbo].get_name() << "has fallen ill.\n";
    if (bank < 2500) {
      cout << "You can't afford health care for " << blackbears[numbo].get_name() << ". ";
      cout << blackbears[numbo].get_name() << " dies.\n";
      kill_blackbear(numbo);
    } else if (bank >= 2500){
      cout << "The $2500 veterinarian bill has been deducted from your bank.\n";
      bank -= 2500;
    }
  } else {
    cout << "You heard reports of black bears getting sick, luckily you don't own any\n";
  }
}
/* sick_tiger()
If you have at least one tiger, selects one that gets sick and then
determines if you have enough dough to save its dang life
*/
void zoo::sick_tiger(){
  srand(time(0));
  int numbo = rand() % n_tigers;
  if (n_tigers > 0) {
    cout << "Your tiger, " << tigers[numbo].get_name() << "has fallen ill.\n";
    if (bank < 2500) {
      cout << "You can't afford health care for " << tigers[numbo].get_name() << ". ";
      cout << tigers[numbo].get_name() << " dies.\n";
      kill_tiger(numbo);
    } else if (bank >= 2500){
      cout << "The $6000 veterinarian bill has been deducted from your bank.\n";
      bank -= 6000;
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
    case 1: birth_tiger();
    case 2: birth_blackbear();
    default: birth_sealion();
  }
}
/*************
adds a baby tiger to the tiger array
*************/
void zoo::birth_tiger(){

}
/*************
adds a baby sealion to the sealion array
*************/
void zoo::birth_sealion(){

}
/*************
adds a baby blackbear to the blackbear array
*************/
void zoo::birth_blackbear(){

}
/*****************************************
        KILL BLOCK
*****************************************/
/*************
kill_sealion(), removes a specific sealion from the array
*************/
void kill_sealion(int a){

}
/*************
kill_tiger(), removes a specific tiger from the array
*************/
void kill_tiger(int a){

}
/*************
kill_blackbear(), removes a specific blackbear from the array
*************/
void kill_blackbear(int a){

}
/*****************************************
        MONTHLY OPERATIONS
*****************************************/
/*************
 runs all the necessary functions to go through one month of the game
*************/
void zoo::run_month(){

}
/*************

*************/
void zoo::buy_food(){

}
/*************

*************/
bool zoo::bankrupt(){

}
