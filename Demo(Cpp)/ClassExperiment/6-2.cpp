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
    virtual void display() = 0;	//���麯��
};

class OutSquare : public Shape {
public:
    void display() {
        cout << "�������������:" << x*x << endl;
        cout << "�����������ܳ�:" << 4*x << endl;
    }
};

class InSquare : public Shape {
public:
    void display() {
        cout << "�ڽ����������:" << pow(x*sqrt(2), 2) << endl;
        cout << "�ڽ��������ܳ�:" << 4*x*sqrt(2) << endl;
    }
};

class Circle : public Shape {
public:
    void display() {
        cout << "Բ���:" << PI*x*x << endl;
        cout << "Բ�ܳ�:" << PI*2*x << endl;
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
