
/*
class Rational
C++ course
exercise 2.1
name:linoy boni
*/
#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
using namespace std;
class Rational
{
private:
   int mechane;
   int mone;

   Rational reduce(int mone, int mechane);//öîöåí äùáø
public:
//constructor
   Rational();
   Rational (int myMone,int myMechane);
   void setMechane(int num);
   void setMone(int num);
   int getMechane();
   int getMone();
   void print();
   bool equal(Rational r1, Rational r2);
   //operators
   bool operator>=(const Rational& )const;
   bool operator<=(const Rational& )const;
   bool operator>(const Rational& )const;
   bool operator<(const Rational& )const;
   bool operator!=(const Rational&) const;
   Rational operator--();
   Rational operator--(int);
   Rational operator-(Rational);
   Rational operator/( Rational);
   Rational operator++(int);

   //help func
   friend istream& operator>>(istream& s, Rational& d);
};
#endif