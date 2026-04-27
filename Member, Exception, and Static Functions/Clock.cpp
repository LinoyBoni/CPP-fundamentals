/*
implementaion class clock
C++ course
exercise 4.1
name:linoy boni
*/
#include"Clock.h"
#include<string>
Clock::Clock()
{
	second = 0;
	minute = 0;
	hour = 0;
}
Clock::Clock(int MYsecond, int MYminute, int MYhour)
{
	try
	{
		if(MYsecond>60)
			throw "Invalid time - more than 60 seconds.";
		if(MYminute>60)
			throw "Invalid time - more than 60 minutes.";
		if(MYhour>24)
			throw "Invalid time - more than 24 hours.";
		if(MYsecond<0)
			throw "Invalid time - negative number of seconds.";
		if(MYminute<0)
			throw "Invalid time - negative number of minutes.";
		if(MYhour<0)
			throw "Invalid time - negative number of hours.";
		second = MYsecond;
		minute = MYminute;
		hour = MYhour;
	}
	catch(char* str)
	{
		cout<<str;
		second = 0;
		minute = 0;
		hour = 0;
	}
}
Clock::Clock(const Clock& c)
{
	second = c.second;
	minute = c.minute;
	hour = c.hour;
}
//set N get
int Clock::getHour()
{
	return hour;
}
int Clock::getminute()
{
	return minute;
}
int Clock::getSecond()
{
	return second;
}
void Clock::setSecond(int newsecond)
{
	second = newsecond;
}
void Clock::setMinute(int newminute)
{
	minute = newminute;
}
void Clock::setHour(int newhour)
{
	hour = newhour;
}
Clock& Clock::operator+=(int Seconds)
{
	int index = 1;
	while(index<=Seconds)
	{
		if(1+second==60)
		{
			second = 0;
			if(minute+1 == 60)
			{minute = 0;hour++;}
			else
				minute++;
		}
		else
			second++;
		index++;
	}
	if(second%60 == 0)
	{minute += second/60;second = 0;}
	return *this;
}

