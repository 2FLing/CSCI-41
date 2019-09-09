#ifndef _Cylinder
#define _Cylinder
#include<stdio.h>
using namespace std;
class Cylinder
{
private:
	double height;
	double radius;
public:
	Cylinder(double num1, double num2);
	Cylinder();
	bool operator==(Cylinder& cy);
	friend ostream& operator<<(ostream& os, Cylinder cy);
};

Cylinder::Cylinder(double num1, double num2)
{
	height = num1;
	radius = num2;
}
Cylinder::Cylinder()
{
	height = 0;
	radius = 0;
}
bool Cylinder::operator==(Cylinder& cy)
{
	bool equal = false;
	if (cy.height == this->height and cy.radius == this->radius)
	{
		equal = true;
	}
	return equal;
}
ostream& operator<<(ostream& os, Cylinder cy)
{
	os << "This cylinder`s height is: " << cy.height << ", and it`s radius is : " << cy.radius << endl;
	return os;
}
#endif