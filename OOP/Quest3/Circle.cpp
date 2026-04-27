/*
implementaion class Circle
C++ course
exercise 1.3
name:linoy boni
*/
#include"circle.h"
//constructors
Circle::Circle()
{
	p.setX(0);
	p.setY(0);
	radius = 0;
}
Circle::Circle(Point newP,double newRadius)
{
	p.setX(newP.getX());
	p.setY(newP.getY());
	radius = newRadius;
}
//set N get methods
void Circle::setRadius(double r){radius = r;}
double Circle::getRadius(){return radius;}
//helping functions
double Circle::areaCircle(double r,float const PI){return r*r*PI;}
double Circle::scopeCircle(double r,double const PI){return 2*r*PI;}
int Circle::checkingPoint(Point newp)
{
	double num = ( (p.getX()-newp.getX())*(p.getX()-newp.getX())  +  (p.getY()-newp.getY())*(p.getY()-newp.getY()) ); 
	if(num == radius*radius)
		return 0;
	if(num > radius*radius)
		return 1;
	return -1;
}
