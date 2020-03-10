#include "child.h"

#include <iostream>
#include <string>

//name:: child
//description: constructor for child
child::child(){
	set_name("I am a child");
}

void child::print(){
	cout << "The Right Honorable " << get_name() << endl;
}
