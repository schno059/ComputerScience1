#include <iostream>
using namespace std;

int main()
{
	int gigs;
	cout<<"How many gigs do you need"<<endl;
	cin>>gigs;
	if(gigs>=5)
		cout<<"$80 a month"<<endl;
	else if(gigs>=3)
		cout<<"$70 a month"<<endl;
	else if(gigs>=2)
		cout<<"$65 a month"<<endl;
	else if(gigs>=1)
		cout<<"$55 a month"<<endl;
	else
		cout<<"Error: Enter a positive, nonzero integer"<<endl;
}
