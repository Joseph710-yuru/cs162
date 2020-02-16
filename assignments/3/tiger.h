#ifndef TIGER_H
#define TIGER_H

#include "animal.h"

using namespace std;

class tiger : public animal {
  private:

  public:
    tiger();
    tiger(int);
    void bought();
    void birth();
    string namegen();
};

#endif
