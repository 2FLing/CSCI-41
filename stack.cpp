#include<iostream>
#include<random>
#include<string>
#include"Stack.h"
using namespace std;
int main()
{
	Stack<char>myStack;
	int length;
	string a;
	cout << "Please enter a string:" << endl;
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		myStack.push(a.at(i));
	}
	for (int i = 0; i < a.size(); i++)
	{
		if (myStack.peek() != '$')
			myStack.pop();
	}

	myStack.display();
	return 0;
}