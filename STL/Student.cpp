
#include <iostream>
using namespace std;
#include "Student.h"
#include <string>
//constractor
Student::Student(){}
Student::Student(int n, string s, string b, int m)
{
	id = n;
	name = s;
	lastName = b;
	numCourse = m;
}
//dtor
Student::~Student(){}
void Student::print()
{
	cout << "ID: " << id << endl << "first name: " << name << endl << "last name: " << lastName << endl << "num courses: " << numCourse << endl;
}
string Student::studType(){return string();}
bool milga1();
int Student::getnumcouses(){return numCourse;}
int Student::gethours(){return 0;}
