#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	if (a<=0||b<=0||c<=0)
		cout<<"invalid";
	else if (a+b<=c||a+c<=b||b+c<=a)
		cout<<"invalid";
	else
	{
		double s=(a+b+c)/2;
		double area = sqrt(s*(s-a)*(s-b)*(s-c));
		cout<<"AREA="<<area;
	}
}
