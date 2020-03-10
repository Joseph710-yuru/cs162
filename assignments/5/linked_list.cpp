/*******************************************************************
file: linked_list.cpp
description: implementation for linked_list class
*******************************************************************/
#include "linked_list.h"
#include "node.h"

#include <iostream>
#include <cstdlib>

using namespace std;

/*******************************************************************
function: linked_list
description: default constructor for linked list
*******************************************************************/
linked_list::linked_list(){
  length = 0;
  head = new node;
}
/*******************************************************************
function: get_length
description: accessor for length
*******************************************************************/
int linked_list::get_length(){
  return length;
}
/*******************************************************************
function: print
description: prints all items from the list
*******************************************************************/
void linked_list::print(){
  node *temp = head;
  int i=0;
  while (i != length) {
    cout << temp->val << " ";
    temp = temp->next;
    ++i;
  }
  cout << endl;
  temp = nullptr;
}
/*******************************************************************
function: clear
description: deletes every element from a list
*******************************************************************/
void linked_list::clear(){

}
/*******************************************************************
function: push_front
description: adds new element to beginning of linked list
*******************************************************************/
unsigned int linked_list::push_front(int v){
    node *temp;
    temp = new node;
    temp->val = head->val;
    temp->next = head->next;

    head->next = temp;
    head->val = v;

    length++;
}
/*******************************************************************
function: push_back
description: adds new element to end of linked list
*******************************************************************/
unsigned int linked_list::push_back(int v){
  node *temp, *t2=head;
  if (head->next == nullptr) {
    head->val = v;
  } else {
    for (int i=0; i<length;++i){
      if (t2->next != nullptr) t2=t2->next;
      else if (t2->next == nullptr) {
        temp = new node;
        temp->val = v;
        t2->next=temp;
      }
    }
  }

  length++;
}
/*******************************************************************
function:
description:
*******************************************************************/
unsigned int linked_list::insert(int v, unsigned int index){
  node *temp;
  temp = new node;

  int i = 0;
  while (i != index){
    temp = temp->next;
  }

  head->next = temp;
  head->val = v;

  length++;
}
void sort_ascending(){}
void sort_descending(){}
/*******************************************************************
function: prime
parameter: int
description: returns true if a given number is prime, false otherwise
*******************************************************************/
bool linked_list::prime(int val){
  if (abs(val) == 1) return false;
  for (int i=2; i < abs(val); ++i){
    if (abs(val) % i == 0) return false;
  }

  return true;
}
/*******************************************************************
function: print_prime()
description: prints all the prime numbers in the list
*******************************************************************/
void linked_list::print_prime(){
  node *temp = head;
  int i=0;
  while (i != length) {
    if (prime(temp->val)==true){
      cout << temp->val << " ";
    }
    temp = temp->next;
    ++i;
  }
  cout << endl;
  temp = nullptr;
}
