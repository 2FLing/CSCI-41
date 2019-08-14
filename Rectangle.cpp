#include<iostream>
#include<stdio.h>
#include"rectangle.h"
using namespace std;
Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}
Rectangle::Rectangle(double l, double w)
{
	length = l;
	width = w;
}

void Rectangle::setRectangle(double l, double w)
{
	length = l;
	width = w;
}
void Rectangle::display()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 or i == length - 1 or j == 0 or j == width - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}
