#include "MA.h"
#include <iostream>
using namespace std;

//constractor
MA::MA(int a, string b, string c, int d, int* f, bool flag) :BA(a, b, c, d, f)
{
	research = flag;
}
//dtor
MA::~MA()
{
}
bool MA::milga1()
{
	int sum = 0;
	if ((numCourse >= 7) && (research))
	{
		for (int i = 0; i < size; i++)
			sum += grades[i];
		if (sum / size > 90)
			return true;
	}
	return false;
}
void MA::print()
{
	BA::print();
	cout << "research: ";
	if (research)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
//get
string MA::getname(){return name;}
string MA::getFname(){return lastName;}
bool MA::getresearch(){return research;}
string MA::studType(){return "MA";}
