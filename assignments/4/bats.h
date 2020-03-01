#ifndef BATS_H
#define BATS_H

#include "event.h"

#include <string>

using namespace std;

class bats : public event {
  public:
    void encounter();
};

#endif
