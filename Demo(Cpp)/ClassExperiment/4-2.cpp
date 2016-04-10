#include <iostream>
#include <cmath>
using namespace std;

class Point {
	int x;
	int y;
public:
	Point(int m_x, int m_y) : x(m_x), y(m_y) { }
	friend double getDistance(const Point &p1, const Point &p2);
};

double getDistance(const Point &p1, const Point &p2)
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{
	int x, y;
	cout << "input point 1:";
	cin >> x >> y;
	Point p1(x,y);
	x = y = 0;
	cout << "input point 2:";
	cin >> x >> y;
	Point p2(x,y);
	cout << "distance:" << getDistance(p1, p2);
	return 0;
}
