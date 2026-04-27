/*
implementaion class string
C++ course
exercise 3.1
name:linoy boni
*/
#define _CRT_SECURE_NO_WARNINGS
#include"MyString.h"
//#include<cstring>
#include<string.h>
void my_strrev(char s[]);
void MyString::setString(const char * s)
{
	if (s)
	{
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
		
	}
	else 
		str = NULL;
}
MyString::MyString(char* s)
{
	setString(s);
}
MyString::MyString(const MyString & my_s)
{
	setString(my_s.getString());
}
char* MyString::getString() const
{
	return str;
}
//operators
bool MyString::operator<(const MyString& st1)const
{
	if(strcmp(str,st1.str)<0)
		return true;
	return false;
}
bool MyString::operator>(const MyString& st1)const
{
	if(strcmp(str,st1.str)>0)
		return true;
	return false;
}
bool MyString::operator<=(const MyString& st1)const
{
	if(strcmp(str,st1.str)<0 || strcmp(str,st1.str)==0)
		return true;
	return false;
}
bool MyString::operator>=(const MyString& st1)const
{
	if(strcmp(str,st1.str)>0 || strcmp(str,st1.str)==0)
		return true;
	return false;
}
bool MyString::operator!=(const MyString& st1) const
{
	if(strcmp(str,st1.str)!=0)
		return true;
	return false;
}
MyString& MyString::insert(int index,const char* st1)
{
	MyString M = NULL;
	char* s = new char[index+strlen(str)];
	char *send = new char[index+strlen(str)];
	if(index>strlen(str))
		{cout<<"ERROR";str = NULL;return M;}
	for(int i=0;i<index;i++)
	{
		*(s+i) = str[i];
	}
	strcat(s,st1);
	my_strrev(str);
	strncpy(send,str,strlen(str)-index);
	my_strrev(send);
	for(int i=0;i<strlen(s);i++)
	{
		str[i] = s[i];
	}
	strcat(str,send);
	return *this;
}
bool MyString::isEmpty()
{
	if(!str)
		return true;
	return false;
}
void my_strrev(char s[])
{
	char t;
	for (int i = 0, j = strlen(s) - 1; i<j; i++, j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}



