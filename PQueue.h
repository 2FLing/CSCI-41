#pragma once
// Class template PQueue header file: PQueue.h
#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include"SortedList.h"

template<class ItemType>
class PQueue
{
private:
	SortedList<ItemType>* sortedListPtr;
public:
	PQueue();  //Default constructor
	PQueue(const PQueue& aPQueue); //Copy constructor
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peek();
	void displayQueue();
};
//Default constructor
template<class ItemType>
PQueue<ItemType>::PQueue()
{
	sortedListPtr = new SortedList<ItemType>();
}
//Copy constructor
template<class ItemType>
PQueue<ItemType>::PQueue(const PQueue& aPQueue)
{
	sortedListPtr = new SortedList<ItemType>();
	if (!aPQueue.isEmpty()) {
		int length = aPQueue.sortedListPtr->getLength();
		ItemType anEntry;
		for (int i = 1; i <= length; i++) {
			anEntry = aPQueue.sortedListPtr->getEntry(i);
			sortedListPtr->insertSorted(anEntry);
		}
	}
}
template<class ItemType>
bool PQueue<ItemType>::isEmpty() const
{
	bool empty = false;
	if (sortedListPtr->isEmpty())
		empty = true;
	return empty;
}
template<class ItemType>
bool PQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	sortedListPtr->insertSorted(newEntry);
	return true;
}
template<class ItemType>
bool PQueue<ItemType>::dequeue()
{
	if (sortedListPtr->isEmpty())
		return false;
	else
	{
		sortedListPtr->remove(1);
		return true;
	}
}
template<class ItemType>
ItemType PQueue<ItemType>::peek()
{
	return sortedListPtr->getEntry(1);
}
template<class ItemType>
void PQueue<ItemType>::displayQueue()
{
	sortedListPtr->displayList();
}
#endif
