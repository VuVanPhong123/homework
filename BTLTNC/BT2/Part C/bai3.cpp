#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int a=x;
    for (int i=0;i<x;i++)
        {
            for (int j=1;j<a;j++)
                cout<<" ";
            for (int k=0;k<(x-a)*2+1;k++)
                cout<<"*";
            cout<<endl;
            a--;

        }
}
