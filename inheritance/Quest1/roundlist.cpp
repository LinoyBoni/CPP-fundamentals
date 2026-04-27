/*
implementaion class roundlist
C++ course
exercise 6.1
name:linoy boni
*/

#include "roundlist.h"
RoundList::~RoundList()
{
	clear();
}
void RoundList::addToEnd(int val)
{
	if (head == NULL)
	{
		head = new Link(val);
		Link *p = head;
		head->next = p;
	}
	else
	{
		Link *p = head;
		while (p->next != head) 
			p = p->next;
		p->next = new Link(val, head); 
	}
}
int RoundList::search(int n)
{
	if (isEmpty())
		return -1;
	Link * p = head;
	for (int i = 0; i < n; i++)
		p = p->next;
	return p->value;
}
//override
void RoundList::clear()
{
	if (head != NULL)
	{
		Link * p, *next;
		for (p = head; p->next != head; p = next)
		{
			next = p->next;
			p->next = NULL;
			delete p;
		}
		p->next = NULL;
		delete p;
		head = NULL;
	}
}
void RoundList::add(int val)
{
	if (head == NULL)
	{
		head = new Link(val);
		Link *p = head;
		head->next = p;
	}
	else
	{
		Link *p = head;
		while (p->next != head)
			p = p->next;
		p->next = new Link(val, head);
		head = p->next;
	}
}

void RoundList::removeFirst()
{
	if (isEmpty())
		throw("list is empty /n");
	Link *p = head;
	while (p->next != head)
		p = p->next;
	p->next = head->next;
	head->next = NULL;
	delete head;
	head = p->next;
}