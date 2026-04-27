/*
C++ course
exercise 3.1
name:linoy boni
id:211820824
the program is developing the class string
and excuting > < != <= >= on the characters
*/
#include"MyString.h"
#include<string.h>
#include<iostream>
int main()
{
	char c[80];
	int n;
	cin>>c;
	cout<<endl;
	MyString a(c);
	cin>>c;
	MyString b(c);
	cout<<endl;
	cin>>n;
	if(a>b)
		cout<<"a>b"<<endl;
	if(a<b)
		cout<<"a<b"<<endl;
	if(!(a!=b))
		cout<<"a=b"<<endl;
	MyString temp(b);
	b.insert(n,a.getString());
	if(!b.isEmpty())
	 {
		for(int j=0; j<strlen(b.getString()); j++)
		{
			if(b.getString()[j]>0)
				cout<<b.getString()[j];
		}
	 }
	else
	//	b.insert(0,temp.getString());
	return 0;
}