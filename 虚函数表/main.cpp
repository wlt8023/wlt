#include <iostream>
#include <Windows.h>
#include "Father.h"
#include "Mother.h"
#include "Son.h"

using namespace std;

typedef void (*func_t)(void);

int main(void) {
	Father father;
	Son son;

	cout << "sizeof(father)==" << sizeof(father) << endl;
	cout << "sizeof(son)==" << sizeof(son) << endl;

	int* vptr = (int*)*(int*)&father;

	cout << "father�ĵ�ַ:" << (int*)&father << endl;
	cout << "father���ݵ�ַ:" << &father.n << endl;
	cout << "father���ݵ�ַ:" << std::hex << (int)&father + 4 << endl;

	cout << "------------------------------------------------------------------" << endl;

	cout << "father�麯����ĵ�ַ:" << vptr << endl;
	for (int i = 0; i < 3; i++) {
		cout << "����father��" << i + 1 << "���麯��:";
		((func_t)* (vptr + i))();
	}

	cout << "------------------------------------------------------------------" << endl;

	vptr = (int*)*(int*)&son;

	cout << "son�ĵ�ַ:" << (int*)&son << endl;
	cout << "son�̳�father�����ݵ�ַ:" << (int)&son.n << endl;
	cout << "son�̳�father�����ݵ�ַ:" << (int)&son + 4 << endl;

	cout << "------------------------------------------------------------------" << endl;
	
	cout << "son�̳�mother���麯�����ַ:" << (int)&son + 8 << endl;
	cout << "son�̳�mother�����ݵ�ַ:" << (int)&son.m << endl;
	cout << "son�̳�mother�����ݵ�ַ:" << (int)&son + 12 << endl;

	cout << "------------------------------------------------------------------" << endl;

	cout << "son��һ���麯�����ַ:" << vptr << endl;
	for (int i = 0; i < 4; i++) {
		cout << "����son��һ���麯�����" << i + 1 << "���麯��:";
		((func_t) * (vptr + i))();
	}

	cout << "------------------------------------------------------------------" << endl;

	vptr = (int*)*(int*)((int)&son + 8);
	cout << "son�ڶ����麯�����ַ:" << vptr << endl;
	for (int i = 0; i < 3; i++) {
		cout << "����son�ڶ����麯�����" << i + 1 << "���麯��:";
		((func_t) * (vptr + i))();
	}

	system("pause");
	return 0;
}