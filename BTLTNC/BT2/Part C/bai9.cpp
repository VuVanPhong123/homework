#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mina,minb;
    int a,b;
    cin>>a>>b;
    mina=a;
    minb=b;
    for (int i=0;i<n-1;i++)
        {
            cin>>a;
            cin>>b;
            if(mina>a)
                mina=a;
            if (minb>b)
                minb=b;
        }
    cout<<minb*mina;

}
