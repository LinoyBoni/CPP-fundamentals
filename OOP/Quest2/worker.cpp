/*
implementaion class worker
C++ course
exercise 1.2
name:linoy boni
*/
#include"Worker.h"
//constructors
Worker::Worker()
{
	id=0;
	strcpy(name,"");
	priceHour = 0;
	numHours = 0;
	bonusHours = 0;
}
Worker::Worker(int myid, char* myname, float mypriceHour,int mynumHours,int mybonusHours)
{
	id=myid;
	strcpy(name,myname);
	priceHour = mypriceHour;
	numHours = mynumHours;
	bonusHours = mybonusHours;
}
//set methods
void Worker::setId(int myid)
{
	id=myid;
}
void Worker::setName(char* myname)
{
	strcpy(name,myname);
}
void Worker::setPriceHours(float myprice)
{
	priceHour = myprice;
}
void Worker::setnumHours(int num)
{
	numHours = num;
}
void Worker::setbonusHours(int bonus)
{
	bonusHours = bonus;
}
//get methods
int Worker::getId()
{
	return id;
}
char* Worker::getName()//ìáãå÷!!!!!!!!!!!!
{
	return name;
}
float Worker::getPriceHours()
{
	return priceHour;
}
int Worker::getNumHours()
{
	return numHours;
}
int Worker::getbonusHours()
{
	return bonusHours;
}
//the function is getting 3 parameters and calculate full salary for worker
double Worker::salary(int numHours,float priceHour,int bonusHours)
{
	return (numHours*priceHour + bonusHours*1.5*priceHour);
}
