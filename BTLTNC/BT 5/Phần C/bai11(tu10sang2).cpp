#include<bits/stdc++.h>
using namespace std;
string Tu10Sang2(int a)
{
    string b;
    while(a>0)
    {
        b=char(a%2+48)+b;
        a/=2;
    }
    return b;
}
int main()
{
    int a;
    cin>>a;
    cout<<Tu10Sang2(a);

}

