#include <iostream>
using namespace std;

class Complex {
	double real;
	double imag;
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) { }
	Complex operator+(Complex &c1);
	Complex operator*(Complex &c1);
	friend ostream & operator<<(ostream &, const Complex &);
	friend istream & operator>>(istream &, Complex &);
};

Complex Complex::operator+(Complex &c1)
{
	return Complex(real + c1.real, imag + c1.imag);
}

Complex Complex::operator*(Complex &c1)
{
	return Complex(real * c1.real - imag * c1.imag, real * c1.real + imag * c1.real);
}

ostream & operator<<(ostream & out, const Complex & c)
{
	out << "(" << c.real << "+" << c.imag << "i)";
	return out;
}

istream & operator>>(istream & in, Complex & c)
{
	cout << "input real part and imaginary part of complex number:";
	in >> c.real >> c.imag;
	return in;
}

int main()
{
	Complex c1, c2, c3, c4;
	cin >> c1;
	cin >> c2;
	c3 = c1 + c2;
	c4 = c1 * c2;
	cout << "c3 = " << c3 << endl;
	cout << "c4 = " << c4 << endl;
	return 0;
}
