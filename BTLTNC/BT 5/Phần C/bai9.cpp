#include<bits/stdc++.h>
using namespace std;
int randomNumber(int n)
{
    srand(time(NULL));
    int r = rand();
    return r % n;
}
int main()
{
    double N;
    cin>>N;
    cout<<randomNumber(N);
}

