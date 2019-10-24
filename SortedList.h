#ifndef _SORTED_LIST
#define _SORTED_LIST
#include<stdio.h>
#include"Node.h"
using namespace std;
template<class ItemType>
class SortedList
{
private:
	Node<ItemType>* head;
	int itemCount;		//Current count of list items
	Node<ItemType>* getNodeBefore(const ItemType& anEntry)const;
	Node<ItemType>* getNodeAt(int position) const; //Return a pointer that hold the address of the node at 'position'
public:
	SortedList(); //Default constructor
	SortedList(const SortedList<ItemType>& aList); //Copy constructor
	bool isEmpty() const;  //Check if the list empty (no item stored in the array)
	int getLength() const; //Returns the number of items in the list
	bool remove(int position); //Remove an entry at given position from the list
	void clear(); //remove all the items from the list
	ItemType getEntry(int position) const; //Retrieves an item on the list at the given position
	void displayList();

	//Following are three new methods:
	void insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	int getPosition(const ItemType& newEntry) const;
};
//Complete all the constructors and methods here:
template<class ItemType>
SortedList<ItemType>::SortedList()
{
	head = NULL;
	itemCount = 0;
}
template<class ItemType>
SortedList<ItemType>::SortedList(const SortedList<ItemType>& List)
{

	Node<ItemType>* temp_node, * alist_head = List.head;
	head = NULL;
	itemCount = 0;
	while (alist_head != NULL)
	{
		temp_node = new Node<ItemType>(alist_head->getItem(), head);
		head = temp_node;
		alist_head = alist_head->getNext();
		itemCount++;
	}

}
template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	if (isEmpty())
	{
		return NULL;
	}
	else if (head->getItem() >= anEntry)
	{
		return NULL;
	}
	else
	{
		Node<ItemType>* temp_node = head, * next_node;
		while (temp_node != NULL)
		{
			next_node = temp_node->getNext();
			if (next_node == NULL)
				break;
			if (next_node->getItem() >= anEntry)
				break;
			temp_node = temp_node->getNext();
		}
		return temp_node;
	}
}
template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeAt(int position) const
{
	int counter = position - 1;
	Node<ItemType>*temp_node=head;
	while (counter != 0)
	{
		temp_node = temp_node->getNext();
		counter--;
	}
	return temp_node;
}
template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
	bool empty = false;
	if (head == NULL)
		empty = true;
	return empty;
}
template<class ItemType>
int SortedList<ItemType>::getLength() const
{
	return itemCount;
}
template<class ItemType>
bool SortedList<ItemType>::remove(int position)
{
	if (position<1 or position>itemCount)
		return false;
	else if (position == 1)
	{
		Node<ItemType>*temp_node = head;
		head = head->getNext();
		temp_node->setNext(NULL);
		delete(temp_node);
		itemCount--;
		return true;
	}
	else
	{
		Node<ItemType>*pre_node,*temp_node,*next_node;
		pre_node = getNodeAt(position - 1);
		temp_node = getNodeAt(position);
		next_node = temp_node->getNext();
		pre_node->setNext(next_node);
		temp_node->setNext(NULL);
		delete(temp_node);
		itemCount--;
		return true;
	}
}
template<class ItemType>
void SortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>*pre_node,*next_node,*temp_node;
	pre_node = getNodeBefore(newEntry);
	if (pre_node == NULL)
	{
		temp_node = new Node<ItemType>(newEntry, head);
		head = temp_node;
		itemCount++;
	}
	else
	{
		temp_node = new Node<ItemType>(newEntry, NULL);
		next_node = pre_node->getNext();
		temp_node->setNext(next_node);
		pre_node->setNext(temp_node);
		itemCount++;
	}
}
template<class ItemType>
void SortedList<ItemType>::displayList()
{
	if (isEmpty())
	{
		cout << "This list is empty" << endl;
	}
	else
	{
		Node<ItemType>* temp_node = head;
		while (temp_node != NULL)
		{
			cout << temp_node->getItem() << endl;
			temp_node = temp_node->getNext();
		}
	}
}
template<class ItemType>
void SortedList<ItemType>::clear()
{
	Node<ItemType>*temp_node;
	while (head != NULL)
	{
		temp_node = head;
		head = head->getNext();
		temp_node->setNext(NULL);
		delete(temp_node);
	}
}
template<class ItemType>
ItemType SortedList<ItemType>::getEntry(int position) const
{
	Node<ItemType>* temp_node = head;
	while (position<1 or position>itemCount)
	{
		cout << "Invalid position, please enter again: " << endl;
		cin >> position;
	}
	while (position != 1)
	{
		temp_node = temp_node->getNext();
		position--;
	}
	return temp_node->getItem();
}
template<class ItemType>
bool SortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	if (isEmpty())
		return false;
	else if (anEntry == head->getItem())
	{
		Node<ItemType>* temp_node=head;
		head = head->getNext();
		temp_node->setNext(NULL);
		delete(temp_node);
		return true;
	}
	else
	{
		Node<ItemType>* pre_node,*cur_node;
		pre_node = getNodeBefore(anEntry);
		if (pre_node == NULL)
			return false;
		else
		{
			cur_node = pre_node->getNext();
			if (cur_node == NULL or cur_node->getItem() > anEntry)
				return false;
			else
			{
				pre_node->setNext(cur_node->getNext());
				cur_node->setNext(NULL);
				delete(cur_node);
				return true;
			}
		}

	}

}
template<class ItemType>
int SortedList<ItemType>::getPosition(const ItemType& newEntry) const
{
	int position = 1;
	if (isEmpty())
		return position;
	else
	{
		Node<ItemType>*temp_node=head;
		while (temp_node != NULL)
		{
			if (temp_node->getItem() < newEntry)
				position++;
			temp_node = temp_node->getNext();
		}
		return position;
	}
}
#endif