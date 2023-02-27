#include<bits/stdc++.h>
using namespace std;
int main()
{
   int m,n;
   int count=0;
   cin>>m>>n;
   char mang[m+2][n+2];
   for (int i=1;i<m+1;i++)
        for (int j=1;j<n+1;j++)
            mang[i][j]='.';
   for (int i=1;i<m+1;i++)
        for (int j=1;j<n+1;j++)
            cin>>mang[i][j];
   for (int i=1;i<m+1;i++)
        for (int j=1;j<n+1;j++)
            if (mang[i][j]=='.')
                {
                    for (int l=i-1;l<=i+1;l++)
                        for (int k=j-1;k<=j+1;k++)
                            if (mang[l][k]=='*')
                                count++;
                    mang[i][j]=count+48;
                    count=0;
                }
     for (int i=1;i<m+1;i++)
        {
            for (int j=1;j<n+1;j++)
                cout<<mang[i][j]<<" ";
            cout<<endl;
        }



}
