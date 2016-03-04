#include <iostream>
using namespace std;

void f(int *i) {
	cout << "f(int *i) :" << *i << endl;
}

// 此处const为指针所指对象为const 
void f(const int *i) {
	cout << "f(const int *i) :" << *i << endl;
}

// 返回引用可作为左值 
int & test(int &n) {
	n = 5;
	return n;
}

// 数组引用写法 
void test(int (&n)[5]) {
	cout << "test(int (&n)[5]) :" << n[0] << endl;
}

/* 数组指针写法
error: 和上一种方法重载无法选择 
void test(int *n) {	// void test(int n[])
	cout << "test(int *n) :" << *n << endl;
}
*/

// 通过指针（不复制且未知长度数组）遍历 
void test(const int *beg, const int *end) {
	while(beg != end) {
		cout << *beg++ << " ";
	}
	cout << endl;
}

// 内联函数 一般写在头文件中 
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
