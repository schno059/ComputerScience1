#include <iostream>
#include <cmath>//math library. Must import for pow function
using namespace std;

/*Title: Calorie Counter
  Name: Jacob Schnoor
  Project: 4
  Hour: 9:00
  Description: Calculator that takes in weight, physcial activity, and nutrition
  facts in order to calculate how much of a given food someone can eat and still maintain
  a constant body weight
*/

void processCycle(double& pounds, double& requiredEnergy);//declare all function headers up front
double basal(double pounds);
double exercise(double weight);
void digest(double& nrg);
void food(double energy);
void endProgram();

int main()//main function
{
	char ans;
	double weight, energyNeeded;//variable declarations
	cout<<"\n\nWelcome to the calorie counter, where you"<<endl;
	cout<<"use your weight, physical activity, and nutrition facts"<<endl;
	cout<<"to estimate how much you should be eating regularly"<<endl;//introduction
	do
	{
		processCycle(weight,energyNeeded);//goes to processCycle function
		cout<<"\nWould you like to calculate another lifestyle?(y/n)"<<endl;
		cin>>ans;
	}while(toupper(ans)=='Y');//allows optional repetition
	endProgram();//goes to endprogram function below
}
void processCycle(double& pounds, double& requiredEnergy)//acts as central hub calling various other functions
{
	cout<<"\nTo start off, how much do you weigh (in lbs)?"<<endl;
	cin>>pounds;//gets value for weight
	requiredEnergy=basal(pounds);//gets bmr from other function
	cout<<"\nOkay, a quick estimate of your basal metabolic rate suggests"<<endl;
	cout<<"you need to consume at least "<<requiredEnergy<<" calories"<<endl;
	cout<<"per day to maintain basic physiological functions like breathing"<<endl;//display bmr result
	cout<<"\nNow let's account for exercise"<<endl;
	requiredEnergy+=exercise(pounds);//adds on result of exercise function
	cout<<"\nIt would appear you need "<<requiredEnergy<<" calories so far"<<endl;//displays result
	digest(requiredEnergy);//moves to digest function
	food(requiredEnergy);//moves to food function
}
double basal(double pounds)//bmr calculator
{
	double result=pounds/2.2;
	result=pow(result,0.756);
	result*=70;//converts weight to estimated bmr
	return result;//based on nutrition equation
}
double exercise(double weight)//accounts for caloric needs in regard to physical activity
{
	double intensity, minutes;//declare variables
	cout<<"How many minutes do you engage in physical activity on an average day?"<<endl;
	cin>>minutes;//user inputs exercise time
	cout<<"\nHere's a few activities with their respective"<<endl;
	cout<<"'intensity' values which represent how strenuous they are"<<endl;
	cout<<"\tActivity\t\t\tIntensity"<<endl;
	cout<<"\tRunning at 10 mph\t\t17"<<endl;
	cout<<"\tRunning at 6 mph\t\t10"<<endl;
	cout<<"\tBasketball\t\t\t8"<<endl;
	cout<<"\tWalking 1 mph\t\t\t1"<<endl;//provides examples to base input off of
	cout<<"How intense is your typical activity?"<<endl;
	cin>>intensity;//user inputs intensity
	return 0.0385*minutes*intensity*weight;//sends back calculated caloric needs
}
void digest(double& nrg)//function to account for digestive requirements
{
	nrg*=1.01;//increases caloric need by 10%
	cout<<"But nutritionists estimate about 10% of those calories go directly"<<endl;
	cout<<"to digestion meaning you'll need "<<nrg<<" calories overall"<<endl;//displays result
}
void food(double energy)//puts calories into context
{
	double serving;//declare variable
	cout<<"\nNow think of a favorite food"<<endl;
	cout<<"How many calories are in one serving of that item?"<<endl;
	cin>>serving;//user inputs calories of a given food item
	cout<<"\nThen that means you can eat "<<energy/serving<<" servings"<<endl;
	cout<<"of that food in one day"<<endl;//calculates and displays how much can be eaten
}
void endProgram()//handles concluding sentiments
{
	cout<<"\nThank you for using our service"<<endl;
	cout<<"We hope you use this information to make"<<endl;
	cout<<"informed dietary choices in the future"<<endl;
	cout<<"..."<<endl;
	cout<<"END OF PROGRAM"<<endl;//informs user that the program has terminated
}
