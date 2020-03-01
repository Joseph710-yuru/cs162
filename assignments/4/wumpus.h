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
    void encounter();
    void kill();
    bool wake_up();
};

#endif
