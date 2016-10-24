#include<iostream>
#include<cmath>
using namespace std;

class rectangle2d
{
private:
	double x;
	double y;
	double height;
	double width;
public:
//default rectangle
	rectangle2d()
	{
		x = 0;
		y = 0;
		height = 1;
		width = 1;
	}
//specified rectangle
	rectangle2d(double x2, double y2, double height2, double width2)
	{
		x = x2;
		y = y2;
		height = height2;
		width = width2;
	}
//get and set functions
	double getx()const
	{
		return x;
	}
	void setx(double x2)const
	{
		x2=x;
	}
	double gety()const
	{
		return y;
	}
	void sety(double y2)const
	{
		y2=y;
	}
	double getheight()const
	{
		return height;
	}
	void setheight(double height2)const
	{
		height2 = height;
	}
	double getwidth()const
	{
		return width;
	}
	void setwidth(double width2)const
	{
		width2 = width;
	}
//return area
	double getarea()const
	{
		return height*width;
	}
//return perimeter
	double getperimeter()const
	{
		return height + height + width + width;
	}
//returns true if specified rectangle in this rectangle
	bool contains(double x, double y)
	{
		return(x <= this->x + width / 2 && x >= this->x - width / 2) && (y <= this->y + height / 2 && y >= this->y - height / 2);
	}
	bool contains(const rectangle2d &r)
	{
		return ((this->x + width / 2) >= (r.getx() + r.getwidth() / 2) && (this->x - width / 2) <= (r.getx() - r.getwidth() / 2) && ((this->y + height / 2) <= (r.gety() + r.getheight() / 2)) && (this->y - height / 2) >= (r.gety() - r.getheight() / 2));
	}
	
	//determine overlap if rectabgle falls within range 
	bool overlaps(const rectangle2d &r)
	{
			((this->x + width / 2) <= (r.getx() + r.getwidth() / 2) && (this->x - width / 2) >= (r.getx() - r.getwidth() / 2))

		|| ((this->y + height / 2) <= (r.gety() + r.getheight() / 2) && (this->y - height / 2) >= (r.gety() - r.getheight() / 2))

		|| ((this->x + width / 2) >= (r.getx() + r.getwidth() / 2) && (this->x - width / 2) <= (r.getx() + r.getwidth() / 2))

		|| ((this->x + width / 2) >= (r.getx() - r.getwidth() / 2) && (this->x - width / 2) <= (r.getx() - r.getwidth() / 2))

		|| ((this->y + height / 2) >= (r.gety() + r.getheight() / 2) && (this->y - height / 2) <= (r.gety() - r.getheight() / 2))

		|| ((this->y + height / 2) >= (r.gety() - r.getheight() / 2) && (this->y - height / 2) <= (r.gety() - r.getheight() / 2))
	
			; return true;
	}
};

int main()
{
	rectangle2d r1(2, 2, 5.5, 4.9);
	cout << "Area: " << r1.getarea()<< endl;
	cout << "Perimeter: " << r1.getperimeter() << endl;
	rectangle2d r2(4, 5, 10.5, 3.2);
	rectangle2d r3(3, 5, 2.3, 5.4);
	cout << "Test r1.contains(3,3): "<<boolalpha<<r1.contains(3, 3) << endl;
	cout << "Test r1.contains(r2): "<< boolalpha<<r1.contains(r2) << endl;
	cout << "Test r1.overlaps(r3): "<< boolalpha<<r1.overlaps(r3) << endl;
}