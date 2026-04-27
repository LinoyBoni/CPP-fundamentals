/*
class roundlist
C++ course
exercise 6.1
name:linoy boni
*/
#pragma once
#include "list.h"

class RoundList :public List 
{
public:
	RoundList() :List() {};
	~RoundList();

	void addToEnd(int);
	int search(int);
	//override
	void clear();
	void add(int);
	void removeFirst();
};