#include<iostream>
#include<stdio.h>
#include<string>
#include"stack.h"
bool is_braces_balance(string);
int main()
{
	string my_string;
	cout << "Please enter a string:" << endl;
	cin >> my_string;
	if (is_braces_balance(my_string))
		cout << "This is a braces balance string." << endl;
	else
		cout << "This is not a braces balance string." << endl;
}
//abc{abc(abc)abc}
//abc{abc(abc}abc)
bool balanced_braces(string str)
{
	Stack<char>myStack;
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '(' or str.at(i) == '{')
			myStack.push(str.at(i));
		else if (str.at(i) == ')' or str.at(i) == '}')
		{
			
			if (myStack.isEmpty())
				return false;
			else
				myStack.pop();
		}
	}
	if (myStack.isEmpty())
		return true;
	else
		return false;
}
