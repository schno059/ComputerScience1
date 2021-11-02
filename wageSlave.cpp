#include <iostream>
using namespace std;

int main()
{
	/*Title: A Cog in the Machine
	Name: Jacob Schnoor
	Lab: Project 6 Page 107
	Description: Your pitiful existence is defined
	by a cycle of labor for an affluent bourgeois
	devil that you call "master". Use this program
	to determine how many bread crumbs you get to scrape
	up from your work. If you're lucky, it might just be
	enough to satisfy your immediate needs and prevent 
	popular revolt.*/

	//declare all necessary variables
	bool keepGoing=false;
	int dependents=0;
	double hours=0,gross=0;
	char temp='a';
	//introduce user to the program
	cout<<"\nCongratulations! You have a job that pays you a whopping\n";
	cout<<"$16.78 per hour with overtime benefits if you exceed 40 hours\n";
	cout<<"a week. Now let's see how much legal tender you raked in!\n";
	do{
		//input hours and dependents for the calculations
		cout<<"\nEnter the number of hours you worked this week\n";
		cin>>hours;
		cout<<"And how many dependents do you have?\n";
		cin>>dependents;
		//treat cases of regular work and overtime separately
		if(hours>40)
		{
			hours-=40;
			gross=hours*1.5*16.78;
			gross+=40*16.78;
			hours+=40;
		}
		else
		{
			gross=hours*16.78;
		}
		//tell user their amount of money and amount withheld
		cout<<"Subtotal: $"<<gross<<"\n";
		cout<<"-$"<<gross*.06<<" for Social Security Tax\n";
		cout<<"-$"<<gross*.14<<" for Federal Income Tax\n";
		cout<<"-$"<<gross*.05<<" for State Income Tax\n";
		cout<<"-$10 for union dues\n";
		gross=(gross*.75)-10;
		//make special case for 3 or more dependents
		if(dependents>=3)
		{
			cout<<"-$35 for extra health insurance costs to cover your "<<dependents<<" dependents\n";
			gross-=35;
		}
		cout<<"Total: $"<<gross<<"\n\n";
		//ask for continuation
		cout<<"Would you like to calculate your income again? (Y/N)\n";
		cin>>temp;
		//convert y for "yes" into a continuation request
		if(temp=='y'||temp=='Y')
		{
			keepGoing=true;
		}
		//assume all non-yes responses are equivalent to "no"
		else
		{
			keepGoing=false;
		}
	}while(keepGoing==true);
	//if it's not still going, it's over
	cout<<"Ending Program...\n";
	cout<<"Thank you for using our service\n";
}

