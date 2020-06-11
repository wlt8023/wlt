#pragma once

class Father
{
public:
	Father(int n = 0);
	~Father();

	virtual void func1();
	virtual void func2();
	virtual void func3();
	void func4();

public:
	int n;
};

