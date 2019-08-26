//Header File for Class Bag (as a sample of an implementation of ADT
#define _Bag
#include<iostream>
using namespace std;
const int CMAX = 100;
//Class Definition (Interface)
class CBag
{
private:
	char bagStorage[CMAX];
	int size;
public:
	CBag(); //This is a default constructor
	int getSize();
	bool isEmpty();
	void add(char item);
	void remove(char item);
	void display();
	void clear();
	bool contains(char item);
};
//Definition of Constructors
CBag::CBag()
{
	size = 0;
}
//Definition of Methods (Member Functions)
int CBag::getSize()
{
	return size;
}
bool CBag::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}
void CBag::add(char item)
{
	if (size == CMAX)
		cout << "The bag is full!" << endl;
	else
	{
		bagStorage[size] = item;
		size++;
	}
}
void CBag::display()
{
	cout << "The bag contains following integers: " << endl;
	for (int i = 0; i < size; i++)
		cout << bagStorage[i] << endl;
}
void CBag::clear()
{
	size = 0;

}
bool CBag::contains(char item)
{
	for (int i = 0; i < size; i++) {
		if (bagStorage[i] == item)
			return true;
	}
	return false;
}
void CBag::remove(char item)
{
	if (isEmpty()) {
		cout << "Removal is failed! The bag is empty!" << endl;
	}
	else if (!contains(item)) {
		cout << "Removal is failed! The item is not in the bag." << endl;
	}
	else {
		//First, find the index of the item
		int index = 0;
		for (int i = 0; i < size; i++) {
			if (bagStorage[i] == item) {
				index = i;
				break;
			}
		}
		//To remove the item, shift all the numbers on the right side of item to the left by one place
		for (int i = index; i < size - 1; i++) {
			bagStorage[i] = bagStorage[i + 1];
		}
		size--;
	}
}