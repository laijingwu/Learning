#include <iostream>
#include <cstring>
using namespace std;

class Student {
	int id;
	char name[10];
	bool sex;	// false:女  true:男 
	char grade[10];
public:
	Student(int m_id = 1, char *m_name = "小明", bool m_sex = true, char *m_grade = "高二"); 
	Student(int m_id, const char *m_name);
	void display();
	void setSex(bool m_sex) { sex = m_sex; }
	void setGrade(const char *m_grade) { strncpy(grade, m_grade, sizeof(grade)); }
};

Student::Student(int m_id, char *m_name, bool m_sex, char *m_grade) : id(m_id), sex(m_sex)
{
	strncpy(name, m_name, sizeof(name));
	strncpy(grade, m_grade, sizeof(grade));
}

Student::Student(int m_id, const char *m_name) : id(m_id)
{
	strncpy(name, m_name, sizeof(name));
}

void Student::display()
{
	cout << "id:" << id << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << (sex==true ? "男" : "女") << endl;
	cout << "grade:" << grade << endl;
}

int main()
{
	Student stu1;
	Student stu2(2, "小红");
	stu1.display();
	stu2.setSex(false);
	stu2.setGrade("高一");
	stu2.display(); 
	return 0;
} 
