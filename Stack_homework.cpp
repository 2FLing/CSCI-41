#include<iostream>
#include<stdio.h>
#include<string>
#include"stack.h"
bool is_braces_balance(string);
bool is_equal(char, char);
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
bool is_braces_balance(string st)
{
	Stack<char> my_stack;
	for (int i = 0; i < st.size(); i++)
	{
		if (st.at(i) == '(' or st.at(i) == '{')//push the left side symbol into stack.
		{
			my_stack.push(st.at(i));
		}
	}
	for (int i = 0; i < st.size(); i++)
	{
		if (st.at(i) == ')' and st.at(i) == '}')//if the charater in the string is a right side symbol then make it compare with the symbol in the stack.
		{
			if (is_equal(my_stack.peek(), st.at(i)))//if the left side symbol and right side symbol are matched then pop the symbol out of the stack
			{
				my_stack.pop();
			}
			if (my_stack.isEmpty())//if the stack is empty but there is still right side symbol in the string then it is not a balance string.
				return false;
		}
	}
	if (!my_stack.isEmpty())//if there are still symbols in the stack then it is not a balance string.
	{
		return false;
	}
	else//otherwise it is a balance string.
		return true;
}
//if the left side symbol is matched with the right side symbol then they are equal.
bool is_equal(char left_symbol, char right_symbol)
{
	bool equal = false;
	if (left_symbol == '(' and right_symbol == ')')
		equal = true;
	if (left_symbol == '{' and right_symbol == '}')
		equal = true;
	return equal;
}