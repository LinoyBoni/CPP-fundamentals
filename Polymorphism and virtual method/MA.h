#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include"BA.h"
class MA: public BA
{
public:
	bool study;
public:
	MA(bool study,int length,double* marks,string id, string name, string family,int numOfCourses);
	bool milga();
	void print();
};
