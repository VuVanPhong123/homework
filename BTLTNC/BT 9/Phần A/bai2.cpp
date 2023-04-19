#include <iostream>
using namespace std;

int main() {
   int a[4] = {1, 2, 3, 4};
   double b[4] = {1.0, 2.0, 3.0, 4.0};
   char c[4] = "abc";

   cout << "Size of int: " << sizeof(int) << endl;
   cout << "Size of double: " << sizeof(double) << endl;
   cout << "Size of char: " << sizeof(char) << endl;

   cout << "Size of int array: " << sizeof(a) << endl;
   cout << "Size of double array: " << sizeof(b) << endl;
   cout << "Size of char array: " << sizeof(c) << endl;

   return 0;
}
