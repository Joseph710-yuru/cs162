#ifndef BASE_H
#define BASE_H

#include <string>

using namespace std;

class base {
	public:
		string name;
		base();
		string get_name();
		void set_name(string);
		virtual void print();
};

#endif
