#include<bits/stdc++.h>
using namespace std;
int Tu2Sang10(string a)
{
    int g=0;
    int b=1;
    for (int i=a.size()-1;i>=0;i--)
        {
            g+=(a[i]-48)*b;
            b=b*2;
        }
    return g;
}
int main()
{
    string a;
    cin>>a;
    cout<<Tu2Sang10(a);

}

