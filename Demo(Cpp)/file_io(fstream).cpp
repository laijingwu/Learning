#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// ���ļ� ��ʼ������ Ҳ������open��Ա���� 
	fstream file("test.txt", ios::in|ios::out);
	//file.open("test.txt", ios::app|ios::in|ios::out); //ios::ate �ļ�ĩβ 
	
	// ����ļ��Ƿ�򿪳ɹ� 
	if (!file.is_open())
	{
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
	file.clear();	// ����״̬ 
	file.seekp(0, fstream::end);	// ��λ���ļ�ĩβ 
	//file << "test";	// д���ļ��� 
	file.close();	// �ر��ļ� 
	return 0;
}
