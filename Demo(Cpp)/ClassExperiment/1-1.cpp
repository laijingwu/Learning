#include <iostream>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	void setday(int n_year, int n_month, int n_day);
	void display();
};

void Date::setday(int n_year, int n_month, int n_day)
{
	year = n_year;
	month = n_month;
	day = n_day;
}

void Date::display()
{
	cout << year << "-" << month << "-" << day << endl;
}

int main()
{
	Date date1;
	Date date2;
	date1.setday(2015, 9, 1);
	date2.setday(2016, 4, 5);
	date1.display();
	date2.display();
	return 0;
}
