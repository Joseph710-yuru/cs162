#ifndef ROOM_H
#define ROOM_H

#include "event.h"

#include <string>

using namespace std;

class room {
  private:
    event e;
    bool arrow, show;
  public:
    room();
    char get_symbol();
    bool get_show();
    void set_show(bool);
    event get_event();
    void set_event(event &);
    bool get_arrow();
    void set_arrow(bool);
    void get_percept();
    string get_name();
    int get_ent();
    bool kill();
};

#endif
