/*
implementaion class date
C++ course
exercise 2.2
name:linoy boni
*/
#include"Date.h"
//constructors
Date::Date()
{
	day = 1;
	month = 1;
	year = 1970;
}
Date::Date(int MYday,int MYmonth, int MYyear)
{
	if(MYday == NULL)
		day = 1;
	else
		day = MYday;
	if(MYmonth == NULL)
		month = 1;
	else
		month = MYmonth;
	if(MYyear == NULL)
		year = 1970;
	else
		year = MYyear;
	if(MYday<1 || MYday>30){
		cout<<"ERROR day"<<endl; day=1;}
	if(MYmonth<1 || MYmonth>12){
		cout<<"ERROR month"<<endl; month=1;}
	if(MYyear<1970 || MYyear>2099){
		cout<<"ERROR year"<<endl; year=1970;}
}
//copy ctor
Date::Date(const Date & d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}
//set method
void Date::setDate(int MYday,int MYmonth, int MYyear)
{
	if(MYday == NULL)
		day = 1;
	else
		day = MYday;
	if(MYmonth == NULL)
		month = 1;
	else
		month = MYmonth;
	if(MYyear == NULL)
		year = 1970;
	else
		year = MYyear;
	if(MYday<1 || MYday>30){
		cout<<"Error day"<<endl; day=1;}
	if(MYmonth<1 || MYmonth>12){
		cout<<"Error month"<<endl; month=1;}
	if(MYyear<1970 || MYyear>2099){
		cout<<"Error year"<<endl; year=1970;}
}
//operators
Date& Date::operator++()
{
	if(day+1==31){
		this->day=1;
		if(month==12){
			month=1;year++;}
		else
			this->month++;
	}
	else
		this->day++;
	return *this;
}
Date Date::operator++(int)
{
	Date temp = *this;
	if(day+1==31){
		this->day=1;
		if(month==12){
			month=1;year++;}
		else
			this->month++;
	}
	else
		this->day++;
	return temp;	
}
void Date::operator+=(const int& days)
{
	int index=1;
	while(index<=days)
	{
		if((day+index)<31){day++;}
		else{
			if(month==12)
				{year++;month=1;day=1;}
			else
			{month++;day=1;}
		}
		index=index+1;
	}
}
bool Date::operator<(const Date& d2) const
{
	return (year>d2.year)||(year==d2.year)&&(month>d2.month)||
			  (year==d2.year)&&(month==d2.month)&&(day>d2.day);
}
bool Date::operator>(const Date&d2)const
{
	return (year>d2.year)||(year==d2.year)&&(month>d2.month)||
			   (year==d2.year)&&(month==d2.month)&&(day>d2.day);
}

bool Date::operator==(const Date& d) const
{
	return (day==d.day)&&(month==d.month)&&(year==d.year);
}
void Date::print()
{
	cout<<day<<"/"<<month<<"/"<<year<<endl;
}
int Date::getDay(){return day;}
int Date::getMonth(){return month;}
int Date::getYear(){return year;}





