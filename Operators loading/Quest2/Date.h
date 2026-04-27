/*
class date
C++ course
exercise 2.2
name:linoy boni
*/
#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
private:
   int day;
   int month;
   int year;
public:
//constructor
	Date();
	Date(int day, int month, int year);
    Date(const Date & d);//copy ctor
//functions
	void setDate(int day,int month,int year); 
	Date& operator++();//++àçøé ä÷éãåí
	Date operator++(int);//++ìôðé ä÷éãåí
	void operator+=(const int& days);
    bool operator<(const Date& ) const;
	bool operator>(const Date& )const;
	bool operator==(const Date& d) const;
	void print();
	//help func
	friend istream& operator>>(istream& s, Date& d);
	//get methods
	int getDay();
	int getMonth();
	int getYear();
};
#endif