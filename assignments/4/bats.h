#ifndef BATS_H
#define BATS_H

#include "event.h"

using namespace std;

class bats : public event {
  private:

  public:
    void percept();
    void encounter();
};

#endif
