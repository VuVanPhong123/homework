#include<iostream>
using namespace std;
int main()
{
	while (true)
	{
		int n;
		cin>>n;
		if (n==-1)
			break;
		if(n%5==0)
			cout<<n/5<<endl;
		else cout<<"-1"<<endl;
	}
	cout<<"bye";
}
