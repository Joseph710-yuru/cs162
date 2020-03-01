#ifndef BATS_H
#define BATS_H

#include "event.h"

#include <string>

using namespace std;

class bats : public event {
  private:

  public:
    void percept();
    void encounter();
    string contain();
};

#endif
