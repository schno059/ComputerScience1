#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct item
{
	string description;
	int quantity;
};
int main()
{
	srand(time(0));
	item myItems[5];
	for(int i=0; i<5; i++)
	{
		cout<<"\nEnter description for item "<<i<<endl;
		getline(cin,myItems[i].description);
		myItems[i].quantity=rand()%100;
	}
	cout<<"\nResults\n\n";
	for(int i=0; i<5; i++)
	{
		cout<<myItems[i].description<<" "<<myItems[i].quantity<<endl;
	}
	cout<<"\nProgram complete\n";
}
