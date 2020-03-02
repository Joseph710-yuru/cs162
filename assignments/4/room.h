#ifndef ROOM_H
#define ROOM_H

#include "event.h"

#include <string>

using namespace std;

class room {
  private:
    event *e;
    bool arrow, show;
  public:
    room();
    ~room();
//accessors and mutators
    char get_symbol();
    bool get_show();
    void set_show(bool);
    event get_event();
    void set_event(event *);
    bool get_arrow();
    void set_arrow(bool);
    void get_percept();
    string get_name();
    int get_ent();
//when u gotta kill a wumpus
    bool kill();
//event stuff
    void assign_escape();
    void assign_empty();
    void assign_wumpus();
    void assign_pit();
    void assign_bats();
    void assign_gold();
};

#endif
