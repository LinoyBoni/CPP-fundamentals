/*
implementaion class polygon
C++ course
exercise 3.3
name:linoy boni
*/
#include"polygon.h"
#include"point.h"

polygon::polygon(int num)
{
	N = num;
	a = new point[num];
}
polygon::polygon(polygon & p)
{
	for(int i=0; i<p.N; i++)
	{
		*(a+i) = p.a[i];
	}
	N = p.N;
}
polygon::~polygon()
{
	if (a)
		delete[] a;
	a = NULL;
}
double polygon::scopePolygon(polygon & p1)
{
	double sum=0;
	for(int i=1;i<p1.N; i++)
	{
		sum+=p1.a[i].distance(a[i-1],a[i]);
	}
	sum+=p1.a[0].distance(a[0],a[N-1]);
	return sum;
}
point* polygon::getA()
{
	return a;
}
