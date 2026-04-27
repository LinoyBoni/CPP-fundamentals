
#include<iostream>
#include"Rational.h"
;using namespace std;
//id:211820824
//name:linoy boni
//the program is getting a two objects and checking if they equal or not
int main()
{
	int mone1,mone2,mechane1,mechane2;
	char c;
	cout<<"enter two rational numbers"<<endl;
	cin>>mone1>>c>>mechane1>>mone2>>c>>mechane2;
	Rational r1(mone1,mechane1), r2(mone2,mechane2);
	if(r1.equal(r1,r2))
	{
		cout<<"equal"<<endl;
	}
	else
	{
		if(mechane2 == 0){mechane2 ++;}
		if(mechane1 == 0){mechane1 ++;}
		cout<<"different "<<mone1<<"/"<<mechane1<<" "<<mone2<<"/"<<mechane2;
	}
	return 0;
}
/*
enter two rational numbers
1/2 3/4
different 1/2 3/4
*/