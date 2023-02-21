#include <iostream>
using namespace std;

int main()
{
    int a=0;
    int n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            {
                if (j+a>0)
                    cout<<j+a-n;
                else cout<<j+a<<" ";
            }
        a++;
        cout<<endl;
    }

}
