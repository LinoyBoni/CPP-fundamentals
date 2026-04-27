#pragma once
#include "Student.h"
#include <iostream>
using namespace std;

class BA :public Student
{
protected:
	float* grades;
	int size;
public:
	//constractor
	BA(int, string, string, int, int*);
	//dtor
	~BA();
	bool milga1();
	void print();
	string getname();
	string getFname();
	bool getresearch();
	string studType();
};

