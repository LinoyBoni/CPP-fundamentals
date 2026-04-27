#include "PHD.h"
#include <iostream>
using namespace std;

//constractor
PHD::PHD(int a, string b, string c, int d, int h) :Student(a, b, c, d)
{
	hours = h;
}
//dtor
PHD::~PHD(){}
bool PHD::milga1()
{
	if (numCourse == 2 && hours > 25)
		return true;
	return false;
}
void PHD::print()
{
	Student::print();
	cout << "hours: " << hours << endl;
}
string PHD::studType(){return "PHD";}
//get
string PHD::getname(){return name;}
string PHD::getFname(){return this->lastName;}
bool PHD::getresearch(){return true;}
int PHD::gethours(){return hours;}

