/*****************************
Author: Garrett Martin
Date: 2/16/19
Program: Assignment 3 "Zoo Tycoon-ish"
*****************************/

#include "zoo.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
  int repeat = 1;
  zoo bamafoo;
  srand(time(0));

  cout << "Welcome to your zoo!\n";
  bamafoo.print_stats();
  bamafoo.buy_animals();
  bamafoo.buy_food();
  bamafoo.set_month(1);
  cout << endl;

  while (repeat != 0){
    bamafoo.run_month();
    cout << "Continue game (0 - no, 1 - yes): ";
    cin >> repeat;
    cout << endl;
  }


  return 0;
}
