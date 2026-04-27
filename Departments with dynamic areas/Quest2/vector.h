
#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;
class Vector
{
private:
	int* data;//pointer to array
	int capacity;//the maximum amount 
	int size; //current size in array
public:
	//constructors
	Vector();//default ctor
	Vector(int capacity);//ctor
	Vector(const Vector& v); //copy ctor
	//~Vector();//dtor

	//get N set
	int getCapacity();
	int getSize();
	void print();

	//operators
	//void operator=(const Vector & v);
	bool operator==(const Vector&);
	int& operator[](int index);
	int operator*(Vector); 
	Vector operator+(const Vector&) ;
	
	//help fuctions
	void clear();
	void delLast();
	void insert(int val);

};
#endif