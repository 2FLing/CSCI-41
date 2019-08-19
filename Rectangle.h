class Rectangle
{
private:
	double length;
	double width;
public:
	Rectangle();
	Rectangle(double l, double w);
	Rectangle(double l);
	Rectangle operator+(Rectangle& Rec);
	void GetLength(double l);
	void GetWidth(double l);
	void setRectangle(double l, double w);
	void display();
};
Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}
Rectangle::Rectangle(double l)
{
	lenth = l;
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

void Rectangle::GetLength(double l)
{
	length = l;
}
void Rectangle::GetWidth(double w)
{
	width = w;
}
Rectangle Rectangle::operator+(Rectangle& Rec)
{
	Rectangle r;
	r.GetLength(this->length + Rec.length);
	r.GetWidth(this->width + Rec.width);
	return r;
}
