#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void contextLoop();
//Pre:Program is properly initialized with standard
//namespace, and iostream, string, and fstream libs
//Post:Introduces user and handles calls to searchName function
void searchName(string name, int year);
//Pre:name is a valid string and year is a valid int between 2008 and 2017
//Post:Displays the popularity rankings for girls and boys along with the year

int main()//calls other functions
{
	/*
	Title: Baby Name Search Engine
	Name: Jacob Schnoor
	Lab: MWAH 177 9:00
	Description: Allows user to enter a name and searches through
	SSA data files to find the prevalence of that name among babies over
	the past decade
	*/
	contextLoop();
}
void contextLoop()//puts stuff into context and repeats everything
{
	string name;
	char response='n';
	cout<<"\n\n\nWelcome to the Baby Name Search Engine. You can find"<<endl;//context
	cout<<"the popularity of any name over the past decade in the United"<<endl;//and
	cout<<"States based on data from the Social Security Administration"<<endl<<endl;//instructions
	cout<<"#1 is the most popular, #2 is the second most popular, etc."<<endl;
	cout<<"'-' means that the name is not in the top 1000 for that demographic"<<endl<<endl;
	cout<<"Enter a name:"<<endl;//prompt
	cin>>name;
	while(name!="STOP"){//repeats so long as valid name is present
		cout<<"\nPopularity Rankings for "+name<<endl;
		cout<<"Year\t\t\tBoys\t\t\tGirls\n"<<endl;
		for(int i=2008; i<2018; i++)
			searchName(name,i);
		cout<<"\nEnter another name (type 'STOP' to exit):"<<endl;
		cin>>name;
	}
	cout<<endl<<"Thank you for using our service"<<endl;//ends program
}
void searchName(string name, int year)
{
	int index,boyRank,girlRank;
	boyRank=0;
	girlRank=0;//declares rank variables to display later
	string boyNames[1000];
	string girlNames[1000];//declares arrays
	string fileName("names");
	fileName+=std::to_string(year);//adjusts file name to year
	fileName+=".txt";
	ifstream fin;
	fin.open(fileName.c_str());
	for(int j=0; j<1000; j++)//fills arrays
		fin>>index>>boyNames[j]>>girlNames[j];
	for(int k=0; k<1000; k++)//goes through arrays
	{
		if(name==boyNames[k])//checks if search term matches element
			boyRank=k+1;//sets rank to index plus 1
		if(name==girlNames[k])
			girlRank=k+1;
	}
	cout<<year<<"\t\t\t";
	if(boyRank==0)//if no match was found
		cout<<"-\t\t\t";//show "-" symbol
	else
		cout<<"#"<<boyRank<<"\t\t\t";//or else show the rank
	if(girlRank==0)
		cout<<"-"<<endl;
	else
		cout<<"#"<<girlRank<<endl;
	fin.close();//close file reader
}
