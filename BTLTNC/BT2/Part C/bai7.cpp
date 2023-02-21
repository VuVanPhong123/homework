#include <iostream>
using namespace std;

int main()
{
    int a=-9;
    int n;
    while (true)
   {
        cin>>n;
        if (n<0)
        {
            cout<<n;
            break;
        }
        if (n!=a)
            cout<<n<<" ";
        a=n;
   }
}
