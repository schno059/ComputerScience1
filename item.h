class Item//Item class definition.
{//Essentially a glorified string
public:
	Item() {name="";};//default constructor
	Item(string nm){name=nm;}//sets name
	string getName(){return name;}//gets the current name
	void setName(string nm){name=nm;}//sets the name string
private:
	string name;//private data member for name of the object
};
