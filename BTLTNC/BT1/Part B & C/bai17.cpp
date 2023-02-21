#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	if (x%100==0)
	{
		if (x%400==0)
			cout<<"nam nhuan";
		else cout<<"nam khong nhuan";
	}
	else
	{
		if (x%4==0)
			cout<<"nam nhuan";
		else cout<<"nam khong nhuan";
	}
}
