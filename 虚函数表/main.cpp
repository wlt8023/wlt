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

	cout << "father的地址:" << (int*)&father << endl;
	cout << "father数据地址:" << &father.n << endl;
	cout << "father数据地址:" << std::hex << (int)&father + 4 << endl;

	cout << "------------------------------------------------------------------" << endl;

	cout << "father虚函数表的地址:" << vptr << endl;
	for (int i = 0; i < 3; i++) {
		cout << "调用father第" << i + 1 << "个虚函数:";
		((func_t)* (vptr + i))();
	}

	cout << "------------------------------------------------------------------" << endl;

	vptr = (int*)*(int*)&son;

	cout << "son的地址:" << (int*)&son << endl;
	cout << "son继承father的数据地址:" << (int)&son.n << endl;
	cout << "son继承father的数据地址:" << (int)&son + 4 << endl;

	cout << "------------------------------------------------------------------" << endl;
	
	cout << "son继承mother的虚函数表地址:" << (int)&son + 8 << endl;
	cout << "son继承mother的数据地址:" << (int)&son.m << endl;
	cout << "son继承mother的数据地址:" << (int)&son + 12 << endl;

	cout << "------------------------------------------------------------------" << endl;

	cout << "son第一个虚函数表地址:" << vptr << endl;
	for (int i = 0; i < 4; i++) {
		cout << "调用son第一个虚函数表第" << i + 1 << "个虚函数:";
		((func_t) * (vptr + i))();
	}

	cout << "------------------------------------------------------------------" << endl;

	vptr = (int*)*(int*)((int)&son + 8);
	cout << "son第二个虚函数表地址:" << vptr << endl;
	for (int i = 0; i < 3; i++) {
		cout << "调用son第二个虚函数表第" << i + 1 << "个虚函数:";
		((func_t) * (vptr + i))();
	}

	system("pause");
	return 0;
}