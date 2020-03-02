#ifndef ESCAPE_H
#define ESCAPE_H

#include "event.h"

#include <string>

using namespace std;

class escape : public event {
  public:
    escape();
    int encounter();
};

#endif
