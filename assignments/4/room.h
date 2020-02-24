#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class room {
  private:
    event e;
  public:
    room();
    ~room();
    event get_event();
    void set_event(event &);
};

#endif
