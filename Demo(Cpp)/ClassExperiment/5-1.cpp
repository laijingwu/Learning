#include <iostream>
using namespace std;

class Mammal {
public:
	Mammal() {
		cout << "Mammal class constructing." << endl; 
	}
	~Mammal() {
		cout << "Mammal class destructing." << endl;
	}
};

class Dog : public Mammal {
public:
	Dog() {
		cout << "Dog class constructing." << endl; 
	}
	~Dog() {
		cout << "Dog class destructing." << endl;
	}
};

int main()
{
	Dog a;
	return 0;
}
