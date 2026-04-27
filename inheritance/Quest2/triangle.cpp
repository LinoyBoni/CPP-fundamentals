/*
implementaion class triangle
C++ course
exercise 6.2
name:linoy boni
*/
#include "triangle.h"

Triangle::Triangle(int a, int b, int c) :Polygon(3)
{
	sides[0] = a;
	sides[1] = b;
	sides[2] = c;
}
Triangle::~Triangle()
{
}