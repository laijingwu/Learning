#include <iostream>
#include <cstring>
using namespace std;

class Student {
	char name[15];
	int englishScore;
	int computerScore;
	int totalScore;
public:
	void input();
	void display();
	friend void Sort(Student *T, int n);
	Student& operator=(const Student &T);
};

void Student::input()
{
	cout << "input name:";
	cin >> name;
	cout << "input english score:";
	cin >> englishScore;
	cout << "input computer score:";
	cin >> computerScore;
	totalScore = englishScore + computerScore;
}

void Student::display()
{
	cout << "--------------" << endl;
	cout << "name:" << name << endl;
	cout << "english score:" << englishScore << endl;
	cout << "computer score:" << computerScore << endl;
	cout << "total score:" << totalScore << endl;
}

Student& Student::operator=(const Student &T)
{
	if (this == &T)
		return *this;
	
	strcpy(name, T.name);
	englishScore = T.englishScore;
	computerScore = T.computerScore;
	totalScore = T.totalScore;
	return *this;
}

void Sort(Student *T, int n)
{
	int exchange = 0;
	Student tmp;
	for (int i = 0; i < n - 1; i++)
	{
		exchange = 0;
		for (int j = n - 2 ; j >= 0; j--)
		{
			if (T[j+1].totalScore > T[j].totalScore)
			{
				tmp = T[j+1];
				T[j+1] = T[j];
				T[j] = tmp;
				exchange = 1;
			}
			if (!exchange)
				break;
		}
	}
} 

int main()
{
	int n;
	cout << "input student number:";
	cin >> n;
	Student *p = new Student[n];
	for (int i = 0; i < n; i++)
		p[i].input();
		
	Sort(p, n);
	
	cout << "sort by asc" << endl;
	
	for (int j = 0; j < n; j++)
		p[j].display(); 
	
	return 0;
} 
