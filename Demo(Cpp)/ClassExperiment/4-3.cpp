#include <iostream>
using namespace std;

class Time {
	int hour;
	int minute;
	int second;
public:
	Time(int m_hour, int m_minute, int m_second) : hour(m_hour), minute(m_minute), second(m_second) { }
	friend int relSecond(Time &t1, Time &t2);
};

int relSecond(Time &t1, Time &t2)
{
	int t1_sec = t1.hour * 3600 + t1.minute * 60 + t1.second;
	int t2_sec = t2.hour * 3600 + t2.minute * 60 + t2.second;
	if (t1_sec >= t2_sec)
		return t1_sec - t2_sec;
	else
		return t2_sec - t1_sec;
}

int main()
{
	int hour, minute, second;
	cout << "input time 1:";
	cin >> hour >> minute >> second;
	Time t1(hour, minute, second);
	hour = minute = second = 0;
	cout << "input time 2:";
	cin >> hour >> minute >> second;
	Time t2(hour, minute, second);
	cout << "relative second:" << relSecond(t1, t2) << endl;
	return 0;
}
