#include<bits/stdc++.h>
using namespace std;
int KiemTraSoNT(int n)
{
    bool a=true;
    if (n==1)
        return 0;
    else if (n==2)
        return 1;
    else {
        for (int i=2;i<n;i++)
            {
                if (n%i==0)
                    {
                        a=false;
                        break;
                    }

            }
        if (a==true)
            return 1;
        else return 0;
    }
}
int main()
{
    int n;
    cin>>n;
    int a=0;
    for (int i=1;i<n;i++)
        if (KiemTraSoNT(i)==1)
            a++;
    cout<<a;


}
