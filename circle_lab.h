#include<iostream>
#include<stdio.h>
using namespace std;
class Circle
{
private:
	double radius;
public:
	void set_radius(double r);
	void display();
	Circle (double r);
	Circle();
	Circle operator-(Circle c);
	Circle operator*(Circle c);
	bool operator<=(Circle c);
	friend ostream& operator<<(ostream& os, Circle& c);
};
void Circle::set_radius(double r)
{
	radius = r;
}
Circle::Circle()
{
	radius= 0;
}
void Circle::display()
{
	cout << "This is a circle the radius is: " << radius << endl;
}
Circle::Circle(double r)
{
	radius = r;
}
Circle Circle::operator-(Circle c)
{
	Circle new_c;
	new_c.set_radius(this->radius - c.radius);
	return new_c;
}
Circle Circle::operator*(Circle c)
{
	Circle new_c;
	new_c.set_radius(this->radius * c.radius);
	return new_c;
}
bool Circle::operator<=(Circle c)
{
	bool smaller = false;
	if (this->radius <= c.radius)
		smaller = true;
	return smaller;
}
ostream& operator<<(ostream& os, Circle& c)
{
	os << "This is a circle, the radius is: " << c.radius << endl;
	return os;
}