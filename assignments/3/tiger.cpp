#include "tiger.h"
#include <string>

using namespace std;

string tiger::namegen() {
  srand(time(0));

  /*
    Famous lions and names meaning lion
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
