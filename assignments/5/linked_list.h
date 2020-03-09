#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

#include <iostream>

using namespace std;

class linked_list {
  private:
    unsigned int length; // length of list
    Node *head; // points 2 head
  public:
    int get_length();
    void print();
    void clear();
    unsigned int push_front(int);
    unsigned int push_back(int);
    unsigned int insert(int, unsigned int);
    void sort_ascending();
    void sort_descending();
    bool prime();
    void print_prime();
    void swap_nodes();
};

#endif
