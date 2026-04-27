
#include<iostream>
#include"MA.h"

MA::MA(bool newstudy,int length,double* marks,string id, string name, string family,int numOfCourses):BA(length,marks,id,name,family,numOfCourses)
{
	study = newstudy;
}
void MA::print()
{
	BA::print();

	if(study == true)
		cout<<"research: yes"<<endl;
	else
		cout<<"research: no"<<endl;
}
bool MA::milga()
{
	if (!study)
		return false;
	float zover = 0;
	for (int i = 0; i < length; i++)
	zover += marks[i];
	zover = zover / length;
	if (zover < 90)
		return false;
	return true;
};