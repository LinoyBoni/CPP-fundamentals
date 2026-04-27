/*
class point
C++ course
exercise 3.3
name:linoy boni
*/
#ifndef POINT_H
#define POINT_H
#include<iostream>
using namespace std;
class point
{
private:
	double x;
	double y;
public:
	//constructor
	point();
	point(double MYx, double MYy);
	//set N get
	double getX();
	double getY();
	void setX(double newX);
	void setY(double newY);

	double distance(point p1, point p2);
};
#endif