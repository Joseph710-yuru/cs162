#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

#include <string>

using namespace std;

class wumpus : public event {
  private:
    bool alive;
  public:
    wumpus();
    bool get_alive();
    void set_alive(bool);
    string get_percept();
    int encounter();
    void kill();
    bool wake_up();
};

#endif
