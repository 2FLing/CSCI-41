#include<iostream>
#include"Node.h"
#include"SortedList.h"
#include<ctime>
using namespace std;

int main()
{
	SortedList<int> aList;

	//Test inserSorted() funciton
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 8; i++) {
		aList.insertSorted(rand() % 100);
	}
	cout << "================\n";
	aList.displayList();
	cout << "================\n";
	//Test clear() function
	aList.clear();
	aList.insertSorted(17);
	aList.insertSorted(5);
	aList.insertSorted(21);
	aList.insertSorted(15);
	aList.insertSorted(4);
	cout << "================\n";
	aList.displayList();
	cout << "================\n";
	//Test removeSorted() function
	for (int i = 1; i < 5; i++)
	{
		aList.remove(i);
		aList.insertSorted(i);
	}
	aList.displayList();
	return 0;
}
