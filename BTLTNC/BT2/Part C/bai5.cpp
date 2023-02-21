#include <iostream>
using namespace std;
void docso(int x)
{
	 if (x==1)
        cout<<"one";
    else if (x==2)
        cout<<"two";
    else if (x==3)
        cout<<"three";
    else if (x==4)
        cout<<"four";
    else if (x==5)
        cout<<"five";
    else if (x==6)
        cout<<"six";
    else if (x==7)
        cout<<"seven";
    else if (x==8)
        cout<<"eight";
    else if (x==9)
        cout<<"nine";
}
void docso2(int x)
{
	 if (x==2)
        cout<<"twenty";
    else if (x==3)
        cout<<"thirty";
    else if (x==4)
        cout<<"forty";
    else if (x==5)
        cout<<"fifty";
    else if (x==6)
        cout<<"sixty";
    else if (x==7)
        cout<<"seventy";
    else if (x==8)
        cout<<"eighty";
    else if (x==9)
        cout<<"ninety";

}
void docso3(int x)
{
	if (x==0)
	 cout<<"ten";
	else if (x==1)
        cout<<"eleven";
    else if (x==2)
        cout<<"twelve";
    else if (x==3)
        cout<<"thirteen";
    else if (x==4)
        cout<<"fourteen";
    else if (x==5)
        cout<<"fifteen";
    else if (x==6)
        cout<<"sixteen";
    else if (x==7)
        cout<<"seventeen";
    else if (x==8)
        cout<<"eighteen";
    else if (x==9)
        cout<<"nineteen";
}
void doc3so(int a, int b, int c)
{
	if (a<10)
		{
			docso(a);
			if (a!=0)
				cout<<" hundred ";
		}
	if (b!=1)
		{
			docso2(b);
			if (b!=0&&b<10)
				cout<<"-";
			docso(c);
		}
	else if (b==1)
		{
			void (docso3(c));
		}
}
int main()
{
	int k=8;
	int x;
	cin>>x;
	int a;
	a=x;
	if (x<0)
	{
	cout<<"negative ";
	x=-x;
	a=x;
	}

	int mang[9];
	for (int i=0;i<9;i++)
		mang[i]=10;
	while(x>0)
	{
		mang[k]=x%10;
		x=x/10;
		k--;
	}
	doc3so(mang[0],mang[1],mang[2]);
	if (mang[0]!=10||mang[1]!=10||mang[2]!=10)
		cout<<" million ";
	doc3so(mang[3],mang[4],mang[5]);
	if (a>=1000&&(mang[3]!=0||mang[4]!=0||mang[5]!=0))
		cout<<" thousand ";
	doc3so(mang[6],mang[7],mang[8]);

}
