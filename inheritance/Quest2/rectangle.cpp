/*
implementaion class rectangle
C++ course
exercise 6.2
name:linoy boni
*/
#include "rectangle.h"

Rectangle::Rectangle(int a, int b):Polygon(4)
{
	sides[0] = a;
	sides[1] = a;
	sides[2] = b;
	sides[3] = b;
}

Rectangle::~Rectangle()
{
}
