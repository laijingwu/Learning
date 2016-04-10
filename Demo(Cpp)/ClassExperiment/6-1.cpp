#include <iostream>
using namespace std;

class Shape {
public:
	virtual double getArea() { }
};

class Rectangle : public Shape {
	int x;
	int y;
public:
	Rectangle(int a, int b) : x(a), y(b) { }
	double getArea() { return x*y; }
};

class Circle : public Shape {
	int r;
public:
	Circle(int round) : r(round) { }
	double getArea() { return r*r*3.14159; }
}; 

int main()
{
	Rectangle a(5,3);
	cout << a.getArea() << endl;
	Circle b(6);
	cout << b.getArea() << endl;
	return 0;
}
