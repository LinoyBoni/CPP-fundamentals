#include "BA.h"
#include <iostream>
using namespace std;

//constractor
BA::BA(int a, string b, string c, int d, int* grade) :Student(a, b, c, d)
{
	grades = new float[d];
	size = d;
	for (int i = 0; i < d; i++)
		grades[i] = grade[i];
}
//dtor
BA::~BA(){}
bool BA::milga1()
{
	int sum = 0;
	if (numCourse >= 10)
	{
		for (int i = 0; i < size; i++)
			sum += grades[i];
		if (sum / size > 95)
			return true;
	}
	return false;
}
void BA::print()
{
	Student::print();
	cout << "grades: ";
	for (int i = 0; i < size; i++)
		cout << grades[i] << " ";
	cout << endl;
}
string BA::getname(){return name;}
string BA::getFname(){return lastName;}
bool BA::getresearch(){return true;}
string BA::studType(){return "BA";}

