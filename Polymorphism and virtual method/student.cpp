
#include"student.h"

 Student::Student(string newid, string newname, string newfamily,int newnumOfCourses)
 {
	 id=newid;
	 name=newname;
	 family=newfamily;
	 numOfCourses = newnumOfCourses;
 }
 Student::~Student()
  {
	  id = "";
	  name = "";
	  family = "";
	  numOfCourses = 0;
 }
 void Student::print()
 {
	 cout<<"ID: "<<id<<endl;
	 cout<<"first name: "<<name<<endl;
	 cout<<"last name: "<<family<<endl;
	 cout<<"num courses: "<<numOfCourses<<endl;
 }