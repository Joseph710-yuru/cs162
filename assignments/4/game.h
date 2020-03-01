#ifndef GAME_H
#define GAME_H

#include "room.h"

#include <iostream>
#include <vector>

using namespace std;

class game {
  private:
    int player_x, player_y, rooms, arrows;
    bool alive, horde, debug, escape;
    vector<vector<room>> r;
  public:
    game();
    game(int, bool);
    ~game();
    //accessors and mutators
    int get_player_x();
    int get_player_y();
    int get_arrows();
    int get_rooms();
    bool get_debug();
    void set_player_x(int);
    void set_player_y(int);
    void set_arrows(int);
    void set_rooms(int);
    void set_debug(bool);
    //movement
    void player_move();
    void move_north();
    void move_south();
    void move_east();
    void move_west();
    //arrow stuff
    void arrow_direction(char);
    void arrow_north();
    void arrow_south();
    void arrow_east();
    void arrow_west();
    void arrow_noise(int, int);
    //allocate events
    void assign_events();
    void assign_wumpus();
    void assign_pit();
    void assign_bats();
    void assign_gold();
    //stuff that happens after specific events
    void post_event(int);
    void post_bats();
    void post_gold();
    void post_wumpit();
    //other
    void print_map();
    void set_starting_location();
    void print_percepts();
    bool check_win();

};

#endif
