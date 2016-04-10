#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class Shape
{
protected:
    int x;
	int y;
public:
    void setValue(int d, int w = 0) { x = d; y = w; }
    virtual void display() = 0;	//纯虚函数
};

class OutSquare : public Shape {
public:
    void display() {
        cout << "外切正方形面积:" << x*x << endl;
        cout << "外切正方形周长:" << 4*x << endl;
    }
};

class InSquare : public Shape {
public:
    void display() {
        cout << "内接正方形面积:" << pow(x*sqrt(2), 2) << endl;
        cout << "内接正方形周长:" << 4*x*sqrt(2) << endl;
    }
};

class Circle : public Shape {
public:
    void display() {
        cout << "圆面积:" << PI*x*x << endl;
        cout << "圆周长:" << PI*2*x << endl;
    }
};

int main()
{
	Circle c;
	c.setValue(6);
	c.display();
	InSquare i;
	i.setValue(6);
	i.display();
	OutSquare o;
	o.setValue(6);
	o.display();
	return 0;
}
