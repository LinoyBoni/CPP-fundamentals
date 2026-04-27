#ifndef CIRCLE_H
#define CIRCLE_H
#include"point.h"
/*
class circle
C++ course
exercise 1.3
name:linoy boni
*/
class Circle
{
private:
   Point p;
   double radius;
public:
	//constructor
	Circle();
	Circle(Point newP,double newRadius);
	//set N get methods
	void setRadius(double r);
	double getRadius();
	//helping functions
	double areaCircle(double r,float const PI=3.14);
	double scopeCircle(double r,double const PI=3.14);
	int checkingPoint(Point p);
};
#endif
   
