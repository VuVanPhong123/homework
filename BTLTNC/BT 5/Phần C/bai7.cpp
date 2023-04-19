#include<bits/stdc++.h>
using namespace std;
int drawing(int n)
{
    int a=n;
    while(a>0)
    {
        for (int i=0;i<a;i++)
            cout<<" ";
        for (int i=0;i<(n-a)*2+1;i++)
            cout<<"*";
        a--;
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    drawing(n);
}

