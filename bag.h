//Header File for Class Bag (as a sample of an implementation of ADT
#ifndef _Bag
#define _Bag
#include<iostream>
using namespace std;
<<<<<<< HEAD

=======
const int MAX = 100;
>>>>>>> b23d309eb87005792a920248dc079bf783085f0e
//Class Definition (Interface)
class Bag
{
private:
<<<<<<< HEAD
	int bagStorage[100];
=======
	int bagStorage[MAX];
>>>>>>> b23d309eb87005792a920248dc079bf783085f0e
	int size;
public:
	Bag(); //This is a default constructor
	int getSize();
	bool isEmpty();
	void add(int item);
	void remove(int item);
	void display();
	void clear();
<<<<<<< HEAD
	bool contains(int item);
	bool getMax(int& maxitem);
=======
	void insert(int);
	bool contains(int item);
>>>>>>> b23d309eb87005792a920248dc079bf783085f0e
};
//Definition of Constructors
Bag::Bag()
{
	size = 0;
}
//Definition of Methods (Member Functions)
int Bag::getSize()
{
	return size;
}
bool Bag::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}
void Bag::add(int item)
{
<<<<<<< HEAD
	if (size == 100)
=======
	if (size == MAX)
>>>>>>> b23d309eb87005792a920248dc079bf783085f0e
		cout << "The bag is full!" << endl;
	else {
		bagStorage[size] = item;
		size++;
	}
}
void Bag::display()
{
	cout << "The bag contains following integers: " << endl;
	for (int i = 0; i < size; i++)
		cout << bagStorage[i] << endl;
}
void Bag::clear()
{
	size = 0;
<<<<<<< HEAD
=======
	
>>>>>>> b23d309eb87005792a920248dc079bf783085f0e
}
bool Bag::contains(int item)
{
	for (int i = 0; i < size; i++) {
		if (bagStorage[i] == item)
			return true;
	}
	return false;
}
void Bag::remove(int item)
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
<<<<<<< HEAD
bool Bag::getMax(int& maxitem)
{
	int num;
	bool Notempty=true;
	if (size != 0)
	{
		num = bagStorage[0];
		for (int i = 1; i < size; i++)
		{
			if (bagStorage[i] > num)
				num = bagStorage[i];
		}
		maxitem = num;
	}
	else
		Notempty = false;
	return Notempty;
}
#endif _Bag
=======
void Bag::insert(int num)
{
	if (contains(num))
		cout << "This number is already in the bag." << endl;
	else
	{
		bagStorage[size] = num;
		size++;
	}
}
#endif _Bag
>>>>>>> b23d309eb87005792a920248dc079bf783085f0e
