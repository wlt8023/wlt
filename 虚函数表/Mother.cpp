#include<iostream>
#include "Mother.h"

using namespace std;

Mother::Mother(int m)
{
	this->m = m;
}

Mother::~Mother()
{
}

void Mother::func5()
{
	cout << "Mother::func1" << endl;
}

void Mother::func6()
{
	cout << "Mother::func2" << endl;
}

void Mother::func7()
{
	cout << "Mother::func3" << endl;
}

void Mother::func8()
{
	cout << "Mother::func4" << endl;
}
