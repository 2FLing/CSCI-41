#include<iostream>
#include<string>
#include"BinarySearchTree.h"
using namespace std;
int main()
{
	BinarySearchTree<int>t1;
	int num=0;
	char answer='n';
	while (answer != '5')
	{
		cout << "--------------------" << endl;
		cout << "|1.Add new item    |" << endl;
		cout << "|2.remove entry    |" << endl;
		cout << "|3.display the tree|" << endl;
		cout << "|4.get node        |" << endl;
		cout << "|5.exit the program|" << endl;
		cout << "--------------------" << endl;
		cin >> answer;
		switch (answer)
		{
		case '1':
		{
			while (num != -1)
			{
				cout << "Please enter a number:(enter -1 to get out)" << endl;
				cin >> num;
				if (num != -1)
					t1.binarySearchAdd(num);
				else
					getchar();
			}
			num = 0;
			break;
		}
		case '2':
		{
			cout << "Please enter what you want to remove:" << endl;
			cin >> num;
			t1.binarySearchRemove(num);
			break;
		}
		case '3':
		{cout << "The list contains:" << endl;
		t1.displayInorder();
		break;
		}
		case'4':
		{
			int target;
			BinaryNode<int>* target_node;
			cout << "Please enter a value:" << endl;
			cin >> target;
			target_node = t1.get_a_node(target);
			if (target_node != NULL)
				cout << "The item is: " << target_node->getItem() << endl;
			else
				cout << "NULL" << endl;
			break;
		}
		case '5':
		{
			exit(0);
		}
		default:
			break;
		}
	}

	return 0;
}