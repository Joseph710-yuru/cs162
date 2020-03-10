#include "base.h"

#include <string>
#include <iostream>

using namespace std;

//name: base
//description: basic constructor
base::base(){
	name = "undefined";
}

//name: get_name
//description: accessor for name
string base::get_name() {
	return name;
}

//name: set_name
//description: mutator for name
void base::set_name(string n){
	name = n;
}

//name:: print
//description: prints contents of name
void base::print(){
	cout << "Base name: " << name << endl;
}

