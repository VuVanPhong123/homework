#include <bits/stdc++.h>
using namespace std;
string kiemtra(int *a,int n)
{
    int tongtrai=0;
    int tongphai=0;
    for (int i=1;i<n;i++)
        {
            tongphai+=a[i];
        }
    if (tongtrai==tongphai)
        return "YES";
    else
    {
        for (int i=0;i<n-1;i++)
            {
                tongtrai+=a[i];
                tongphai-=a[i+1];
                if (tongtrai==tongphai)
                    {
                    goto endloop;
                    }
            }
    return "NO";
    endloop:
    return "YES";
    }
}
int main()
{
    int n;
    cin>>n;
    int a;
    int **mang1=new int *[n];
    for (int i=0;i<n;i++)
    {
        cin>>a;
        mang1[i]=new int [a];
        for (int j=0;j<a;j++)
            cin>>mang1[i][j];
        cout<<kiemtra(mang1[i],a)<<endl;
    }
}
