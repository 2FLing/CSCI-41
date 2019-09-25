#include<iostream>
#include<stdio.h>
#include<random>
#include"Node.h"
using namespace std;
int main()
{
	Node<int>* Head, *My_node,*Temp_node;
	int num,largest=0,sum=0;
	Head = NULL;
	for (int i = 0; i < 50; i++)
	{
		num = rand() % 100;//set num equals random number between 0-99
		My_node = new Node<int>(num, Head);//put num into the linked list.
		Head = My_node;//make head point to the latest node.
	}
	Temp_node = Head;
	while (Temp_node != NULL)
	{
		num = Temp_node->getItem();//set num equal to the number inside of the node.
		if (num > largest)//if num is bigger than largest, then replace largest to the num
			largest = num;
		Temp_node = Temp_node->getNext();
	}
	Temp_node = Head;
	while (Temp_node != NULL)
	{
		num = Temp_node->getItem();//num is the original number in the node.
		Temp_node->setItem(num / largest);//replace the number in the node to number/largest
		Temp_node = Temp_node->getNext();
	}
	Temp_node = Head;
	while (Temp_node != NULL)
	{
		sum += Temp_node->getItem();//sum every single number in the linked list.
		Temp_node = Temp_node->getNext();
	}
	cout << "The sum is: " << sum << endl;
	return 0;
}