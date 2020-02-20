#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

using namespace std;

class room {
  private:
    int x, y;
    event *e;
  public:
    room(int, int);
    ~room();
    int get_x();
    int get_y();
    event get_event();
    void set_x(int);
    void set_y(int);
    void set_event(&event)
};

#endif
