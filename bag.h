void swap(Item& first,Item& second);
//Pre:first and second are both initialized objects of type Item
//Post:the variables first and second exchange values

class Bag
{
private:
        Item contents[15];//array of Item objects. Size of 15
        int n;//represents how many slots in Bag are occupied
public:
        bool add(string item);
	//Pre:item is a valid string
	//Post:adds Item object named after the string to the Bag
	//if there is space. Returns whether or not addition was successful
        bool remove(string item);
	//Pre:item is a valid string
	//Post:if an Item named after the string is in the bag, it is removed.
	//Returns whether or not anything was removed
        void clear();
	//Pre:None
	//Post:Bag is emptied
        int getFrequencyOf(string item);
	//Pre:item is a valid string
	//Post:returns the number of occurrences of item in the Bag 
        bool isEmpty();
	//Pre:None
	//Post:Returns whether or not the bag is empty
        bool contains(string item);
	//Pre:item is a valid string
	//Post:returns whether or not item occurs at least once in the bag
        int getSize();
	//Pre:none
	//Post:returns current value for n (how many slots out of 15 are occupied)
        void display();
	//Pre:none
	//Post:prints all items currently within Bag to the screen
        Bag(){n=0;}
};
bool Bag::add(string item)
{
        if(n<15)//if the bag is not currently full
        {
                contents[n]=Item(item);//the next open spot is an Item called item
                n++;
        }
        return n<15;//tells if the addition was successful
}

bool Bag::remove(string item)
{
        for(int i=0; i<n; i++)//increment through all occupied Bag slots
        {
                if(contents[i].getName()==item)//if the item is what we're looking for
                {
                        swap(contents[i],contents[n-1]);//swap it with the last
                        n--;//decrease the size
                        return true;//removal successful
                }
        }
        return false;//it was never found. removal failed
}
void Bag::clear()
{
        n=0;//all Bag slots now open
}
int Bag::getFrequencyOf(string item)
{
        int count=0;
        for(int i=0; i<n; i++)
        {
                if(contents[i].getName()==item)//if its what we're looking for
                        count++;//add 1
        }
        return count;//return how many times it shows up
}
bool Bag::isEmpty()
{
        return n==0;//is the size zero?
}
bool Bag::contains(string item)
{
        for(int i=0; i<n; i++)
        {
                if(contents[i].getName()==item)
                        return true;//something matches our search
        }
        return false;//nothing matches our search
}
int Bag::getSize()
{
        return n;//return current size
}
void Bag::display()
{
        if(isEmpty())//nothing to display
                cout<<"This bag is empty"<<endl;
        else//something to display
        {
                cout<<"This bag has "<<getSize() <<" item(s) :\n\n";
                for(int i=0; i<n; i++)//go through all Items
                {
                        cout<<contents[i].getName()<<endl;//print the name
                }
                cout<<"\n";
        }
}
void swap(Item& first, Item& second)
{
        Item temp=first;
        first=second;//swaps first and second Item values
        second=temp;
}

