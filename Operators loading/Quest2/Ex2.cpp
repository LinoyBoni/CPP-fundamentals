/*
C++ course
exercise 2.2
name:linoy boni
id:211820824
the program is getting a date and excuting the following functions printing,updating
and clculating operators actings
*/
#include"Date.h"
istream& operator>>(istream& s, Date& d)
{
	Date tmp;char c;//expressing the '/'
	s>>tmp.day;
	s>>c;
	s>>tmp.month;
	s>>c;
	s>>tmp.year;
	d.setDate(tmp.day,tmp.month,tmp.year);
	return s;
}
int main()
{
	Date d,d1;int num=0,days=0;
	cout<<"Enter a date"<<endl;
	cin>>d;
	d.print();
	cout<<"What do you want to do"<<endl;
	cin>>num;
	while(num!=-1)
	{
		if(num==1)
		{
			cout<<"Enter a date"<<endl;
			cin>>d1;
			d.setDate(d1.getDay(),d1.getMonth(),d1.getYear());
			d.print();
		}
		if(num==2)
		{
			(++d).print();
		}
		if(num==3)
		{
			(d++).print();
		}
		if(num==4)
		{
			cout<<"Enter #days"<<endl;
			cin>>days;
			d+=days;
			d.print();
		}
		if(num==5)
		{
			cout<<"Enter a date"<<endl;
			cin>>d1;
			bool f=d>d1;
			if(f==0)
				cout<<">:"<<"false";
			else
				cout<<">:"<<"true";
			cout<<endl;
		}
		if(num==6)
		{
			cout<<"Enter a date"<<endl;
			cin>>d1;
			bool f=d<d1;
			if(f==0)
				cout<<"<:"<<"false";
			else
				cout<<"<:"<<"true";
			cout<<endl;
		}
		if(num==7)
		{
			cout<<"Enter a date"<<endl;
			cin>>d1;
			bool f=d==d1;
			if(f==0)
				cout<<"==:"<<"false";
			else
				cout<<"==:"<<"true";
			cout<<endl;
		}
		cout<<"What do you want to do"<<endl;
		cin>>num;
	}
	return 0;
}
/*
Enter a date
30/3/2000
30/3/2000
What do you want to do
4
Enter #days
7
7/4/2000
What do you want to do
5
Enter a date
1/4/2000
>:true
What do you want to do
*/