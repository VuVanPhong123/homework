#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mang[n];
    cin>>mang[0];
    bool b=false;
    for (int i=1;i<n;i++)
        {
            cin>>mang[i];
            for (int j=0;j<i;j++)
                if (mang[i]==mang[j])
                    b=true;
        }
    if (b==true)
        cout<<"Yes";
    else
        cout<<"No";

}
