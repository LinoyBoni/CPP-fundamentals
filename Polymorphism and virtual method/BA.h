
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include"student.h"
using namespace std;
class BA : public Student
{
public:
	double* marks;
	int length;
public:
	BA(int length,double* marks,string id, string name, string family,int numOfCourses);
	bool milga();
	void print();
};

