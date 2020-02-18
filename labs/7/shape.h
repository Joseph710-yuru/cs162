#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape {
   private:
      string name;
      string color;
   public:
      Shape();
      string get_name();
      string get_color();
      void set_name(string);
      void set_color(string);
      int area();
      bool operator< (Shape &);
};

#endif
