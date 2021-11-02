#include <iostream>
using namespace std;

int main()
{
	//Title: The Apple Tree
	//Name: Jacob Schnoor
	//Lab: M W Alworth Hall 177
	//Description: Simple program for calculating
	//distance of a free falling object based
	//on time in the air (assuming it started
	//at rest and air resistance is negligible)

	//declare variables, instantiate acceleration
	double distance, time, acceleration;
	acceleration=32;
	//establish context
	cout << "\n\n\nYou are on the planet Earth on\n";
	cout << "a regular sunny day with no gravitational\n";
	cout << "anomalies to behold. You witness an apple\n";
	cout << "spontaneously detach from a tree\n\n";
	cout << "Before it strikes the ground, you\n";
	cout << "count the time it is in free fall\n";
	cout << "Enter the number of seconds it spends\n";
	cout << "falling prior to contact with the ground:\n";
	//prompt user input
	cin >> time;
	//process information
	distance = (acceleration * time * time)/2;
	//display results
	cout << "After counting a free fall time of\n";
	cout << time <<" seconds, you determine the apple\n";
	cout << "must have fallen " << distance << " feet\n";
	cout << "\nProgram Complete\n\n\n";
	//thats it
}
