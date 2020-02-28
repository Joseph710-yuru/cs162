#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v1;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v1.push_back(23);
   vector<int> v2(v1);
   stdv.push_back(23);

   cout << "Our vector size: " << v1.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;
   cout << "Our copied vector size: " << v2.size() << endl;

   v1.push_back(22);
   v1.push_back(11);
   v2 = v1;

   cout << "v1: ";
   v1.print();
   cout << "v2: ";
   v2.print();

   cout << "v2[1]: ";
   cout << v2[1] << endl;


   return 0;
}
