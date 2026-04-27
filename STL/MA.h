#pragma once
#include "BA.h"
#include <iostream>
using namespace std;

class MA :public BA
{
	bool research;
public:
	//constractor
	MA(int, string, string, int, int*, bool);
	//dtor
	~MA();
	bool milga1();
	void print();
	string getname();
	string getFname();
	bool getresearch();
	string studType();
};



