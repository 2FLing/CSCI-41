#pragma once
#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode
{
private:
	//Data protion
	ItemType		item;
	BinaryNode<ItemType>* leftChildPtr;     //Pointer to left child
	BinaryNode<ItemType>* rightChildPtr;    //Pointer to right child
public:
	//default constructor
	BinaryNode();
	//Constructor for initializing data member item
	BinaryNode(const ItemType& anItem);
	//Constructor for initializing all data members
	BinaryNode(const ItemType& anItem,
		BinaryNode<ItemType>* leftPtr,
		BinaryNode<ItemType>* rightPtr);
	//set and get functions 
	void setItem(const ItemType& anItem);
	ItemType getItem() const;
	BinaryNode<ItemType>* getLeftChildPtr() const;
	BinaryNode<ItemType>* getRightChildPtr() const;
	void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
	void setRightChildPtr(BinaryNode<ItemType>* rightPtr);

	bool isLeaf() const; //Check if the node has any children
};

template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
{
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
{
	item = anItem;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
	BinaryNode<ItemType>* leftPtr,
	BinaryNode<ItemType>* rightPtr)
{
	item = anItem;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
	return item;
}
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
	leftChildPtr = leftPtr;
}
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
	rightChildPtr = rightPtr;
}
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
	if (leftChildPtr == NULL && rightChildPtr == NULL)
		return true;
	else
		return false;
}
#endif
