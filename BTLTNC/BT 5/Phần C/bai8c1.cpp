#include<bits/stdc++.h>
using namespace std;
int LamTron(double N)
{
    int a=N;
    double b=a+0.5;
    if (N<b)
        return a;
    else return a+1;
}
int main()
{
    double N;
    cin>>N;
    cout<<LamTron(N);
}

