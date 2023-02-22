#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=n;
    for (int i=0;i<n;i++)
    {
        for (int i=0;i<n-a;i++)
            cout<<" ";
        for (int i=0;i<2*a-1;i++)
            cout<<"*";
        cout<<endl;
        a--;
    }
}
