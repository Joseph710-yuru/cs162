#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

#include <string>

using namespace std;

class wumpus : public event {
  private:
    int alive;
  public:
    void percept();
    void encounter();
    void kill();
    bool wake_up();
    string contain();
};

#endif
