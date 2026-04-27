
#include "Student.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"
#include <iterator>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
//name:linoy boni
//id:211820824
using namespace std;
Student* mostResearchHours(vector<Student*> s);
void a
enum option {
	stop,	addNewStudent,	milgaList,	mostResearch,	countMilgaBA,	noResearchMA,	overheadStudent,	removePHDFailers,	
};

void milga(vector<Student*> s)
{
	vector<Student*> ::iterator it1 = (s).begin();
	vector<Student*> ::iterator it2 = (s).end();
	vector<Student*> ::iterator it3;
	it3 = it1;
	for (it3 = it1; it3 != it2; ++it3)
	{
		if ((*it3)->milga1() == true)
			(*it3)->print();
	}
}
int main()
{
	vector<Student*> s;
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewStudent:add(s);
		case milgaList:milga(s);
			break;
		case mostResearch: {
			Student* st = mostResearchHours(s);
			cout << "PHD studnet with most research hours: ";
			cout << st->getname() << ' ' << st->getFname() << endl;
		}
						   break;
		case countMilgaBA:  cout << "#BA studnets for milga: ";
			for_each((s).begin(), (s).end(), [](Student* st) {if ((st->milga1() && st->studType() == "BA")) st->print(); });
			cout << endl;
			break;
		case noResearchMA:cout << "list of no research MA students : ";
			for_each((s).begin(), (s).end(), [](Student* st) {if (!(st->getresearch())) st->print(); });
			cout << endl;
			break;
		case overheadStudent:
			if (any_of((s).begin(), (s).end(), [](Student* x)->bool {return (x)->getnumcouses() > 15; }))
				cout << "there is a student that takes more than 15 courses\n";
			else cout << "no student takes more than 15 courses\n";
			break;
		case removePHDFailers:
			remove_if((s).begin(), (s).end(), [](Student* st) {return(!(st->getnumcouses()) && (st->studType() == "PHD")); });
			for_each((s).begin(), (s).end(), [](Student* st) { st->print(); });
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}

Student* mostResearchHours(vector<Student*> s)
{
	std::vector<Student*> ::iterator it1 = (s).begin();
	vector<Student*> ::iterator it2 = (s).end();
	vector<Student*> ::iterator it3;
	it3 = it1;
	Student* st = (*it1);
	bool flag = false;
	for (it3 = it1; it3 != it2; ++it3)
	{
		if ((*it3)->studType() == "PHD")
		{
			flag = true;
			if ((*it3)->gethours() > (*st).gethours())
				*st = *(*it3);
		}
	}
	if (flag)
		return st;
	return NULL;
}
void add(vector<Student*>& arr)
{
	int num, ID, numOfCourses, hours;
	bool flag;
	string name, ln;
	Student* s;
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> num;
	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> ID >> name >> ln >> numOfCourses;
	int* grades = new int[numOfCourses];
	switch (num)
	{
	case 1:
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
		{
			cin >> grades[i];
		}
		s = new BA(ID, name, ln, numOfCourses, grades);
		(arr).push_back(s);
		break;
	case 2:
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
		{
			cin >> grades[i];
		}
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> flag;
		s = new MA(ID, name, ln, numOfCourses, grades, flag);
		(arr).push_back(s);
		break;
	case 3:	cout << "enter number of research hours\n";
		cin >> hours;
		s = new PHD(ID, name, ln, numOfCourses, hours);
		(arr).push_back(s);
		break;
	default:
		break;
	}
}
