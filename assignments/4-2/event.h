#ifndef EVENT_H
#define EVENT_H

#include "event.h"

#include <string>

using namespace std;

class event {
  private:
    string percept;
    char symbol;
  public:
    event();
    virtual int encounter();
    //accessors and mutators
    void set_percept(string);
    void set_symbol(char);
    string get_percept();
    char get_symbol();
};

#endif
