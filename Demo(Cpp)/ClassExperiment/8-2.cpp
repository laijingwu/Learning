#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	fstream from("test.txt", ios::in|ios::out);
	fstream to("test1.txt", ios::in|ios::out|ios::trunc);	// 文件存在，清空内容 
	
	// 检查文件是否打开成功 
	if (!from.is_open() || !to.is_open()){
		cout << "file open failed." << endl;
		return 1;
	}
	
	// 单字符读取写入 
	char singleBuffer;
	while(!from.eof()) {
		singleBuffer = 0;	// 清空字符缓冲变量 
		from.get(singleBuffer);	// from >> singleBuffer; 会跳过空格和换行 
		to << singleBuffer;
	}
	cout << "single words were written." << endl;
	
	from.clear();	// 重置状态
	from.seekg(0, ios::beg);	// 定位到文件头 
	to.clear();
	to.seekp(0, ios::beg);	// 定位到文件头 
	// 行方式读取写入 
	char lineBuffer[100] = { 0 };
	while (!from.eof()) {
		memset(lineBuffer, 0, 100);	// 清空字符串缓冲 
		from.getline(lineBuffer, 100);
		to << lineBuffer << endl;	// 手动补换行符 
	}
	from.close();	// 关闭文件 
	to.close();
	cout << "all lines were written." << endl;
	return 0;
}
