
#include<iostream>
#include"Rational.h"
;using namespace std;
/*
C++ course
exercise 2.1
name:linoy boni
id:211820824
the program is getting two rational numbers and 
calculating + > < >= ++ - != by operators
*/
istream& operator>>(istream& s, Rational& r)
{
	Rational tmp;char c;//expressing the '/'
	s>>tmp.mone;
	s>>c;
	s>>tmp.mechane;
	r.setMone(tmp.mone);
	r.setMechane(tmp.mechane);
	return s;
}

int main()
{
	Rational a,b;
	cout<<"Enter two rational numbers"<<endl;
	cout<<"a:";
	cin>>a;
	cout<<endl;
	cout<<"b:";
	cin>>b;
	cout<<endl;
	cout<<"b-a: "; 
	(b-a).print();
	cout<<"a!=b: ";
	if((a!=b) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;
	cout<<"a<b: ";
	if((a<b) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;
	cout<<"a>b: ";
	if((a>b) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;
	cout<<"a>=b: ";
	if((a>=b) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;

	cout<<"a++: ";(a++).print();
	cout<<"--a: ";(--a).print();
	cout<<"a--: ";a--.print();
	//update b=a
	b.setMone(a.getMone());
	b.setMechane(a.getMechane());
	cout<<"b-a: "; (b-a).print();
	cout<<endl;
	cout<<"b/a: "; (b/a).print();
	cout<<endl;
	cout<<"a!=b: ";
	if((a!=b) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;

	cout<<"a<b: ";
	if((a<b) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;

	cout<<"a>=b: ";
	if((a>=b) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;
	return 0;
}
/*
Enter two rational numbers
a:5/6

b:6/7

b-a: 1/42
a!=b: true
a<b: true
a>b: false
a>=b: false
a++: 5/6
--a: 5/6
a--: 5/6
b-a: 0
b/a: 1
a!=b: false
a<b: false
a>=b: true
*/