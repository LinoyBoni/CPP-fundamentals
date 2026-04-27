/*
creating a helping class
class point
C++ course
exercise 1.3
name:linoy boni
*/
#ifndef POINT_H
#define POINT_H
#include<iostream>
using namespace std;
class Point
{
private:
	double x;
	double y;
public:
	//constructor
	Point();
	Point(double myX,double myY);
	//set methods
	void setX(double x);
	void setY(double y);
	//get methods
	double getX();
	double getY();
};
#endif
