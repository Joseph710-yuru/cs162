#include "zoo.h"
#include "animal.h"

/*****************************************
      CONSTRUCT/DESTRUCT BLOCK
*****************************************/
/*************
constructor for zoo,
*************/
zoo::zoo(){

}
/*************
d-struct dat zoo
*************/
zoo::~zoo(){

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
/*************
Mutator for n_
*************/
void zoo::set_n_tigers(int a){
  n_tiger = a;
}
/*************
Mutator for n_
*************/
void zoo::set_n_blackbears(int a){
  n_blackbears = a;
}
/*************
Mutator for n_
*************/
void zoo::set_n_sealions(int a){
  n_sealions = a;
}
/*************
Mutator for bank
*************/
void zoo::set_bank(int a){
  bank = a;
}
/*************
Mutator for food_base
*************/
void zoo::set_food_base(float a){
  food_base = a;
}
/*************
Mutator for boom
*************/
void zoo::set_boom(int a){
  boom = a;
}
//tiger, blackbear and sealion accessors need to be added
/*****************************************
            SICK BLOCK
*****************************************/
/*************

*************/
void zoo::sick_animal(int){

}
/*************

*************/
void zoo::sick_sealion(){

}
/*************

*************/
void zoo::sick_blackbear(){

}
/*************

*************/
void zoo::sick_tiger(){

}
/*****************************************
            BIRTH BLOCK
*****************************************/
/*************
determines which of the three animals have been chosen to have a baby
*************/
void zoo::birth_animal(int){

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
