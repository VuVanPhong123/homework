#include <iostream>
using namespace std;
string daonguockitu(string a)
{
    int n=a.size();
    string b=a;
    for (int i=0;i<n;i++)
        b[i]=a[n-1-i];
    return b;
}
int main()
{
    int n;
    cin>>n;
    string mang[n];
    for (int i=0;i<n;i++)
        cin>>mang[i];
    for (int i=0;i<n-1;i++)
    {

        if (mang[i].size()%2==1)
            for (int j=i+1;j<n;j++)
                if (daonguockitu(mang[i])==mang[j])
                    {
                        cout<<mang[i].size()<<" ";
                        cout<<mang[i][mang[i].size()/2];

                    }
    }

}
