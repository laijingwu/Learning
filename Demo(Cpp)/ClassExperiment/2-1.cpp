#include <iostream>
using namespace std;

class Rectangle {
	int length;
	int width;
public:
	Rectangle(int m_length, int m_width);
	Rectangle(const Rectangle &r);
	~Rectangle();
	void showArea() { cout << "area:" << length*width << endl; }
	void showPerimeter() { cout << "perimeter:" << (length+width)*2 << endl; }
};

Rectangle::Rectangle(int m_length, int m_width)
{
	length = m_length;
	width = m_width;
}

Rectangle::Rectangle(const Rectangle& r)
{
	//length = r.length;
	//width = r.width;
	
	// 为测试构造函数是否运行 
	length = 4;
	width = 3;
}

Rectangle::~Rectangle()
{
	cout << "Rectangle destructint" << endl;
}

void display(Rectangle tmp)	// 对象经过拷贝 
{
	tmp.showArea();
	tmp.showPerimeter();
}

int main()
{
	Rectangle rect(5, 10);
	rect.showArea();
	rect.showPerimeter();
	display(rect);
	return 0;
}
