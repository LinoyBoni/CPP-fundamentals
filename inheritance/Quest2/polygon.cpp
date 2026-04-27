/*
implementaion class polygon
C++ course
exercise 6.2
name:linoy boni
*/
#include "polygon.h"
#include<iostream>
using namespace std;

Polygon::Polygon(int num)
{
	sides = new int[num];
	numSides = num;
	if ((num != 3) && (num != 4))
	{
		cout <<"enter sides for polygon:"<< endl;
		for (int i = 0; i <num; i++)
		{
			cin >> sides[i];
		}
	}
}
Polygon::Polygon(Polygon * p)
{
	this->numSides = p->numSides;
	sides = new int[numSides];
}
Polygon::~Polygon()
{
	delete[] sides;
}
bool Polygon::operator==(Polygon a)
{
	return (this->numSides == a.numSides&&this->hekef() == a.hekef());
}
int Polygon::hekef()
{
	int sum = 0;
	for (int i = 0; i < numSides; i++)
	{
		sum += sides[i];
	}
	return sum;
}
