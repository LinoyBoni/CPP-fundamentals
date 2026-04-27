/*
class acount
C++ course
exercise 4.1
name:linoy boni
*/
#pragma once
#include<iostream>
using namespace std;
class Clock
{
private:
	int hour;
	int minute;
	int second;
public:
	Clock();//default ctor
	Clock(int second, int minute, int hour);//ctor
	Clock(const Clock& c); //copy ctor
	//set N set
	int getHour();
	int getminute();
	int getSecond();
	void setSecond(int newsecond);
	void setMinute(int newminute);
	void setHour(int newhour);
	Clock& operator+=(const int Seconds);
	friend ostream& operator<<(ostream& s, Clock c);
	friend istream& operator>>(istream& s, Clock &r);
};