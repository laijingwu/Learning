#include <iostream>
using namespace std;

class Cat {
public:
	static int howManyCats;
	static int getHowMany() { return howManyCats; }
	Cat() { howManyCats++; }
};

int Cat::howManyCats = 0;

int main()
{
	Cat black;
	Cat white;
	cout << Cat::getHowMany() << endl;
	return 0;
} 
