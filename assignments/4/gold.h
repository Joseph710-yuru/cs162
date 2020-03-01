#ifndef GOLD_H
#define GOLD_H

#include "event.h"

#include <string>

using namespace std;

class gold : public event {
  private:

  public:
    void percept();
    void encounter();
    string contain();
};

#endif
