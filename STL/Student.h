
#include <iostream>
#include <string>
using namespace std;
#pragma once

class Student
{
protected:
	int id;
	string name;
	string lastName;
	int numCourse;
public:
	//constractor
	Student();
	Student(int, string, string, int);
	//virtual
	virtual bool milga1() = 0;
	virtual void print();
	virtual string studType() = 0;
	virtual string getname() = 0;
	virtual string getFname() = 0;
	virtual bool getresearch() = 0;
	int getnumcouses();
	//dtor
	virtual ~Student();
	virtual int gethours();
};

