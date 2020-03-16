#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

#include <iostream>

using namespace std;

class linked_list {
  private:
    unsigned int length; // length of list
    node *head; // points 2 head
    void merge_sort_ascend(node **); //its merge sort
    void merge_sort_descend(node **);
  public:
    linked_list();
    ~linked_list();
    int get_length();
    void print();
    void clear();
    unsigned int push_front(int);
    unsigned int push_back(int);
    unsigned int insert(int, unsigned int);
    void sort_ascending();
    void sort_descending();
    bool prime(int);
    int prime_amount(); // returns the amount of primes in a list
    void print_prime(); // prints out all the primes in list
    node* merge_ascend(node *, node *);
    node* merge_descend(node *, node *);
    void split(node *, node **, node **);
    void swap(node **, node *, node *, node *);
};

#endif
