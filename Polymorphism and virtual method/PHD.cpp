
#include<iostream>
#include"student.h"
#include"PHD.h"

PHD::PHD(double newweeklyhours,string id,string name,string family,int numOfCourses):Student(id,name,family,numOfCourses)
{
	weeklyhours = newweeklyhours;
}
void PHD::print()
{
	Student::print();
	cout<<"hours: "<<weeklyhours<<endl;
}
bool PHD::milga()
{
	if (numOfCourses < 2)
		return false;
	if (weeklyhours < 25)
		return false;
	return true;
}