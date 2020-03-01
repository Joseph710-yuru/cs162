#ifndef ROOM_H
#define ROOM_H

#include "event.h"

#include <string>

using namespace std;

class room {
  private:
    event e;
  public:
    room();
    event get_event();
    void set_event(event &);
    string contain();
};

#endif
