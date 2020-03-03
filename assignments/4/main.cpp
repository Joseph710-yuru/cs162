#include "event.h"
#include "wumpus.h"
#include "pit.h"
#include "bats.h"
#include "gold.h"
#include "escape.h"
#include "game.h"

#include <iostream>
//#include <cstdlib>
//#include <ctime>

using namespace std;

int main(){
  srand(time(0));
  game a;
  a.game_loop();

  return 0;
}
