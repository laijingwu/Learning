#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	fstream from("test.txt", ios::in|ios::out);
	fstream to("test1.txt", ios::in|ios::out|ios::trunc);	// �ļ����ڣ�������� 
	
	// ����ļ��Ƿ�򿪳ɹ� 
	if (!from.is_open() || !to.is_open()){
		cout << "file open failed." << endl;
		return 1;
	}
	
	// ���ַ���ȡд�� 
	char singleBuffer;
	while(!from.eof()) {
		singleBuffer = 0;	// ����ַ�������� 
		from.get(singleBuffer);	// from >> singleBuffer; �������ո�ͻ��� 
		to << singleBuffer;
	}
	cout << "single words were written." << endl;
	
	from.clear();	// ����״̬
	from.seekg(0, ios::beg);	// ��λ���ļ�ͷ 
	to.clear();
	to.seekp(0, ios::beg);	// ��λ���ļ�ͷ 
	// �з�ʽ��ȡд�� 
	char lineBuffer[100] = { 0 };
	while (!from.eof()) {
		memset(lineBuffer, 0, 100);	// ����ַ������� 
		from.getline(lineBuffer, 100);
		to << lineBuffer << endl;	// �ֶ������з� 
	}
	from.close();	// �ر��ļ� 
	to.close();
	cout << "all lines were written." << endl;
	return 0;
}
