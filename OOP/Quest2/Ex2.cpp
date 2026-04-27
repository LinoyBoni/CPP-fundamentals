/*
C++ course
exercise 1.2
name:linoy boni
id:211820824
the program is getting workers' datas and excuting the following things:
printing the max worker's salary ,max worker's hours + his datas
*/
#include"Worker.h"
Worker MaxSalary(Worker w1, Worker w2);
Worker MaxHours(Worker w1, Worker w2);

int main()
{
	int id,numhours,bonus;
	char name[20];bool flag= true;
	float pricehour;
	Worker w2,MAXSALARYworker, MAXHOURSworker,w3;
	cout<<"enter details, to end enter 0"<<endl;
	cin>>id;
	if(id<0)
		{cout<<"ERROR"<<endl;flag=false;}
	else
		if(id!=0)
		{
			cin>>name;
			if(strlen(name)>21&&flag)
			{cout<<"ERROR"<<endl;flag=false;}
			cin>>pricehour;
			if(pricehour<0&&flag)
				{cout<<"ERROR"<<endl;flag=false;}
			cin>>numhours;
			if(numhours<0&&flag)
				{cout<<"ERROR"<<endl;flag=false;}
			cin>>bonus;
			if(bonus<0&&flag)
				{cout<<"ERROR"<<endl;flag=false;}
		}
		if(flag)
		{//enters values
			w2.setId(id);
			w2.setName(name);
			w2.setnumHours(numhours);
			w2.setPriceHours(pricehour);
			w2.setbonusHours(bonus);
		    w3=w2;//השמה
		    MAXHOURSworker = w2;
			MAXSALARYworker = w2;
		}
		flag = true;
		cin>>id;
		while(id!=0)
		{
			cin>>name;
			if(strlen(name)>21&&flag)
				{cout<<"ERROR"<<endl;flag=false;}
			cin>>pricehour;
			if(pricehour<0&&flag)
				{cout<<"ERROR"<<endl;flag=false;}
			cin>>numhours;
			if(numhours<0&&flag)
				{cout<<"ERROR"<<endl;flag=false;}
			cin>>bonus;
			if(bonus<0&&flag)
				{cout<<"ERROR"<<endl;flag=false;}
			if(flag)
			{
				Worker w1(id,name,pricehour,numhours,bonus);
				MAXSALARYworker = MaxSalary(w1,w2);
				w2 = MAXSALARYworker;
				MAXHOURSworker = MaxHours(w1,w3);
				w3 = MAXHOURSworker;
			}
		cin>>id;
		flag = true;
		if(id<0&&flag)
			{cout<<"ERROR"<<endl;flag=false;}
		}
		cout<<"highest salary: "<<MAXSALARYworker.getId()<<" "<<MAXSALARYworker.getName();
		cout<<endl;
		cout<<"hardest worker: "<<MAXHOURSworker.getId()<<" "<<MAXHOURSworker.getName();
		return 0;
}
//function which return the worker with the maximum salary
Worker MaxSalary(Worker w1, Worker w2)
{
	double salary1,salary2;
	salary1 = w1.salary(w1.getNumHours(),w1.getPriceHours(),w1.getbonusHours());
	salary2 = w2.salary(w2.getNumHours(),w2.getPriceHours(),w2.getbonusHours());
	if(salary1>salary2)
		return w1;
	return w2;
}
//function which return the worker with the maximum hours
Worker MaxHours(Worker w1, Worker w2)
{
	double hour1,hour2;
	hour1 = w1.getbonusHours() + w1.getNumHours();
	hour2 = w2.getbonusHours() + w2.getNumHours();
	if(hour1>hour2)
		return w1;
	return w2;
}
/*
enter details, to end enter 0
211820824
linoy
150
38
12
211820816
lital
200
45
5
0
highest salary: 211820816 lital
hardest worker: 211820824 linoy
*/