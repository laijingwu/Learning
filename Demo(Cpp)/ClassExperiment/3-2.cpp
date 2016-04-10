#include <iostream>
using namespace std;

class Student {
	int id;
	int score;
public:
	static int totalScore;
	static int totalStudent;
	static double getAvg() { return ((double)totalScore)/totalStudent; }
	Student(int m_id, int m_score) { id = m_id; score = m_score; totalStudent++; totalScore += score; }
};

int Student::totalScore = 0;
int Student::totalStudent = 0;

int main()
{
	Student xiaoMing(1, 89);
	Student xiaoHong(2, 95);
	Student xiaoLi(3, 72);
	cout << Student::getAvg() << endl;
	return 0;
}
