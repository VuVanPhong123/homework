#include<bits/stdc++.h>
using namespace std;
int main()
{

    int m,n;
    cin>>m>>n;
    int mang[m][n];
    int q=m;
    int w=n;
    int a=1;
    int b=1;
    int c=0;
    int d=0;
    int number=1;
    while (number<=q*w)
    {
            for (int i=0;i<n;i++)
                {
                    mang[c][d]=number;
                    d++;
                    number++;
                }
            b=-1;
            d--;
            m--;
            c++;
            for (int i=0;i<m;i++)
                {
                    mang[c][d]=number;
                    number++;
                    c++;
                }
            c--;
            n--;
            a=-1;
            d--;
            for (int i=0;i<n;i++)
                {
                    mang[c][d]=number;
                    number++;
                    d--;
                }
            d++;
            m--;
            a=1;
            c--;
            for (int i=0;i<m;i++)
            {
                mang[c][d]=number;
                number++;
                c--;
            }
            b=1;
            c++;
            d++;
            n--;
    }
    for (int i=0;i<q;i++)
    {
        for (int j=0;j<w;j++)
            cout<<setw(3)<<mang[i][j];
        cout<<endl;
    }
}
