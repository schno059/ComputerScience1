#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
	//declare variables
	int rnum,guess;
	srand(time(0));
	rnum=rand()%100+1;
	//input
	cout<<"\nGuess a number 1-100\n";
	cin>>guess;
	//processing
	while(guess!=rnum)
	{
		if(guess<rnum)
		{
			cout<<"Too low\n";
		}
		else
		{
			cout<<"Too high\n";
		}
		cout<<"Guess again:\n";
		cin>>guess;
	}
	//output
	cout<<"Correct!\n";
}
