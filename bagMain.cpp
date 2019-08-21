#include<stdio.h>
#include<random>
#include"bag.h"
using namespace std;
int main()
{
	Bag myBag;
	int num;
	for (int i = 0; i < 49; i++)
	{
		num = rand() % 10;
		myBag.insert(num);
	}
	cout << "-----------------------" << endl;
	myBag.display();
	return 0;
}