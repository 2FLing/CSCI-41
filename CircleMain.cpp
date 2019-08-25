//CSCI 41 Assignment 1
#include<iostream>
#include"Circle.h"
using namespace std;

int main()
{
	Circle a[6] = { Circle(5),Circle(7),Circle(2),Circle(3),Circle(11),Circle(6) };
	Circle new_a[6];
	Circle t;
	t = a[0];
	int position;
	for (int i = 0; i < 6; i++) {
		if (a[i] > t)
			t = a[i];
	}
	cout << "The largest circle is " << t <<endl;
	new_a[0] = a[0];
	for (int i = 1; i < 6; i++)// go through array "a"
	{
		position = 0;// initial the position where circle in array "a" should go in new array
		for (int j = 0; j < i; j++)
		{
			if (a[i] > new_a[j])// if the circle in array "a" is greater than the circle in new array, then move forward one place. 
				position++;
		}
		for (int k = i; k >= position; k--)//These circles after the position of new circle move forward one place.
			if (k + 1 != 6)
				new_a[k + 1] = new_a[k];
		new_a[position] = a[i];//insert the circle to new circle
	}
	cout << "--------This is the new array--------" << endl;
	for (int i = 0; i < 6; i++)
		cout << new_a[i]<<endl;
	//system("pause"); <-- you may need to add this line if you are using VS C++
	return 0;
}
