//class template BinaryTree header file: BinaryTree.h
#ifndef _BINARY_TREE
#define _BINARY_TREE

#include"BinaryNode.h"
#include<iostream>
using namespace std;
template<class ItemType>
class BinaryTree
{
private:
	BinaryNode<ItemType>* rootPtr;
protected:
	BinaryNode<ItemType>* createBinaryTreeHelper(BinaryNode<ItemType>* aParent);
	void preOrderVisit(BinaryNode<ItemType>* treeRoot);
	void inOrderVisit(BinaryNode<ItemType>* treeRoot);
	void postOrderVisit(BinaryNode<ItemType>* treeRoot);
	ItemType getSumHelper(BinaryNode< ItemType>*);
	int getNumberOfNodesHelper(BinaryNode<ItemType>*);
	BinaryNode<ItemType>* addNewItemHelper(BinaryNode<ItemType>*treeRoot, ItemType newitem);
	int getMaxHelper(BinaryNode <ItemType>*);
public:
	//Constructors
	BinaryTree();
	BinaryTree(const ItemType& rootItem);


	//Set and Get functions 
	ItemType getRootItem();
	void setRootItem(const ItemType& rootItem);

	//Other member functions
	bool isEmpty() const;
	void creatBinaryTree();
	void displayPreorder();
	void displayInorder();
	void displayPostorder();
	void addNewItem();
	ItemType getSum();
	int getNumberOfNodes();
	int getMax();
};
//Constructors
template<class ItemType>
BinaryTree<ItemType>::BinaryTree()
{
	rootPtr = NULL;
}
template<class ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}

//Set and Get functions
template<class ItemType>
ItemType BinaryTree<ItemType>::getRootItem()
{
	if (rootPtr != NULL)
		return rootPtr->getItem();
	else
	{
		cout << "Empty tree!\n";
		exit(1);
	}
}
template<class ItemType>
void BinaryTree<ItemType>::setRootItem(const ItemType& rootItem)
{
	if (rootPtr != NULL)
		rootPtr->setItem(rootItem);
	else
		rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
template<class ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
	return(rootPtr == NULL);
}
//Assignment 15: Please complete following member functions
template<class ItemType>
BinaryNode<ItemType>*BinaryTree<ItemType>::createBinaryTreeHelper(BinaryNode<ItemType>* treeRoot)
{
	ItemType item;
	int answer;
	cout << "Please enter an Item:" << endl;
	cin >> item;
	treeRoot = new BinaryNode<ItemType>(item);
	cout << "Continue to the left of " << treeRoot->getItem() << " ?(0 for no, 1 for yes):" << endl;
	cin >> answer;
	if (answer == 1)
	{
		treeRoot->setLeftChildPtr(createBinaryTreeHelper(treeRoot->getLeftChildPtr()));
	}
	cout << "Continure to the right of " << treeRoot->getItem() << " ?(0 for no, 1 for yes):" << endl;
	cin >> answer;
	if (answer == 1)
	{
		treeRoot->setRightChildPtr(createBinaryTreeHelper(treeRoot->getRightChildPtr()));
	}
	return treeRoot;
}
template<class ItemType>
void BinaryTree<ItemType>::preOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot != NULL)
	{
		cout << treeRoot->getItem() << " ";
		if (treeRoot->getLeftChildPtr() != NULL)
			preOrderVisit(treeRoot->getLeftChildPtr());
		if (treeRoot->getRightChildPtr() != NULL)
			preOrderVisit(treeRoot->getRightChildPtr());
	}
}
template<class ItemType>
void BinaryTree<ItemType>::inOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot != NULL)
	{
		if (treeRoot->getLeftChildPtr() != NULL)
		{
			inOrderVisit(treeRoot->getLeftChildPtr());//go all the way to the end if the tree has left_sub_tree
			cout << treeRoot->getItem() << " ";//after go through all the left_sub_tree, display the root
		}
		if (treeRoot->getRightChildPtr() != NULL)
		{
			if (treeRoot->getLeftChildPtr() == NULL)//if the node doesn`t have left sub_tree,display the node right away
				cout << treeRoot->getItem() << " "; //because when a node doesn	t have left_sub_tree, it won`t go through the 
				                                    //process above,and it must be a root,so just display it right away.		
			inOrderVisit(treeRoot->getRightChildPtr());//go through the right_sub_tree
		}
		else if(treeRoot->getLeftChildPtr()==NULL and treeRoot->getRightChildPtr()==NULL)//when a node doen`t have either left or right sub tree
			cout << treeRoot->getItem() << " ";	                                         //that means it is the end of the sub tree, then display the
		                                                                                 //node right away
	}
}
template<class ItemType>
void BinaryTree<ItemType>::postOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	//postordervisit, for every single sub tree.it will go through all the way to the left
	//first then display the left sub tree and then go through all
	//the way to the right then display the right sub tree.
	if (treeRoot != NULL)
	{
		if (treeRoot->getLeftChildPtr() != NULL)
		{
			postOrderVisit(treeRoot->getLeftChildPtr());
		}
		if (treeRoot->getRightChildPtr() != NULL);
		{
			postOrderVisit(treeRoot->getRightChildPtr());
		}
		cout << treeRoot->getItem() << " ";
	}
}
template<class ItemType>
void BinaryTree<ItemType>::creatBinaryTree()
{
	rootPtr = createBinaryTreeHelper(rootPtr);
}
template<class ItemType>
void BinaryTree<ItemType>::displayPreorder()
{
	preOrderVisit(rootPtr);
	cout << endl;
}
template<class ItemType>
void BinaryTree<ItemType>::displayInorder()
{
	inOrderVisit(rootPtr);
	cout << endl;
}
template<class ItemType>
void BinaryTree<ItemType>::displayPostorder()
{
	postOrderVisit(rootPtr);
	cout << endl;
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getSumHelper(BinaryNode<ItemType>*treeRoot)
{
	if (treeRoot == NULL)
	{
		cout << "TreeRoot is NULL" << endl;
		exit(1);
	}
	else
	{
		ItemType s = treeRoot->getItem();
		if (treeRoot->getLeftChildPtr() != NULL)
		{
			s += getSumHelper(treeRoot->getLeftChildPtr());
		}
		if (treeRoot->getRightChildPtr() != NULL)
		{
			s += getSumHelper(treeRoot->getRightChildPtr());
		}
		return s;
	}
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getSum()
{
	return getSumHelper(rootPtr);
}
template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::addNewItemHelper(BinaryNode <ItemType>*treeRoot,ItemType item)
{
	if (treeRoot == NULL)
	{
		treeRoot = new BinaryNode <ItemType>(item);
		return treeRoot;
	}
	else
	{
		int answer;
		cout << "left or right of "<<treeRoot->getItem()<<"?( 0 for left,1 for right)" << endl;
		cin >> answer;
		if (answer == 0)
		{
			treeRoot->setLeftChildPtr(addNewItemHelper(treeRoot->getLeftChildPtr(), item));
		}
		else if (answer == 1)
		{
			treeRoot->setRightChildPtr(addNewItemHelper(treeRoot->getRightChildPtr(), item));
		}
	}
}
template<class ItemType>
void BinaryTree<ItemType>::addNewItem()
{
	ItemType item;
	cout << "Adding a new item." << endl;
	cout << "Please enter an item:" << endl;
	cin >> item;
	addNewItemHelper(rootPtr, item);
}
template<class ItemType>
int BinaryTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>*treeRoot)
{
	if (treeRoot == NULL)
	{
		return 0;
	}
	else
	{
		int n;
		n = 1+getNumberOfNodesHelper(treeRoot->getLeftChildPtr()) + getNumberOfNodesHelper(treeRoot->getRightChildPtr());
		return n;
	}
}
template<class ItemType>
int BinaryTree<ItemType>::getNumberOfNodes()
{
	return getNumberOfNodesHelper(rootPtr);
}
template<class ItemType>
int BinaryTree<ItemType>::getMaxHelper(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot == NULL)
	{
		cout << "The treeroot is NULL." << endl;
		exit(1);
	}
	else
	{
		int n=treeRoot->getItem();
		if (treeRoot->getLeftChildPtr() != NULL)
		{
			if (getMaxHelper(treeRoot->getLeftChildPtr()) > n)
				n = getMaxHelper(treeRoot->getLeftChildPtr());
		}
		if (treeRoot->getRightChildPtr() != NULL)
		{
			if (getMaxHelper(treeRoot->getRightChildPtr()) > n)
				n = getMaxHelper(treeRoot->getRightChildPtr());
		}
		return n;
	}
}
template<class ItemType>
int BinaryTree<ItemType>::getMax()
{
	return getMaxHelper(rootPtr);
}
#endif
 
