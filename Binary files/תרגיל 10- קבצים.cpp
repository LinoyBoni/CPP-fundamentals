//linoy boni
//211820824
#include <iostream>
#include <fstream>
using namespace std;
struct student
{
	int id;
	char firstName[20];
	char lastName[20];
	bool Courses[5];
	student()
	{
		id=0;
		for (int i = 0; i < 5; i++)
			Courses[i]=0;
	}
};
void UpdateCourses(fstream &f,int _id);
void deleteRecord(fstream &deleteFromFl);
void create();
void newStudent(fstream& f);
bool searchRecord(int _id, fstream& f);
void StudentsInTheCourse(fstream &f,int numCourse);
void printStudent(fstream &f,int _id);
bool listingInvestigation(fstream &f,int _id,int numCourse);
int main()
{
	int choice,id,co;
	fstream fout("students.dat", ios::binary|ios::in | ios::out);
	create();
	cout << "enter your choise:";
		cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:
			newStudent(fout);
			break;
		case 2:
			deleteRecord(fout);
			break;
		case 3:
			cout<<"enter id:"<<endl;
			cin>>id;
			UpdateCourses(fout,id);
			break;
		case 4:
			cout<<"enter id and number course: "<<endl;
			cin>>id>>co;
			if(listingInvestigation(fout,id,co))
				cout<<"true"<<endl;
			else
				cout<<"false"<<endl;
			break;
		case 5:
			cout<<"enter id:"<<endl;
			cin>>id;
			printStudent(fout,id);
			break;
		case 6:
			cout<<"enter number course:"<<endl;
			cin>>co;
			StudentsInTheCourse(fout,co);
			break;
		case 0:break;
		default:
			cout<<"ERROR"<<endl;
			break;
		}
		cout << "enter your choise:";
		cin >> choice;
	}
	fout.close();
	return 0;
}

bool searchRecord(int _id, fstream& f)
{
	f.seekg((_id - 1)*sizeof(student), ios::beg);
	student s;
	f.read((char*)&s, sizeof(student));
	if (s.id == 0)
		return true;
	return false;
}
void newStudent(fstream& f)
{
	student s;
	cout<<"Enter data for student: (id,first name,lest name,courses)"<<endl;
	cin>>s.id>>s.firstName>>s.lastName;
	for (int i = 0; i < 5; i++)
		cin>>s.Courses[i];
	if (searchRecord(s.id,f))
	{
		f.seekp((s.id-1)*sizeof(student));
	    f.write((char*)&s,sizeof(student));
	}
	else
	 cout << "student" << s.id<< " is exists\n";
}
void deleteRecord(fstream &deleteFromFl)
{
	cout<<"Enter id to delete"<<endl;
	int tmpId;
	cin>>tmpId;
	if (!searchRecord(tmpId,deleteFromFl))
	{
		student blankStudent;
        deleteFromFl.seekp((tmpId-1)*sizeof(student));
		deleteFromFl.write((char*)&blankStudent,sizeof(student));
		cout<<"student "<< tmpId <<" deleted.\n";
   }
  else cout<<"student "<<tmpId<<" is empty.\n";
} 
void UpdateCourses(fstream &f,int _id)
{
	f.seekg((_id-1)*sizeof(student));
    student stu;
    f.read((char*)&stu,sizeof(student));
    if (!searchRecord(_id,f))
	{
		cout<<"enter true or false for courses:"<<endl;
		for (int i = 0; i < 5; i++)
			cin>>stu.Courses[i];
		f.write((char*)&stu,sizeof(student));
   }
  else cout<<"student "<<_id<<" is empty.\n";
}
bool listingInvestigation(fstream &f,int _id,int numCourse)
{
	if (!searchRecord(_id,f))
	{
		cout<<"Student not found"<<endl;
		return 0;
	}
	f.seekg((_id-1)*sizeof(student));
    student stu;
    f.read((char*)&stu,sizeof(student));
    if (stu.id != 0 )
	{
		if (stu.Courses[numCourse])
			return true;
		return false;
   }
  else return false;
}
void printStudent(fstream &f,int _id)
{
	f.seekg((_id - 1)*sizeof(student), ios::beg);
	student stu;
	f.read((char *) &stu, sizeof(student));
	if (!searchRecord(_id,f))
	{
		cout<<stu.firstName<<" "<<stu.lastName<<" "<<endl;
		for (int i = 0; i < 5; i++)
		{
			if (stu.Courses[i])
				cout<<"Y"<<" "<<endl;
			else
				cout<<"N"<<" "<<endl;
		}
	}
	else
	 cout<<"student not found"<<endl;
}
void StudentsInTheCourse(fstream &f,int numCourse)
{
	for (int i = 1; i < 100; i++)
	{
		f.seekg((i - 1)*sizeof(student), ios::beg);
		student stu;
	    f.read((char *) &stu, sizeof(student));
	    if (stu.id)
			if (stu.Courses[numCourse])
				cout<<stu.firstName<<" "<<stu.lastName<<endl;
	}
}
void create()
{	
	ofstream stu( "students.dat", ios::binary);
	if(!stu)
		cout<<"not open"<<endl;
	student s; 
	for(int i=0;i<100;i++)
		stu.write((char*)&s,sizeof(student));
}
