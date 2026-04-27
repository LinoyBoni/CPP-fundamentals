#pragma once
#include "Student.h"
#include <iostream>
using namespace std;

class PHD :
	public Student
{
	int hours;
public:
	//constractor
	PHD(int, string, string, int, int);
	//dtor
	~PHD();
	bool milga1();
	void print();
	string studType();
	string getname();
	string getFname();
	bool getresearch();
	int gethours();
	
};

