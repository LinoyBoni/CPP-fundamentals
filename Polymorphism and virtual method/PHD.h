#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include"student.h"
class PHD: public Student
{
public:
	double weeklyhours;
public:
	PHD(double weeklyhours,string id, string name, string family,int numOfCourses);
	bool milga();
	void print();
};