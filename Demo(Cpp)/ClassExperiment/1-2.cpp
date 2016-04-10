#include <iostream>
#include <cstring>
using namespace std;

class Student {
	int id;
	char name[10];
	int score[3];
public:
	void setId(int stuid) { id = stuid; }
	void setName(const char *stuname) { strncpy(name, stuname, sizeof(name)); }
	void setScore(int n, int num);
	void display();
};

void Student::setScore(int n, int num)
{
	if (n > 2 || n < 0)
		return;
	score[n] = num;
}

void Student::display()
{
	cout << "id:" << id << endl;
	cout << "name:" << name << endl;
	for (int i = 0; i < 3; i++)
		cout << "score" << i+1 << ":" << score[i] << endl;
}

int main()
{
	int id, score = 0;
	char name[10];
	Student xiaoMing;
	cout << "input student id:";
	cin >> id;
	xiaoMing.setId(id);
	cout << "input student name:";
	cin >> name;
	xiaoMing.setName(name);
	cout << "input student score in 3 subjects:";
	for (int i = 0; i < 3; i++) {
		cin >> score;
		xiaoMing.setScore(i, score);
	}
	xiaoMing.display();
	return 0;
}
