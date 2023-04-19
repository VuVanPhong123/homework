#include <iostream>

using namespace std;

int n,k,chucai[100],tu[100];

void ketqua()
{
    for (int i=0;i<k;i++)cout << (char)tu[i];
    cout << endl;
}

void hoanvi(int i)
{
    for (int j=97;j<97+n;j++)
    {
        if (chucai[j]==1)
        {
            tu[i]=j;
            chucai[j]=0;
            if (i==k-1)ketqua();
            else hoanvi(i+1);
            chucai[j]=1;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i=0;i<100;i++)chucai[i]=1;
    hoanvi(0);
    return 0;
}
