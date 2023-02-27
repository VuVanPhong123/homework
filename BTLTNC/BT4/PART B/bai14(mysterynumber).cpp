#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mang[n];
    for (int i=0;i<n;i++)
        cin>>mang[i];
    int mang2[n+1];
    for (int i=0;i<n+1;i++)
        {
            cin>>mang2[i];
            for (int j=0;j<n;j++)
            {
                if (mang2[i]==mang[j])
                    {
                        mang2[i]=-1;
                        mang[j]=-1;
                        break;
                    }
            }
        }
    for (int i=0;i<n+1;i++)
        if (mang2[i]!=-1)
            {
                cout<<mang2[i];
                break;
            }


}
