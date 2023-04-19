#include<bits/stdc++.h>
using namespace std;
void random(int n,int mang[])
{

    for (int i=0;i<n-2;i++)
        for (int j=i+1;j<n-1;j++)
            for (int k=j+1;k<n;k++)
                if ((mang[i]+mang[j]+mang[k])%25)
                    cout<<mang[i]<<" "<<mang[j]<<" "<<mang[k]<<endl;
}
int main()
{
    int N;
    cin>>N;
    srand(time(NULL));
    int mang[N];
    for (int i=0;i<N;i++)
        mang[i]=rand()%50;
    random(N,mang);
}

