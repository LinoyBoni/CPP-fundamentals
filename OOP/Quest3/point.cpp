/*
implementaion class Point
C++ course
exercise 1.3
name:linoy boni
*/
#include"point.h"
//constructor
Point::Point()
{
	x=0;
	y=0;
}
Point::Point(double myX ,double myY)
{
	x=myX;
	y=myY;
}
//set methods
void Point::setX(double newx){x=newx;}
void Point::setY(double newy){y=newy;}
//get methods
double Point::getX(){return x;}
double Point::getY(){return y;}
