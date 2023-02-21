#include<iostream>
using namespace std;
int main()
{
	string f0="a";
	string f1="b";
	string f2;
	for (int i=0;i<11;i++)
		{
			cout<<"f("<<i<<")="<<f0<<endl;
			f2=f1+f0;
			f0=f1;
			f1=f2;
		}
}
