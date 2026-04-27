/*
C++ course
exercise 5.2
name:linoy boni
id:211820824
the program is using a sorted nodes list and using remove and insert functions
*/
#include <iostream>
#include "list.h"
using namespace std;
List merge(const List &lst1, const List &lst2);
void makeSet(List &lst);
int main()
{
	List lst1, lst2, mergedList;
	cout<<"enter sorted values for the first list:"<< endl;
	cin>>lst1;
	cout<<"enter sorted values for the second list:"<< endl;
	cin>>lst2;
	mergedList = merge(lst1,lst2);
	cout <<"the new merged list: " << mergedList <<endl;
	makeSet(mergedList);
	cout<<"the new merged set: " << mergedList << endl;
	return 0;
}
List merge(const List &lst1, const List &lst2)
{
	List mergeList = lst1;
	List tmp = lst2;
	int val;
	while (!tmp.isEmpty())
	{
		val = tmp.firstElement();
		tmp.removeFirst();
		mergeList.insert(val);
	}
	return mergeList;
}

void makeSet(List &lst)
{
	List temp = lst;
	if (!temp.isEmpty())
	{
		int val, next;
		val = temp.firstElement();
		temp.removeFirst();
		while (!temp.isEmpty())
		{
			next = temp.firstElement();
			temp.removeFirst();
			if (val == next)
				lst.remove(val);
			val = next;
		}
	}
}
