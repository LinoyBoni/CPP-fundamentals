

#ifndef RATIONAL_H
#define RATIONAL_H
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
}
#endif