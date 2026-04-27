#include"triangle.h"
#include "rectangle.h"
#include<iostream>
using namespace std;

void Getp(int a, Polygon* &p)
{
	int b, c, d;
	if ((a != 3) && (a != 4))
	{
		p = new Polygon(a);
	}
	else
	{
		cout << "enter sides for polygon:" << endl;
		if(a==3)
		{
			cin >> b >> c >> d;
			p = new Triangle(b, c, d);
		}
		else
		{
			cin >> b >> c;
			p = new Rectangle(b, c);
		}
	}
}
int main()
{
	Polygon* p1,*p2;
	int num1, num2;
	cout << "enter number of sides for polygon 1:" << endl;
	cin >> num1;
	Getp(num1, p1);
	cout << "enter number of sides for polygon 2:" << endl;
	cin >> num2;
	if (num1 != num2)
		cout << "not equal" << endl;
	else
	{
		Getp(num2, p2);
		if(*p1==*p2)
			cout << "equal" << endl;
		else
			cout << "not equal" << endl;
	}
	return 0;
}