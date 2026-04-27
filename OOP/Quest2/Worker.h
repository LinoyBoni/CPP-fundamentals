/*
class worker
C++ course
exercise 1.2
name:linoy boni
*/
#include<iostream>
#include<cstring>
using namespace std;
#ifndef WORKER_H
#define WORKER_H
class Worker
{
private:
	int id;
	char name[20];
	float priceHour;
	int numHours;
	int bonusHours;
public:
	//constructors
	Worker();
	Worker(int, char*,float,int,int);
	//set methods
	void setId(int id);
	void setName(char* name);
	void setPriceHours(float price);
	void setnumHours(int num);
	void setbonusHours(int bonus);
	//get methods
	int getId();
	char* getName();
	float getPriceHours();
	int getNumHours();
	int getbonusHours();
	//help function to calculate salary for worker
	double salary(int numHours,float priceHour,int bonusHours);
};
#endif
