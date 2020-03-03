#ifndef GAME_H
#define GAME_H

#include "room.h"
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "escape.h"
#include "empty.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class game {
  private:
    bool alive, has_gold, can_flee, w_alive, debug;
    int p_x, p_y, n_rooms, p_arrows, w_x, w_y,
        b1_x, b1_y, b2_x, b2_y, pi_x, pi_y, g_x, g_y;
    wumpus w;
    bats b1,b2;
    pit p;
    escape e;
    gold g;
    empty empt;

  public:
    vector<vector<room>> r;
    game();
    game(int, bool);
    //accessors
    int get_p_x();
    int get_p_y();
    int get_w_x();
    int get_w_y();
    int get_b1_x();
    int get_b1_y();
    int get_b2_x();
    int get_b2_y();
    int get_pi_x();
    int get_pi_y();
    int get_g_x();
    int get_g_y();
    int get_n_rooms();
    int get_p_arrows();
    bool get_alive();
    bool get_has_gold();
    bool get_can_flee();
    bool get_w_alive();
    bool get_debug();
    //mutators
    void set_p_x(int);
    void set_p_y(int);
    void set_n_rooms(int);
    void set_p_arrows(int);
    void set_alive(bool);
    void set_has_gold(bool);
    void set_can_flee(bool);
    void set_w_alive(bool);
    void set_debug(bool);
    //player movement
    void player_move();
    void move_north();
    void move_south();
    void move_east();
    void move_west();
    //arrow stuff
    void arrow_direction();
    void arrow_north();
    void arrow_south();
    void arrow_east();
    void arrow_west();
    //event related stuff
    void assign_events();
    void assign_wumpus();
    void assign_pit();
    void assign_bats();
    void assign_gold();

    void post_event(int);
    void post_bats();
    void post_gold();
    void post_wumpit();
    void post_escape();

    void copy_events();
    //other
    void turn();
    void print_map();
    void wumpwake();
    bool killwump(int,int);
    void set_starting_location();
    void print_percepts();
    void game_loop();
    void clear_terminal();
    void get_char(char &);
};

  void save_lines(int &, int &);
  void check_args(int &, int &, int, char **);
#endif
