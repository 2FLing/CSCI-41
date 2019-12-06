#include<iostream>
using namespace std;
void display(int a[],int length);
int sum(int a[], int length);
int smallest(int a[], int length);
bool contain_native(int a[], int length);
int main()
{
	int a[5] = { 3,0,0,0,6};
	cout <<contain_native(a,5)<<endl;
	return 0;
}
void display(int a[],int length)
{
	if (length == 1)
		cout << a[0] << endl;
	else
	{
		display(a, length - 1);
		cout << a[length-1] << endl;
	}
}
int sum(int a[], int length)
{
	if (length == 1)
		return a[length - 1];
	else
		return a[length - 1] + sum(a, length - 1);
}
int smallest(int a[], int length)
{
	if (length == 1)
	{
		return a[length - 1];
	}
	else
	{
		int n = smallest(a, length - 1);
		if (a[length - 1] < n)
			return a[length - 1];
		else
			return n;
	}

}
bool contain_native(int a[], int length)
{
	if (length == 1)
	{
		if (a[length - 1] < 0)
			return true;
		else
			return false;
	}
	else
	{
		if (a[length - 1] < 0)
			return true;
		else
			return contain_native(a, length - 1);
	}
}