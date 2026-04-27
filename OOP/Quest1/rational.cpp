
#include<iostream>
#include"Rational.h"
;using namespace std;

Rational::Rational()
{
	mone = 0;
	mechane = 1;
}
Rational::Rational(int myMone,int myMechane)
{
	mone = myMone;
	mechane = myMechane;
}
void Rational::setMechane(int num)
 {
	 if(num == 0)
		 mechane = 1;
	 else
		 mechane = num;
}
void Rational::setMone(int num)
{
	mone = num;
}
int Rational::getMechane()
{
	return mechane;
}
int Rational::getMone()
{
	return mone;
}
void Rational::print()
{
   cout<<mone<<"/"<<mechane<<'\n';
} 

bool Rational::equal(Rational r1, Rational r2)
{
	r1 = reduce(r1.mone,r1.mechane);
	r2 = reduce(r2.mone,r2.mechane);
	if((r1.mechane == r2.mechane)&&(r1.mone == r2.mone)||(r1.mechane==r1.mone)&&(r2.mechane==r2.mone))
		return true;
	return false;
}
Rational Rational::reduce(int mone, int mechane)
{
	int index;bool flag=true;
	if(mone<mechane)
		index = mone;
	else
		if(mechane<mone)
			index = mechane;
    for(int i=index; i>0 && flag; i--)
	{
		if((mone%i==0) && (mechane%i==0))
		{
			flag = false;
			mone = mone/i;
			mechane = mechane/i;
		}
	}
	Rational r(mone,mechane);
	return r;
}