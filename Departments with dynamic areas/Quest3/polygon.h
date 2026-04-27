/*
class polygon
C++ course
exercise 3.3
name:linoy boni
*/
#ifndef POLYGON_H
#define POLYGON_H
#include"point.h"
class polygon
{
private:
	point* a;
	int N;//number 
public:
	//constructor
	//polygon();
	polygon(int num);
	polygon(polygon & p);//copy ctor
	~polygon();//dtor

	point* getA();
	double scopePolygon(polygon & p1);
};
#endif
