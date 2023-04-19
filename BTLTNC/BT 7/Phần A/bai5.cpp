#include <iostream>
using namespace std;

char* weird_string() {
   char c[] = "123345";
   return c;
}

int main() {
   char* ptr = weird_string();
   cout << ptr << endl;
   return 0;
}
