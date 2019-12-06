#include<iostream>
#include"BinaryTree.h"
using namespace std;
int main()
{
	BinaryTree<int>myTree;
	int num;
	myTree.creatBinaryTree();
	myTree.addNewItem();
	myTree.displayPreorder();
	num = myTree.getMax();
	cout << "The max number is: " << num << endl;
	num = myTree.getSum();
	cout << "The sum is: " << num << endl;
	num = myTree.getNumberOfNodes();
	cout << "The number of nodes is: " << num << endl;
	return 0;
}