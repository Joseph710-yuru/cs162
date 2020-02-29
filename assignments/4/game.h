#ifndef GAME_H
#define GAME_H

#include "room.h"

#include <iostream>
#include <vector>

using namespace std;

class game {
  private:
    int player_x, player_y,alive,rooms;
    
  public:
    game();
    game(int);
    ~game();
    int get_player_x();
    int get_player_y();
    void set_player_x();
    void set_player_y();
    void move_north();
    void move_south();
    void move_east();
    void move_west();
};

#endif
