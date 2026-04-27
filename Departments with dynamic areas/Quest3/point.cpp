/*
implementaion class point
C++ course
exercise 3.3
name:linoy boni
*/
#include"point.h"
#include<math.h>

point::point()
{
	x = 0;
	y = 0;
}
point::point(double MYx,double MYy)
{
	x = MYx;
	y = MYy;
}
double point::getX()
{return x;}
double point::getY()
{return y;}
void point::setX(double newX)
{x = newX;}
void point::setY(double newY)
{y = newY;}
double point::distance(point p1, point p2)
{
	double NEWX = pow((p1.x - p2.x),2);
	double NEWY = pow((p1.y - p2.y),2);
	return sqrt(NEWX+NEWY);
}
