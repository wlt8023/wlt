#include<iostream>
#include "Father.h"

using namespace std;

Father::Father(int n)
{
	this->n = n;
}

Father::~Father()
{
}

void Father::func1()
{
	cout << "Father::func1" << endl;
}

void Father::func2()
{
	cout << "Father::func2" << endl;
}

void Father::func3()
{
	cout << "Father::func3" << endl;
}

void Father::func4()
{
	cout << "Father::func4" << endl;
}
