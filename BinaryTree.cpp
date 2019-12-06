#include<iostream>
#include"BinaryTree.h"
using namespace std;
bool exist(BinaryNode<int>*,const int& side);
void insert_node(BinaryNode<int>*,int times);
void display(BinaryNode<int>* root);
int main()
{
	int num,choice,times;
	enum{left=1,right=2};
	cout << "how many data do you have?" << endl;
	cin >> times;
	cout << "Please enter a number." << endl;
	cin >> num;
	BinaryNode<int>* current_node, *root,*new_node;
	current_node = new BinaryNode<int>(num);
	root = current_node;
	insert_node(root,times);
	display(root);
	cout << "how many data do you have?" << endl;
	cin >> times;
	insert_node(root,times);
	display(root);
	system("pause");
	return 0;
}
bool exist(BinaryNode<int>* aNode,const int& side)
{
	bool exsit = false;
	if (side == 1)
	{
		if (aNode->getLeftChildPtr() != NULL)
			exsit = true;
	}
	else if(side==2)
	{
		if (aNode->getRightChildPtr() != NULL)
			exsit = true;
	}
	return exsit;
}
void insert_node(BinaryNode<int>* root, int times)
{
	int num, choice;
	BinaryNode<int>* new_node,*current_node;
	current_node = root;
	enum{left = 1, right = 2};
	while (times != 1)
	{
		cout << "please enter a number." << endl;
		cin >> num;
		cout << "left or right?(1 or 2)" << endl;
		cin >> choice;
		while (exist(current_node, choice))
		{
			cout << "there is alreay a node on the " << choice << " left or right?" << endl;
			cin >> choice;
			if (choice == left and exist(current_node,choice))
				current_node = current_node->getLeftChildPtr();
			else if(choice == right and exist(current_node, choice))
				current_node = current_node->getRightChildPtr();
		}
		new_node = new BinaryNode<int>(num);
		if (choice == left)
		{
			current_node->setLeftChildPtr(new_node);
			current_node = current_node->getLeftChildPtr();
		}
		else
		{
			current_node->setRightChildPtr(new_node);
			current_node = current_node->getRightChildPtr();
		}
		times--;
	}
}
void display(BinaryNode<int>* root)
{
	BinaryNode<int>* new_node;
	enum{left=1,right=2};
	cout << "----------" << endl;
	new_node = root;
	while (new_node != NULL)
	{
		if (exist(new_node, left))
		{
			cout << new_node->getItem() << endl;
			new_node = new_node->getLeftChildPtr();
		}
		else if (exist(new_node, right))
		{
			cout << new_node->getItem() << endl;
			new_node = new_node->getRightChildPtr();
		}
		else if (new_node != NULL)
		{
			cout << new_node->getItem() << endl;
			break;
		}
	}
}