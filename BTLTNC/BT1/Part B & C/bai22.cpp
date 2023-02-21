#include<iostream>
using namespace std;
int main()
{
	double Weight,height;
	cout<<"Weight=";
	cin>>Weight;
	cout<<endl;
	cout<<"height(m)=";
	cin>>height;
	double bmi=Weight/(height*height);
	cout<<"BMI="<<bmi;
}
