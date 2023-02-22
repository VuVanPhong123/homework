#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n<2)
        cout<<"no";
    else if (n==2)
        cout<<"yes";

    else
    {
        for (int i=2;i<n;i++)
            if (n%i==0)
            {
                cout<<"no";
                goto endloop;
            }
    }

    cout<<"yes";
    endloop:
    return 0;
}
