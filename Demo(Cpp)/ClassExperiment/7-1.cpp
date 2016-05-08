#include <iostream>
#include <ostream>
using namespace std;

class Date {
	int year;
	int month;
	int day;
public:
	Date(int Y, int M, int D) : year(Y), month(M), day(D) { }
	Date & operator++();	// Ç°×º
	const Date operator++(int);	// ºó×º
	Date & operator--();
	const Date operator--(int);
	friend ostream & operator<<(ostream &, const Date &);
	int getMonthDayNum(int Y, int M);
};

int Date::getMonthDayNum(int Y, int M) {
	int D = 1;
	if (M == 4 || M == 6 || M == 9 || M == 11)
		D = 30;
	else if (M == 2)
	{
		bool isLeapYear = (Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0);
		if (isLeapYear)
			D = 29;
		else
			D = 28;
	}
	else
		D = 31;
	return D;
}

Date& Date::operator++() {
	day++;
	if (this->getMonthDayNum(year, month) < day) {
		day = 1;
		month++; 
	}
	if (month > 12) {
		year++;
		month = 1;
	}
	return *this;
}

const Date Date::operator++(int) {
	const Date temp = *this;
	++(*this);
	return temp;
}

Date& Date::operator--() {
	if (day == 1) {
		if (month == 1) {
			year--;
			month = 12;
		} else {
			month--;
		}
		day = this->getMonthDayNum(year, month);
	} else {
		day--;
	}
	return *this;
}

const Date Date::operator--(int) {
	const Date temp = *this;
	--(*this);
	return temp;
}

ostream & operator<<(ostream & out, const Date & t) {
	out << t.year << "-" << t.month << "-" << t.day << endl;
	return out;
}

int main() {
	Date date1(2016, 5, 31);
	cout << date1;
	cout << ++date1;
	cout << date1++;
	cout << date1;
	cout << --date1;
	cout << date1--;
	cout << date1;
	return 0;
}
