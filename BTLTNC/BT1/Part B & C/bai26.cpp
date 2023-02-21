#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double mang[n];
	cin>>mang[0];
	double mean,max,min;
	max =mang[0];
	min=mang[0];
	mean=mang[0];

	for (int i=1;i<n;i++)
		{
			cin>>mang[i];
			if (max<mang[i])
				max =mang[i];
			if (min>mang[i])
				min=mang[i];
			mean=mean+mang[i];
		}
	cout<<"Mean: "<<mean/n<<endl<<"Max: "<<max<<endl<<"Min: "<<min;
}
