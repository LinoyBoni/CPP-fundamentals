
#include<iostream>
#include<string>
#include"BA.h"

BA::BA(int newlength,double* newmarks,string id,string name,string family,int numOfCourses):Student(id,name,family,numOfCourses)//ìáãå÷ àí æä áñãø
{
	if(newmarks == NULL)
		marks = new double[newlength];
	else
		marks = newmarks;
	length = newlength;
}
void BA::print()
{
	Student::print();
	cout<<"grades: ";
	for(int i=0; i<length; i++)
	{
		cout<<marks[i]<<" ";
	}
	cout<<endl;
}
bool BA::milga()
{
	if (numOfCourses < 10)
		return false;
	float zover = 0;
	for (int i = 0; i < length; i++)
	zover += marks[i];
	zover = zover / length;
	if (zover < 95)
		return false;
	return true;
}