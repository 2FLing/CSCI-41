#pragma once
//Header File of Class Template for ADT Queue

#ifndef _QUEUE
#define _QUEUE

#include"Node.h"
#include<iostream>
using namespace std;
template<class ItemType>
class Queue
{
private:
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;

public:
	Queue();  //Default constructor
	Queue(const Queue<ItemType>& aQueue); //Copy constructor

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const;
	void display() const;
};

template<class ItemType>
Queue<ItemType>::Queue()
{
	frontPtr = NULL;
	backPtr = NULL;
}
template<class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue)
{
	Node<ItemType>* originalNodePtr = aQueue.frontPtr;
	if (originalNodePtr == NULL) {
		frontPtr = NULL;
		backPtr = NULL;
	}
	else {
		//copy the first node
		frontPtr = new Node<ItemType>;
		frontPtr->setItem(originalNodePtr->getItem());
		//copy the remaining nodes
		backPtr = frontPtr;
		while (originalNodePtr->getNext() != NULL) {
			originalNodePtr = originalNodePtr->getNext();
			ItemType nextItem = originalNodePtr->getItem();
			Node<ItemType>* newNode = new Node<ItemType>(nextItem);
			backPtr->setNext(newNode);
			backPtr = backPtr->getNext();
		}
		backPtr->setNext(NULL);
	}
}
template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
	bool empty = false;
	if (frontPtr == NULL)
		empty = true;
	return empty;
}
template<class ItemType>
bool Queue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* temp_node=new Node<ItemType>(newEntry,NULL);
	if (frontPtr == NULL)
	{
		frontPtr = temp_node;
		backPtr = temp_node;
	}
	else
	{
		backPtr->setNext(temp_node);
		backPtr = temp_node;
	}
	return true;
}
template<class ItemType>
bool Queue<ItemType>::dequeue()
{
	if (frontPtr == NULL)
		return false;
	else if (frontPtr == backPtr)
	{
		Node<ItemType>* temp_node;
		temp_node = frontPtr;
		frontPtr = NULL;
		backPtr = NULL;
		delete(temp_node);
	}
	else
	{
		Node<ItemType>* temp_node;
		temp_node = frontPtr;
		frontPtr = frontPtr->getNext();
		temp_node->setNext(NULL);
		delete(temp_node);
		return true;
	}
}
template<class ItemType>
ItemType Queue<ItemType>::peekFront() const
{
	return frontPtr->getItem();
}
template<class ItemType>
void Queue<ItemType>::display() const
{
	Node<ItemType>* temp_node = frontPtr;
	while (temp_node != NULL)
	{
		cout << temp_node->getItem() << endl;
		temp_node = temp_node->getNext();
	}
}
#endif
