/*******************************************************************
Author: Garrett Martin
assignment: 5 - linked lists and sorts
date: 3/11/2020
file: main.cpp
*******************************************************************/

#include "node.h"
#include "linked_list.h"

using namespace std;

int main(){
  linked_list l;

  l.push_back(8);
  l.push_front(7);
  l.push_front(11);
  l.push_front(13);
  l.push_back(21);
  l.insert(121, 3);

  cout << "primes: ";
  l.print_prime();
  cout << "whole list: ";
  l.print();

  return 0;
}
