#include <iostream>
using namespace std;

// �򻯺���ָ��ʹ�� 
typedef int (*Func)(const int &, const int &);
 
int test(const int &n1, const int &n2) {
	cout << "test function: n1=" << n1 << " ,n2=" << n2 << endl;
}

int test1(const int &n1, const int &n2) {
	cout << "test1 function: n1=" << n1 << " ,n2=" << n2 << endl;
}

// ���β� �������β�д���� 
void testp(int pf1(const int &, const int &), int (*pf2)(const int &, const int &), Func pf3) {
	pf1(100, 101);
	pf2(102, 103);
	pf3(104, 105); 
}

// ���������� 
// ����д����int (*ff(int i))(const int &, const int &)
Func ff(int i = 0) {
	Func pf = test1;
	return pf;
}

int main() {
	Func pf = test;	// ʵ�ʺ���Ϊint (*)(const int &, const int &)
	pf = &test;
	test(1, 2);
	
	// ���ֵ��÷�ʽ 
	pf(10, 11);
	(*pf)(10, 12);
	
	testp(pf, pf, pf);
	pf = ff();
	testp(pf, pf, pf);
	return 0;
} 
