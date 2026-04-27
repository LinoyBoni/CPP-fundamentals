/*
class list
C++ course
exercise 6.1
name:linoy boni
*/
#pragma once
#include <iostream>
using namespace std;
class List
{
protected:
	class Link
	{
	public:
		int value;
		Link * next;
		//constructors
		Link(int val, Link * next = NULL) :value(val), next(next) {};
		Link(const Link & l) :value(l.value), next(l.next) {};
	};

	Link * ptr; 
	Link * head; 
public:
	//constructors
	List();
	List(const List &);
	~List();
	bool isEmpty();
	void clear();
	void add(int);
	void addLast(int);
	void removeFirst();
	void insert(int);
	//operations
	List operator=(const List &);
	friend ostream & operator<<(ostream &, List &);
	friend istream & operator >> (istream &, List &);
};