

#include"vector.h"
#include<iostream>
using namespace std;

Vector::Vector()
{
	capacity = 10;
	size = 0;
	data = new int[capacity];
}
Vector::Vector(int c)
{
	capacity = c;
	size = 0;
	data = new int[capacity];
}
Vector::Vector(const Vector& v)
{
	data = v.data;
	capacity = v.capacity;
	size = v.size;
}
//Vector::~Vector()
//{
//	if (data)
//		delete[] data;
//	data = NULL;
//}
int Vector::getCapacity()
{
	return capacity;
}
int Vector::getSize()
{
	return size;
}
void Vector::print()
{
	cout<<"capacity: "<<capacity<<" size: "<<size<<" val: ";
	for(int i=0; i<size;i++)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
}
//void Vector::operator=(const Vector & v1)
//{
//	data = v1.data;
//	capacity = v1.capacity;
//	size = v1.size;
//}
bool Vector::operator==(const Vector& v)
{
	bool equal = false;
	if((size == v.size)&&(capacity == v.capacity))
	{
		equal = true;
		for(int i=0; i<size&&equal; i++)
		{
			if(data[i] != v.data[i])
				equal = false;
		}
	}
	return equal;
}
int& Vector::operator[](int index)
{
	if(index>size)
	{cout<<"ERROR"<<endl;return data[-1];}
	else
	{
		return data[index];
	}
}
int Vector::operator*(Vector v)
{
	int sum=0;
	if(size != v.size)
		cout<<"ERROR"<<endl;
	else
	{
		for(int i=0; i<size; i++)
		{
			sum += data[i]*v.data[i];
		}
	}
	return sum;
}

Vector Vector::operator+(const Vector& v) 
{
	Vector temp(capacity + v.capacity);
	for(int i=0; i<size; i++)
	{
		temp.data[i] = data[i];
		temp.size++;
	}
	for(int i=0; i<v.size; i++)
	{
		temp.data[i+size] = v.data[i];
		temp.size++;
	}
	return temp;
}

void Vector::clear()
{
	data = NULL;
	size =0;
}
void Vector::delLast()
{
	if(!data)
		cout<<"ERROR"<<endl;
	else
	{data[size-1] = 0;size--;}
}
void Vector::insert(int val)
{
	if(size == capacity)
		cout<<"ERROR"<<endl;
	else
	{
		data[size] = val;
		size++;
	}
}
