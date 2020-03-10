#include "node.h"
#include "linked_list.h"

using namespace std;

int main(){
  linked_list l;

  l.push_back(8);

  l.push_front(7);
  l.push_front(11);
  l.push_front(13);
  l.push_back(21);
  //l.insert(3,2);

  l.print_prime();
  l.print();

  return 0;
}
