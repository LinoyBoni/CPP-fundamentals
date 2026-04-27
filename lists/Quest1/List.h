
/*
class list
C++ course
exercise 5.1
name:linoy boni
*/
#pragma once
#include<iostream>
using namespace std;

class List
{
protected:
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link &);
		// data areas
		int value;
		Link* next;
	};
public:
	// constructors
	List();
	List(const List&);
	~List();

	void add(int value);
	int firstElement() const;
	bool search(const int &value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void insert(int key);
	void remove(int key);

	//------the new operators
	friend istream& operator>>(istream& s, List& l);
	friend ostream& operator<<(ostream& s, List& l);
	List& operator=(const List lst);
protected:
	Link* head;
};


