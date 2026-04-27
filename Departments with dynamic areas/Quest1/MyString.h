
/*
class string
C++ course
exercise 3.1
name:linoy boni
*/
#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>
#include<string>
using namespace std;
class MyString
{
private:
	char* str;
	void setString(const char* s);
public:
	//constructor
	MyString(char* s = NULL); //empty ctor or not empty ctor
	MyString(const MyString & s);//copy ctor
	char* getString() const; // view function.
	//operators
	bool operator<(const MyString& )const;
	bool operator>(const MyString& )const;
	bool operator<=(const MyString& )const;
	bool operator>=(const MyString& )const;
	bool operator!=(const MyString&) const;
	//void my_strrev(char s[]);
	

	bool isEmpty();
	MyString& insert(int index,const char* str); 
};
#endif