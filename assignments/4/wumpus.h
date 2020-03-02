#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

#include <string>

using namespace std;

class wumpus : public event {
  public:
    wumpus();
    void encounter();
};

#endif
