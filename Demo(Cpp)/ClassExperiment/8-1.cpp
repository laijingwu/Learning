#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// ���ļ� ��ʼ������ Ҳ������open��Ա���� 
	fstream file("test.txt", ios::in|ios::out);
	
	// ����ļ��Ƿ�򿪳ɹ� 
	if (!file.is_open()) {
		cout << "file open failed." << endl;
		return 1;
	}
	
	// ͨ���ļ�����ȡ 
	string str;
	while (!file.eof()) {
		str.clear();
		file >> str;
		cout << str << endl;
	}
	file.close();	// �ر��ļ� 
	return 0;
}
