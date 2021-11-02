#include <iostream>
#include <string>

using namespace std;

/*
	Title: Bag ADT
	Name: Jacob Schnoor
	Lab: MWAH 177 9:00
	Description: Explores the possible use cases for an Abstract Data Type using
	a bag as an example object. Can perform basic functions such as adding, removing,
	searching, emptying, etc.
*/

class Bag//the abstract data type for a bag object
{
private://these variables cannot be altered by client except through the lower functions
	string contents[15];
	int n;
public:
	//Pre: An instance of Bag exists and 'item' is a valid string
	//Post: See side comments for each function
	bool add(string item);//attempts to add item to list, returns false if bag is full
	bool remove(string item);//attempts to remove item from list, returns false if item is not found
	void clear();//empties list
	int getFrequencyOf(string item);//returns number of occurences of item
	bool isEmpty();//tells whether or not the bag is empty
	bool contains(string item);//tells whether or not the bag has item somewhere in it
	int getCurrentSize();//returns the number of occupied slots
	void display();//displays status of the bag
	Bag();//default constructor
};

void swap(string& first, string& second);
//Pre: first and second are initialized strings
//Post: The values of first and second will swap with each other

int main() {
   std::cout<<std::boolalpha;//formats booleans to print using words
   Bag grabBag;//instantiates Bag class
   string item;//temporary item variable used at various times

   // Introduction
   cout << "Welcome to the bag manipulator program"<<endl;
   cout << "Here we can use an Abstract Data Type to simulate a real bag!"<<endl;
   cout << "Enter an item : ";
   getline(cin, item);
   while (item != "STOP") {//continue program so long as user does not wish to stop
	if(item=="HELP")//Handles each case for specific command words
	{//and runs respective functions on Bag
		cout<<"\nCommand List:\n\n";
		cout<<"'HELP' - Show all commands\n";
		cout<<"'STOP' - End program\n";
		cout<<"'RMV' - Remove a specified item from the bag\n";
		cout<<"'CLR' - Empty the bag\n";
		cout<<"'GFO' - Get the frequency of a specified item\n";
		cout<<"'ISE' - Check if the bag is empty\n";
		cout<<"'CTN' - Check if the bag contains a specified item\n";
		cout<<"'GCS' - Get the current size of the bag\n";
		cout<<"'DSP' - Display current bag status\n\n";
	}
	else if(item=="RMV")
	{
		cout<<"What item would you like to remove? : ";
		getline(cin, item);
		cout<<"\nItem Removed : "<<grabBag.remove(item)<<endl;
	}
	else if(item=="CLR")
	{
		grabBag.clear();
		cout<<"Bag Cleared"<<endl;
	}
	else if(item=="GFO")
	{
		cout<<"What item do you want to get the frequency of? : ";
		 getline(cin, item);
		cout<<"\nThe item '"<<item<<"' exists in "<<grabBag.getFrequencyOf(item)<<" locations in the bag"<<endl;
	}
	else if(item=="ISE")
	{
		cout<<"Bag Empty : "<<grabBag.isEmpty()<<endl;
	}
	else if(item=="CTN")
	{
		cout<<"Enter a search query : ";
	      getline(cin, item);
		cout<<"Bag contains '"<<item<<"' : "<<grabBag.contains(item)<<endl;
	}
	else if(item=="GCS")
	{
		cout<<"The bag currently has "<<grabBag.getCurrentSize()<<" of its 15 slots occupied"<<endl;
	}
	else if(item=="DSP")
	{
		grabBag.display();
	}
	else//If no command is entered, insert the word as an entry
	{
		grabBag.add(item);
	}
	cout << "Enter an item or command (type 'HELP' for list): ";
      getline(cin, item);//prompt and obtain input
   }
	cout<<"Paper or plastic??? Hahahahaha"<<endl;//end program
	cout<<"Don't answer because the program's over"<<endl;
}
//Bag object functions. See declaration above for details
bool Bag::add(string item)
{
	if(n<15)
	{
		contents[n]=item;
		n++;
	}
	return n<15;
}
bool Bag::remove(string item)
{
	for(int i=0; i<n; i++)
	{
		if(contents[i]==item)
		{
			swap(contents[i],contents[n-1]);
			n--;
			return true;
		}
	}
	return false;
}
void Bag::clear()
{
	n=0;
}
int Bag::getFrequencyOf(string item)
{
	int count=0;
	for(int i=0; i<n; i++)
	{
		if(contents[i]==item)
			count++;
	}
	return count;
}
bool Bag::isEmpty()
{
	return n==0;
}
bool Bag::contains(string item)
{
	for(int i=0; i<n; i++)
	{
		if(contents[i]==item)
			return true;
	}
	return false;
}
int Bag::getCurrentSize()
{
	return n;
}
void Bag::display()
{
	if(isEmpty())
		cout<<"This bag is empty"<<endl;
	else
	{
		cout<<"This bag has "<<getCurrentSize() <<" item(s) :\n\n";
		for(int i=0; i<n; i++)
		{
			cout<<contents[i]<<endl;
		}
		cout<<"\n";
	}
}
//Bag default constructor. Initializes size variable to 0
Bag::Bag()
{
	n=0;
}
//swap function. See above for details
void swap(string& first, string& second)
{
	string temp=first;
	first=second;
	second=temp;
}
