#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

using namespace std;

class wumpus : public event {
  private:
    int alive;
  public:
    void percept();
    void encounter();
    void kill();
    bool wake_up();
};

#endif
