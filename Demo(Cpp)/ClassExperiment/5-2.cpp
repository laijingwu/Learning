#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
	int x;
	int y;
	Point(int a, int b) : x(a), y(b) { } 
};

class Circle : public Point {
	int r;
public:
	Circle(int x, int y, int round) : Point(x, y), r(round) { }
	void isInIt(const Point &p);
};

void Circle::isInIt(const Point &p)
{
	double x = p.x - x;
	double y = p.y - y;
	double length = sqrt(pow(x, 2) + pow(y, 2));
	if (length < r)
		cout << "in the circle." << endl;
	else if(length == r)
		cout << "on the circle." << endl;
	else
		cout << "out of the circle." << endl;
}

int main()
{
	Circle r1(5, 3, 4);
	Point p(1, 3);
	r1.isInIt(p);
	return 0;
}
