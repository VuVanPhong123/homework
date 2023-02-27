#include<bits/stdc++.h>
using namespace std;
int main()
{
    string c;
    cin>>c;
    int n=c.size();
    for (int i=0;i<n/2;i++)
        if (c[i]!=c[n-1-i])
            {
                cout<<"No";
                goto endloop;
            }
    cout<<"Yes";
    endloop:
    return 0;


}
