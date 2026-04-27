/*
the program is getting 3 circles with radius and center point and excuting the following actings:
#calculating the area N scrope
#counting how many points are found in the currents circles
NAME:LINOY BONI
ID:211820824
*/
#include"point.h"
#include"circle.h"
int main()
{
	Point a,b,c;
	float x,y,radius;
	int countA=0,countB=0,countC=0;
	cout<<"enter the center point and radius of 3 circles"<<endl;
	//filling fields
	cin>>x>>y>>radius;
	a.setX(x);a.setY(y);
	Circle A(a,radius);

	cin>>x>>y>>radius;
	b.setX(x);b.setY(y);
	Circle B(b,radius);

	cin>>x>>y>>radius;
	c.setX(x);c.setY(y);
	Circle C(c,radius);

	cout<<"area	A: "<<A.areaCircle(A.getRadius())<<"   B: "<<B.areaCircle(B.getRadius())<<"  C: "<<C.areaCircle(C.getRadius())<<endl;
	cout<<"hekef  A: "<<A.scopeCircle(A.getRadius())<<"   B: "<<B.scopeCircle(B.getRadius())<<"  C: "<<C.scopeCircle(C.getRadius())<<endl;
	
	cin>>x>>y;
	while(x!=0 || y!=0)
	{//checking how many points are found in every circles
		cout<<endl;
		Point p(x,y);
		if(A.checkingPoint(p)==0 || A.checkingPoint(p)==-1)
			countA++;
		if(B.checkingPoint(p)==0 || B.checkingPoint(p)==-1)
			countB++;
		if(C.checkingPoint(p)==0 || C.checkingPoint(p)==-1)
			countC++;
		cin>>x>>y;
	}
	cout<<"num of points in circle   A:"<<countA<<"  B:"<<countB<<"  C:"<<countC;
	return 0;
}
/*
enter the center point and radius of 3 circles
5 8 7
3 5 9
6 10 4
area    A: 153.86   B: 254.34  C: 50.24
hekef  A: 43.96   B: 56.52  C: 25.12
0 1

0 0
num of points in circle   A:0  B:1  C:0
*/
	