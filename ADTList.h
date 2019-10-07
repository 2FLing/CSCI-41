#ifndef _LIST
#define _LIST
#include"Node.h"
#include<iostream>
using namespace std;
template<class ItemType>
class List
{
private:
	Node<ItemType>* head;
	int itemCount;//Current count of list items
	Node<ItemType>* getNodeAt(int position) const;
public:
	List(); //Default constructor
	List(const List<ItemType>& aList); //Copy constructor
	bool isEmpty() const;
	int getLength() const;
	bool insert(int position, const ItemType& newEntry);
	void displayList();
	bool remove(int position);
	void clear(); //remove all the items from the list
	ItemType getEntry(int position) const;
	void setEntry(int position, const ItemType& newEntry);
};
template<class ItemType>
Node<ItemType>* List<ItemType>::getNodeAt(int position) const
{
	if (position < 1 or position>itemCount)
		return NULL;
	else
	{
		Node<ItemType>* CurNode=head;
		while (position != 1)
		{
			CurNode = CurNode->getNext();
			position--;
		}
		return CurNode;
	}
}
template<class ItemType>
List<ItemType>::List()
{
	head = NULL;
	itemCount = 0;
}
template<class ItemType>
List<ItemType>::List(const List<ItemType>& alist)
{
	Node<ItemType>* temp_node=alist.head,*newNode;
	while (temp_node != NULL)//create a empty list has same length as alist.
	{
		newNode = new Node<ItemType>(0, head);
		head = newNode;
		temp_node = temp_node->getNext();
	}
	newNode = head;//make these two nodes points to the head of these two list.
	temp_node = alist.head;
	while (temp_node != NULL)//pass the values in alist to the list here.
	{
		newNode->setItem(temp_node->getItem());
		newNode = newNode->getNext();
		temp_node = temp_node->getNext();
	}
	itemCount = alist.itemCount;
}
template<class ItemType>
bool List<ItemType>::isEmpty() const
{
	return(head == NULL);
}
template<class ItemType>
int List<ItemType>::getLength() const
{
	return itemCount;
}
template<class ItemType>
void List<ItemType>::displayList()
{
	if (head == NULL)
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		Node<ItemType>* curNode = head;
		while (curNode != NULL)
		{
			cout << curNode->getItem() << endl;
			curNode = curNode->getNext();
		}
	}
}
template<class ItemType>
bool List<ItemType>::insert(int position, const ItemType &newEntry)
//用两个pointer，一前一后然后就可以把新的值放入两个pointer之间
//如果position是1的话那就直接把新的值作为head of the linked list
{
	if (position < 1)
	{
		cout << "Invalid position!" << endl;
		return false;
	}
	else
	{
		if (position == 1)
		{
			Node<ItemType>* CurNode;
			CurNode = new Node<ItemType>(newEntry, head);
			head = CurNode;
			itemCount++;
		}
		else if (position > itemCount)
		{
			Node<ItemType>* temp_node,*curNode;
			curNode = getNodeAt(itemCount);
			temp_node = new Node<ItemType>(newEntry, NULL);
			curNode->setNext(temp_node);
			itemCount++;
		}
		else
		{
			Node<ItemType>* PreNode, * CurNode,*Temp_Node;
			PreNode = getNodeAt(position - 1);
			CurNode = getNodeAt(position);
			Temp_Node = new Node<ItemType>(newEntry, CurNode);
			PreNode->setNext(Temp_Node);
			itemCount++;
		}
	}
	return true;
}
template<class ItemType>
bool List<ItemType>::remove(int position)
{
	bool ableToRemove=(position >= 1) and (position <= itemCount);
	if (ableToRemove)
	{
		if (position == 1)
		{
			Node<int>*temp_node = head;
			head = head->getNext();
			temp_node->setNext(NULL);
			delete(temp_node);
			itemCount--;
		}
		else if (position == itemCount)
		{
			Node<ItemType>* cur_node,*pre_node;
			cur_node = getNodeAt(position);
			pre_node = getNodeAt(position - 1);
			pre_node->setNext(NULL);
			delete(cur_node);
			itemCount--;
		}
		else
		{
			Node<ItemType>* cur_node, * pre_node,*next_node;
			cur_node = getNodeAt(position);
			pre_node = getNodeAt(position - 1);
			next_node = getNodeAt(position + 1);
			pre_node->setNext(next_node);
			delete(cur_node);
			itemCount--;
		}
	}
	return ableToRemove;
}
template<class ItemType>
void List<ItemType>::clear()
{
	Node<ItemType>*temp_node;
	while (head != NULL)
	{
		temp_node = head;
		head = head->getNext();
		delete(temp_node);
	}
	itemCount = 0;
}
template<class ItemType>
ItemType List<ItemType>::getEntry(int position) const
{
	Node<ItemType>*temp_node=head;
	while (position<1 or position>itemCount)
	{
		cout << "invalid position, please enter again: " << endl;
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
void List<ItemType>::setEntry(int position, const ItemType& newEntry)
{
	Node<ItemType>* temp_node = head;
	while (position<1 or position>itemCount)
	{
		cout << "invalid position, please enter again: " << endl;
		cin >> position;
	}
	while (position != 1)
	{
		temp_node = temp_node->getNext();
		position--;
	}
	temp_node->setItem(newEntry);
}
#endif