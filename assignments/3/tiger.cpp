#include "tiger.h"
#include <string>

using namespace std;
tiger::tiger(){
  set_name("noname");
  set_age(-1);
}
// birth() - allocates name and sets age to zero
void tiger::birth(){
  set_name(namegen());
  set_age(0);
}
// bought() - generates name and sets age to 48
void tiger::bought(){
  set_name(namegen());
  set_age(48);
}
// namegen() - Randomly selects a name from array.
string tiger::namegen() {
  srand(time(0));

  /*
    Famous tigers, cats and other feline related names
  */
  string names [40] = {
    "Tony the Tiger", "Shere Khan", "Tigger", "Richard Parker", "Onitsuka",
    "Babur", "Tigris", "Kitten", "Garfield", "Hobbes",
    "Tygra", "Lev", "Kovu", "Satoru Sayama", "Fray Tormenta",
    "Oliver", "Jiji", "Ossama", "Sarabi", "Salem",
    "Singapura", "Shishio", "Shetani", "Shange", "Zira",
    "Diego", "Meowth", "Snowball", "Bast", "Dilan",
    "Corin", "Jato", "Kefira", "Kosey", "Mr. Jinks",
    "Jonesy", "Loeb", "Jansher", "Hamza", "Gur"
  };

  return names[rand() % 40];
}
