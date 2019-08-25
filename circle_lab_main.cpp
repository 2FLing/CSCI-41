#include<iostream>
#include<stdio.h>
#include"Circle.h"
using namespace std;
int main()
{
	Circle a(7),b(5),c;
	c = a - b;
	cout << c<< endl;
	c = a * b;
	cout << c << endl;
	if (c <= b)
		cout << c << endl;
	else
		cout << b << endl;
	return 0;
}