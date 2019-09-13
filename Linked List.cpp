#include<iostream>
#include<stdio.h>
#include"LinkedList.h"
using namespace std;
void print_list(Node<int>*);
int main()
{
	Node<int>* head, * newNode;
	int num,score;
	cout << "How many socres do you have?" << endl;
	cin >> num;
	head = NULL;
	for (int i = 0; i < num; i++)
	{
		cout << "Please enter your socre: " << endl;
		cin >> score;
		newNode = new Node<int>(score, head);
		head = newNode;
	}
	print_list(head);
	return 0;
}
void print_list(Node<int>* list)
{
	Node<int>*displayer;
	displayer = list;
	cout << "------------------" << endl;
	while (true)
	{
		if (displayer->getNext() == NULL)
		{
			cout << displayer->getItem() << endl;
			return;
		}
		else
		{
			cout << displayer->getItem() << endl;
			displayer = displayer->getNext();
		}
	}
}