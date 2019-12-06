#pragma once
//This is a simple version of class template BinarySearchTree
#ifndef _BINARYSEARCH_TREE
#define _BINARYSEARCH_TREE
#include"BinaryNode.h"
using namespace std;

template<class ItemType>
class BinarySearchTree
{
private:
	BinaryNode<ItemType>* rootPtr;
protected:
	void inOrderVisit(BinaryNode<ItemType>* treeRoot);

	BinaryNode<ItemType>* binarySearchAddHelper(BinaryNode<ItemType>* treeRoot,
		BinaryNode<ItemType>* newNodePtr);
	BinaryNode<ItemType>* getNode(BinaryNode<ItemType>* treeRoot,
		const ItemType& target) const;
	BinaryNode<ItemType>* removeEntry(BinaryNode<ItemType>* treeRoot,
		ItemType& target, bool& success);
	BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodeToBeRemoved);
	BinaryNode<ItemType>* removeLeftMost(BinaryNode<ItemType>* treeRoot,
		ItemType& nodeItem);
public:
	//Constructors
	BinarySearchTree();

	//Set and Get functions 
	ItemType getRootItem();
	void setRootItem(const ItemType& rootItem);

	//Other member functions
	bool isEmpty() const;
	void displayInorder();

	void binarySearchAdd(ItemType& newItem);
	bool binarySearchRemove(ItemType& anItem);
	BinaryNode<ItemType>* get_a_node(ItemType& anItem);
};
//Constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	rootPtr = NULL;
}
//Set and get functions for the item in the root
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootItem()
{
	if (rootPtr != NULL)
		return rootPtr->getItem();
	else {
		cout << "Empty tree!\n";
		exit(1);
	}
}
template<class ItemType>
void BinarySearchTree<ItemType>::setRootItem(const ItemType& rootItem)
{
	if (rootPtr != NULL)
		rootPtr->setItem(rootItem);
	else
		rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
//Protected functions
template<class ItemType>
void BinarySearchTree<ItemType>::inOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot == NULL)
		cout << "It is an empty tree!\n";
	else 
	{
		if (treeRoot->getLeftChildPtr() != NULL)
			inOrderVisit(treeRoot->getLeftChildPtr());
		cout << treeRoot->getItem() << endl;
		if (treeRoot->getRightChildPtr() != NULL)
			inOrderVisit(treeRoot->getRightChildPtr());
	}
}

//Other public member functions
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return (rootPtr == NULL);
}
template<class ItemType>
void BinarySearchTree<ItemType>::displayInorder()
{
	inOrderVisit(rootPtr);
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::binarySearchAddHelper(BinaryNode<ItemType>* treeRoot,
	BinaryNode<ItemType>* newNodePtr)
{
	if (treeRoot == NULL)
	{
		treeRoot = newNodePtr;
		return treeRoot;
	}
	else if (treeRoot->getItem() == newNodePtr->getItem())
	{
		newNodePtr->setRightChildPtr(treeRoot->getRightChildPtr());
		treeRoot->setRightChildPtr(NULL);
		newNodePtr->setLeftChildPtr(treeRoot);
		treeRoot = newNodePtr;
		return treeRoot;
	}
	else
	{

		if (newNodePtr->getItem() <treeRoot->getItem())
		{
			if (treeRoot->getLeftChildPtr() != NULL)
			{
				treeRoot->setLeftChildPtr(binarySearchAddHelper(treeRoot->getLeftChildPtr(), newNodePtr));
			}
			else
			{
				treeRoot->setLeftChildPtr(newNodePtr);
			}
		}
		else if (newNodePtr->getItem() > treeRoot->getItem())
		{
			if (treeRoot->getRightChildPtr() != NULL)
			{
				treeRoot->setRightChildPtr(binarySearchAddHelper(treeRoot->getRightChildPtr(), newNodePtr));
			}
			else
			{
				treeRoot->setRightChildPtr(newNodePtr);
			}
		}
		return treeRoot;
	}

}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::getNode(BinaryNode<ItemType>* treeRoot,
	const ItemType& target) const
{
	BinaryNode<ItemType>* temp_node=NULL;
	if (treeRoot != NULL)
	{
		if (treeRoot->getItem() == target)
		{
			temp_node = treeRoot;
		}
		else
		{
			temp_node = getNode(treeRoot->getLeftChildPtr(), target);
			if (temp_node == NULL)
				temp_node = getNode(treeRoot->getRightChildPtr(), target);
		}
	}
	return temp_node;
}
template<class ItemType>
void BinarySearchTree<ItemType>::binarySearchAdd(ItemType& newItem)
{
	BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>(newItem);
	rootPtr=binarySearchAddHelper(rootPtr, newNode);
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeEntry(BinaryNode<ItemType>* treeRoot,
	ItemType& target, bool& success)
{
	if (treeRoot == NULL)
	{
		success = false;
	}
	else
	{	
		if (treeRoot->getItem() == target)
		{
			treeRoot = removeNode(treeRoot);
			success = true;

		}
		else
		{
			if (target < treeRoot->getItem())
			{
				treeRoot->setLeftChildPtr(removeEntry(treeRoot->getLeftChildPtr(), target, success));
			}
			else if (target > treeRoot->getItem())
			{
				treeRoot->setRightChildPtr(removeEntry(treeRoot->getRightChildPtr(), target, success));
			}
		}
	}
	return treeRoot;
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodeToBeRemoved)
{
	BinaryNode<ItemType>* temp_node=NULL;
	if (nodeToBeRemoved->getLeftChildPtr() != NULL and nodeToBeRemoved->getRightChildPtr() != NULL)
	{
		ItemType num;
		nodeToBeRemoved->setRightChildPtr(removeLeftMost(nodeToBeRemoved->getRightChildPtr(), num));
		nodeToBeRemoved->setItem(num);
		temp_node = nodeToBeRemoved;

	}
	else if (nodeToBeRemoved->isLeaf())
	{
		nodeToBeRemoved = NULL;
		delete(nodeToBeRemoved);
	}
	else if (nodeToBeRemoved->getLeftChildPtr() != NULL or nodeToBeRemoved->getRightChildPtr() != NULL)
	{
		if (nodeToBeRemoved->getLeftChildPtr() != NULL)
		{
			temp_node= nodeToBeRemoved->getLeftChildPtr();
			nodeToBeRemoved->setLeftChildPtr(NULL);
			delete(nodeToBeRemoved);
		}
		else if (nodeToBeRemoved->getRightChildPtr() != NULL)
		{
			temp_node = nodeToBeRemoved->getRightChildPtr();
			nodeToBeRemoved->setRightChildPtr(NULL);
			delete(nodeToBeRemoved);
		}
	}
	return temp_node;
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftMost(BinaryNode<ItemType>* treeRoot,
	ItemType& nodeItem)
{
	if (treeRoot->getLeftChildPtr() != NULL)
	{
		treeRoot->setLeftChildPtr(removeLeftMost(treeRoot->getLeftChildPtr(), nodeItem));
	}
	else
	{
		nodeItem = treeRoot->getItem();
		treeRoot = treeRoot->getRightChildPtr();
	}
	return treeRoot;
}
template<class ItemType>
bool BinarySearchTree<ItemType>::binarySearchRemove(ItemType& anItem)
{
	bool success;
	rootPtr = removeEntry(rootPtr, anItem, success);
	if (!success)
		cout << "The number is not in the tree" << endl;
	return success;
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::get_a_node(ItemType& anItem)
{
	return getNode(rootPtr, anItem);
}
#endif
