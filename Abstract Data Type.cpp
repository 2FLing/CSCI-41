#include<stdio.h>
#include<random>
#include"TemplateBag.h"
#include"Rectangle.h"
using namespace std;
int main()
{
	Bag<char> myBag;
	Bag<int>myBag_2;
	Bag<Rectangle>RecBag;
	Rectangle rc1(2,3);
	int num;
	myBag.add('u');
	myBag.add('&');
	myBag.add('w');
	myBag.display();
	myBag_2.add(2);
	myBag_2.display();
	RecBag.add(rc1);
	RecBag.display();
	return 0;
}