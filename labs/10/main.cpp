#include "base.h"
#include "child.h"

#include <iostream>

using namespace std;

int main() {
	base b, *bptr;
	child c, *cptr;
	
	cout << "base: ";
	b.print();
	cout << "child: ";
	c.print();

	cptr = &c;
	bptr = cptr;
	
	cout << "bptr prints child function" << endl << "bptr: ";

	bptr->print();

	return 0;
}
