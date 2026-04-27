/*
C++ course
exercise 3.3
name:linoy boni
id:211820824
the program is getting a number and points 
and calculating scope of the polygon
*/
#include"point.h"
#include"polygon.h"
int main()
{
	int num;double x,y;
	cout<<"Enter number and points"<<endl;
	cin>>num;if(num<0){cout<<"ERROR"<<endl;return 0;}
	polygon p1(num);
	for(int i=0; i<num; i++)
	{
		cin>>x;
		p1.getA()[i].setX(x);
		cin>>y;
		p1.getA()[i].setY(y);
	}
	cout<<p1.scopePolygon(p1);
	return 0;
}
/*
Enter number and points
3 0 1 3 5 7 4
16.7389
*/