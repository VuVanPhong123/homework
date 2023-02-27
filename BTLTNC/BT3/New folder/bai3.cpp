#include<bits/stdc++.h>
using namespace std;
int kiemtrasodoiguong(int n)
{
    int mang[7];
    int c=0;
    bool b=true;
    while(n!=0)
        {
            mang[c]=n%10;
            n=n/10;
            c++;
        }
    for (int i=0;i<c/2;i++)
        if (mang[i]!=mang[c-i-1])
            {
                b=false;
            }
    if (b==true)
        return 1;
    else return 0;
}
int main()
{
    int count=0;
    int n;
    cin>>n;
    int mang[n][2];
    for (int i=0;i<n;i++)
        for (int j=0;j<2;j++)
            cin>>mang[i][j];
    for (int i=0;i<n;i++)
        {
            for (int j=mang[i][0];j<=mang[i][1];j++)
                if (kiemtrasodoiguong(j)==1)
                    count++;
            cout<<count<<endl;
            count=0;
        }

}
