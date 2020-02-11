#include "tiger.h"
#include <string>

using namespace std;

string tiger::namegen() {
  srand(time(0));

  /*
    Famous lions and names meaning lion
  */
  string names [40] = {
    "Cowardly", "Asad", "Amra", "Aryeh", "Aslan",
    "Jad-Bal-Ja", "Kefir", "Kojishi", "Laish", "Leander",
    "Leon", "Lev", "Kovu", "Simba", "Mufasa",
    "Leonardo", "Nala", "Ossama", "Sarabi", "Shir",
    "Singapura", "Shishio", "Shetani", "Shange", "Zira",
    "Cirilla", "Calanthe", "Shiku", "Bast", "Dilan",
    "Corin", "Jato", "Kefira", "Kosey", "Layth",
    "Leijona", "Loeb", "Jansher", "Hamza", "Gur"
  };

  return names[rand() % 40];
}
