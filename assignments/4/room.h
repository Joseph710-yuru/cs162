#ifndef ROOM_H
#define ROOM_H

#include "event.h"

#include <string>
#include <vector>

using namespace std;

class room {
  private:
    int arrows;
    bool reveal;
    event *e;
  public:
    room();
    int ev_encounter();
    //accessors and mutators
    int get_arrows();
    void set_arrows(int);
    bool get_reveal();
    void set_reveal(bool);
    event* get_event();
    void set_event(event &);
    //event related functions
    char get_e_symbol();
    string get_e_percept();
    int get_e_encounter();
};

#endif


//west -y
//east +y
//south  +x
//north -x
