//Header File for Class Bag (as a sample of an implementation of ADT
#ifndef _Bag
#define _Bag
#include<iostream>
using namespace std;

//Class Definition (Interface)
class Bag
{
private:
	int bagStorage[100];
	int size;
public:
	Bag(); //This is a default constructor
	int getSize();
	bool isEmpty();
	void add(int item);
	void remove(int item);
	void display();
	void clear();
	bool contains(int item);
	bool getMax(int& maxitem);
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
	if (size == 100)
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