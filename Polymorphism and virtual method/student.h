
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	string id;
	string name;
	string family;
	int numOfCourses;
public:
	 Student(string id, string name, string family,int numOfCourses);//ctor
	 virtual ~Student();
	 virtual bool milga() = 0;
	 virtual void print();
};