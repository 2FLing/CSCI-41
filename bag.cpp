#include<stdio.h>
#include<random>
#include<iostream>
#include"bag.h"
int main()
{
	int num;
	Bag myBag;
	for (int i = 0; i < 30; i++)
	{
		num = rand() % 10;
		if (!myBag.contains(num))
			myBag.add(num);
	}
	return 0;
}