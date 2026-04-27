/*
class polygon
C++ course
exercise 6.2
name:linoy boni
*/
#pragma once
#include<iostream>
using namespace std;
class Polygon 
{
protected:
	int numSides;
	int* sides;
public:
	Polygon(int num);
	Polygon(Polygon* p );
	virtual~Polygon();
	bool operator==(Polygon a);
	int hekef();
};
