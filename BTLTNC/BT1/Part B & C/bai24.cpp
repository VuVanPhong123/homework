#include <bits/stdc++.h>
using namespace std;
int main(){
	int day,month,year;
	int n;
	cout << "Day: ";
	cin >> day;
	cout << endl << "Month: ";
	cin >> month;
	cout << endl << "Year: ";
	cin >> year;
	if ( month >=3 && month<=12 )
		month=month;
	else if ( month == 1 )
		{
			month = 13;
			year--;
		}

	else if ( month == 2 )
		{
			month = 14;
			year--;
		}
	int y = year % 100;
	int c = year / 100;
	int w =( day + ( (13 * (month + 1) )/5) + y +(y / 4) +(c / 4) + 5 * c) % 7;
	switch (w)
		{
			case 0:
				{
					cout<<"Today is Saturday";
					break;
				}
			case 1:
				{
					cout<<"Today is Sunday";
					break;
				}
			case 2:
				{
					cout<<"Today is Monday";
					break;
				}
			case 3:
				{
					cout<<"Today is Tuesday";
					break;
				}
			case 4:
				{
					cout<<"Today is Wednesday";
					break;
				}
			case 5:
				{
					cout<<"Today is thursday";
					break;
				}
			case 6:
				{
					cout<<"friday";
					break;
				}
		}
}
