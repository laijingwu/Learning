#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// 打开文件 初始化对象 也可以用open成员函数 
	fstream file("test.txt", ios::in|ios::out);
	
	// 检查文件是否打开成功 
	if (!file.is_open()) {
		cout << "file open failed." << endl;
		return 1;
	}
	
	// 通过文件流读取 
	string str;
	while (!file.eof()) {
		str.clear();
		file >> str;
		cout << str << endl;
	}
	file.close();	// 关闭文件 
	return 0;
}
