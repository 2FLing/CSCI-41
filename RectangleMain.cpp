#include<iostream>
#include<stdio.h>
#include"rectangle.h"
using namespace std;
int main()
{
	Rectangle a(2, 4), b(4),c;
	a.display();
	c = a + b;
	c.display();
	return 0;
}

