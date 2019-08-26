//Header File for Class Bag (as a sample of an implementation of ADT
#ifndef _Bag
#define _Bag
#include<iostream>
using namespace std;

//Class Definition (Interface)
template<class ItemType>
class Bag
{
private:
	ItemType bagStorage[100];
	int size;
public:
	Bag(); //This is a default constructor
	int getSize();
	bool isEmpty();
	void add(ItemType item);
	void remove(ItemType item);
	void display();
	void clear();
	bool contains(ItemType item);
};
//Definition of Constructors
template<class ItemType>
Bag<ItemType>::Bag()
{
	size = 0;
}
//Definition of Methods (Member Functions)
template<class ItemType>
int Bag<ItemType>::getSize()
{
	return size;
}
template<class ItemType>
bool Bag<ItemType>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}
template<class ItemType>
void Bag<ItemType>::add(ItemType item)
{
	if (size == 100)
		cout << "The bag is full!" << endl;
	else {
		bagStorage[size] = item;
		size++;
	}
}
template<class ItemType>
void Bag<ItemType>::display()
{
	cout << "The bag contains following integers: " << endl;
	for (int i = 0; i < size; i++)
		cout << bagStorage[i] << endl;
}
template<class ItemType>
void Bag<ItemType>::clear()
{
	size = 0;
}
template<class ItemType>
bool Bag<ItemType>::contains(ItemType item)
{
	for (int i = 0; i < size; i++) {
		if (bagStorage[i] == item)
			return true;
	}
	return false;
}
template<class ItemType>
void Bag<ItemType>::remove(ItemType item)
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
#endif _Bag