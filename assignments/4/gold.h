#ifndef GOLD_H
#define GOLD_H

#include "event.h"

using namespace std;

class gold : public event {
  private:

  public:
    void percept();
    void encounter();
};

#endif
