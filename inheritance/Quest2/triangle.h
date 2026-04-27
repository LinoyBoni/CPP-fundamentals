/*
class triangle
C++ course
exercise 6.2
name:linoy boni
*/
#pragma once
#include"polygon.h"
class Triangle :public Polygon
{

public:

	Triangle(int a, int b, int c);
	virtual~Triangle();
};
