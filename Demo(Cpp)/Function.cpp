#include <iostream>
using namespace std;

void f(int *i) {
	cout << "f(int *i) :" << *i << endl;
}

// �˴�constΪָ����ָ����Ϊconst 
void f(const int *i) {
	cout << "f(const int *i) :" << *i << endl;
}

// �������ÿ���Ϊ��ֵ 
int & test(int &n) {
	n = 5;
	return n;
}

// ��������д�� 
void test(int (&n)[5]) {
	cout << "test(int (&n)[5]) :" << n[0] << endl;
}

/* ����ָ��д��
error: ����һ�ַ��������޷�ѡ�� 
void test(int *n) {	// void test(int n[])
	cout << "test(int *n) :" << *n << endl;
}
*/

// ͨ��ָ�루��������δ֪�������飩���� 
void test(const int *beg, const int *end) {
	while(beg != end) {
		cout << *beg++ << " ";
	}
	cout << endl;
}

// �������� һ��д��ͷ�ļ��� 
inline void line() {
	cout << "line" << endl;
}

int main() {
	const int n1 = 1;
	f(&n1);
	
	int n2 = 1;
	test(n2);
	cout << n2 << endl;
	
	int n3[5] = { 1, 2, 3, 4, 5};
	test(n3);
	
	test(n3, n3 + 5);
	
	line(); 
	return 0;
} 
