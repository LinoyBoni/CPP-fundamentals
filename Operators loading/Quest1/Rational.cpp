
/*
implementaion class Rational
C++ course
exercise 2.1
name:linoy boni
*/
#define _CRT_SECURE_NO_WARNINGS
#include"Rational.h"
//constructors

Rational::Rational()
{
	mone = 0;
	mechane = 1;
}
Rational::Rational(int myMone,int myMechane)
{
	mone = myMone;
	if(myMechane==0)
	{myMechane = 1;cout<<"Error";}
	else
		mechane = myMechane;
}
void Rational::setMechane(int num)
 {
	 if(num == 0)
		{mechane = 1;cout<<"Error";}
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
	if(mone==0 ||mechane == 1 )
		cout<<mone;
	else 
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
	if(mone<=mechane)
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

//operators
 bool Rational::operator>=(const Rational& r1)const
 {
	Rational tmp1,tmp2;
	tmp1.mone = mone*r1.mechane;
	tmp1.mechane = mechane*r1.mechane;
	tmp2.mone = r1.mone*mechane;
	tmp2.mechane = r1.mechane*mechane;
	return(tmp1.mone>=tmp2.mone);
 }
 bool Rational::operator<=(const Rational& r1)const
 {
    Rational tmp1,tmp2;
	tmp1.mone = mone*r1.mechane;
	tmp1.mechane = mechane*r1.mechane;
	tmp2.mone = r1.mone*mechane;
	tmp2.mechane = r1.mechane*mechane;
	return(tmp1.mone<=tmp2.mone);
 }
 bool Rational::operator>(const Rational& r1)const
 {
	Rational tmp1,tmp2;
	tmp1.mone = mone*r1.mechane;
	tmp1.mechane = mechane*r1.mechane;
	tmp2.mone = r1.mone*mechane;
	tmp2.mechane = r1.mechane*mechane;
	return(tmp1.mone>tmp2.mone);
 }
 bool Rational::operator<(const Rational& r1)const
 {
	 Rational tmp1,tmp2;
	tmp1.mone = mone*r1.mechane;
	tmp1.mechane = mechane*r1.mechane;
	tmp2.mone = r1.mone*mechane;
	tmp2.mechane = r1.mechane*mechane;
	return(tmp1.mone<tmp2.mone);
 }
 bool Rational::operator!=(const Rational&r1) const
 {
	 Rational temp(*this);//copy ctor
	 Rational temp1(r1);
	 temp.reduce(temp.mone,temp.mechane);//checking if the rational are equal although irreduce rationals
	 temp1.reduce(temp1.mone,temp1.mechane);
	 return (temp.mone!=temp1.mone)&&(temp.mechane!=temp1.mechane) ||
		 (temp.mone!=temp1.mone)&&(temp.mechane==temp1.mechane)||(temp.mone==temp1.mone)&&(temp.mechane !=temp1.mechane);
 }
  Rational Rational::operator--()
  {
	  this->mone--;
	  this->mechane--;
	  return  *this;
  }
  Rational Rational::operator--(int)
  {
		Rational temp = *this;
		this->mone--;
		this->mechane--;
		return temp;	
  }
  Rational Rational::operator-(Rational r1)
  {
	  Rational r2;
	  if(mechane == r1.mechane)
	  {
		  r2.mechane = mechane;
		  r2.mone = mone-r1.mone;
	  }
	  else{
		  Rational tmp1,tmp2;
		  tmp1.mone = mone*r1.mechane;
		  tmp1.mechane = mechane*r1.mechane;
		  tmp2.mone = r1.mone*mechane;
		  tmp2.mechane = r1.mechane*mechane;
		  r2.mone = tmp1.mone - tmp2.mone;
		  r2.mechane = tmp1.mechane;
		  r2.reduce(r2.mone,r2.mechane);
	  }
	  return r2;
  }

   Rational Rational::operator++(int)
{
	Rational temp = *this;
	this->mone++;
    this->mechane++;
	return temp;	
}
  Rational Rational::operator/( Rational r1)
  {
	  Rational temp;
	  temp.mone = mone*r1.mechane;
	  temp.mechane = mechane*r1.mone;

	  return temp.reduce(temp.mone,temp.mechane);
  }




