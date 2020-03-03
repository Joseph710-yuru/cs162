#include "event.h"

#include <iostream>

using namespace std;

event::event(){
  percept = " ";
  symbol = ' ';
}

int event::encounter(){
  return 0;
}

void event::set_percept(string p){
  percept = p;
}

void event::set_symbol(char s){
  symbol = s;
}

string event::get_percept(){
  return percept;
}

char event::get_symbol(){
  return symbol;
}
