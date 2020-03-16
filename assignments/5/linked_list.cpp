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
function: ~linked_list
description: destructor for linked_list
*******************************************************************/
linked_list::~linked_list(){
  node *temp;
  temp = head;

  while (length > 1){
    for (int i=0; i < length;++i){
      if (temp->next != nullptr) temp = temp->next;
      delete temp;
      length--;
    }
  }

  delete head;
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
  node *temp;
  temp = head;

  while (length > 1){
    for (int i=0; i < length;++i){
      if (temp->next != nullptr) temp = temp->next;
      delete temp;
      length--;
    }
  }
  
  length = 0;
  head->val = 0;
  head->next = nullptr;
}
/*******************************************************************
function: push_front
description: adds new element to beginning of linked list
*******************************************************************/
unsigned int linked_list::push_front(int v){
  node *temp;
  if (length = 0) head->val = v;
  else {
    temp = new node;
    temp->val = head->val;
    temp->next = head->next;

    head->next = temp;
    head->val = v;
  }

  length++;
}
/*******************************************************************
function: push_back
description: adds new element to end of linked list
*******************************************************************/
unsigned int linked_list::push_back(int v){
  node *temp, *t2=head;
  if (length == 0) {
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
function: insert
description: inserts an element into the list at a specified index
*******************************************************************/
unsigned int linked_list::insert(int v, unsigned int index){
  node *temp1, *temp2 = new node;
  temp1 = head;
  temp2->val = v;

  if (index > length) cout << "Invalid index provided\n";
  else {
    if (index == 1) push_front(v);
    else {
      for (int i=1; i < index - 1; ++i){
        if (temp1->next != nullptr) temp1 = temp1->next;
      }

      temp2->next = temp1->next;
      temp1->next = temp2;

      length++;
    }
  }
}
/*******************************************************************
function: sort_ascending
description: sorts list in ascending order using a recursive merge sort
*******************************************************************/
void linked_list::sort_ascending(){
  merge_sort_ascend(&head);
}
/*******************************************************************
function: merge_ascend
parameter: node **
description: merge sort algorithm to sort from least to greatest
*******************************************************************/
void linked_list::merge_sort_ascend(node **ref){
  node *top = *ref, *a, *b;
  if (top == nullptr || top->next==nullptr) return;
  split(top, &a, &b);
  merge_sort_ascend(&a);
  merge_sort_ascend(&b);
  *ref = merge_ascend(a, b);
}
/*******************************************************************
function: split
description: splits a linked list into two.
*******************************************************************/
void linked_list::split(node *source, node **a, node **b){
  if (source==nullptr || source->next == nullptr){
    *a = source;
    *b = nullptr;
  } else {
    node *fast, *slow;
    fast = source->next;
    slow = source;

    while (fast != nullptr && fast->next != nullptr){
      fast = fast->next->next;
      slow = slow->next;
    }
    *a = source;
    *b = slow->next;
    slow->next = nullptr;
  }
}
/*******************************************************************
function: merge_ascend
description: merges two lists together in ascending order
*******************************************************************/
node* linked_list::merge_ascend(node *a, node *b){
  if (a==nullptr) return b;
  if (b==nullptr) return a;

  node *top = nullptr;
  if (a->val <= b->val) {
    top = a;
    top->next = merge_ascend(top->next, b);
  } else {
    top = b;
    top->next = merge_ascend(top->next, a);
  }
  return top;
}
/*******************************************************************
function: sort_descending
description: sorts list in descending order using a recursive selection sort
*******************************************************************/
void linked_list::sort_descending(){
  merge_sort_descend(&head);
}
/*******************************************************************
function: merge_descend
parameter: node **
description: merge sort algorithm to sort from greatest to least
*******************************************************************/
void linked_list::merge_sort_descend(node **ref){
  node *top = *ref, *a, *b;
  if (top == nullptr || top->next==nullptr) return;
  split(top, &a, &b);
  merge_sort_descend(&a);
  merge_sort_descend(&b);
  *ref = merge_descend(a, b);
}
/*******************************************************************
function: merge_descend
description: merges two lists together in descending order
*******************************************************************/
node* linked_list::merge_descend(node *a, node *b){
  if (a==nullptr) return b;
  if (b==nullptr) return a;

  node *top = nullptr;
  if (a->val >= b->val) {
    top = a;
    top->next = merge_descend(top->next, b);
  } else {
    top = b;
    top->next = merge_descend(top->next, a);
  }
  return top;
}
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
/*******************************************************************
function: print_prime()
description: returns the amount of primes in the list
*******************************************************************/
int linked_list::prime_amount(){
  node *temp = head;
  int i=0, num=0;
  while (i != length) {
    if (prime(temp->val)==true) num++;
    temp = temp->next;
    i++;
  }
  temp = nullptr;
  return num;
}
