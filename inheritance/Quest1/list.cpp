/*
implementaion class list
C++ course
exercise 6.1
name:linoy boni
*/
#include "list.h"
List::List() :head(NULL) {}
List::List(const List & l)
{
	if (l.head == NULL)
		head = NULL;
	else
	{
		Link *p, *q;
		head = new Link(l.head->value, NULL);
		p = l.head;
		q = head;
		while (p->next != NULL)
		{
			q->next = new Link(p->next->value, NULL);
			p = p->next;
			q = q->next;
		}
	}
}
List::~List()
{
	clear();
}
//operations
void List::clear()
{
	Link *p, *next;
	for (p = head; p != NULL; p = next)
	{
		next = p->next;
		p->next = NULL;
		delete p;
	}
	head = NULL;
}
void List::add(int val)
{
	head = new Link(val, head);
}
void List::addLast(int val) 
{
	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new Link(val, ptr->next);
}
bool List::isEmpty()
{return head == NULL;}

void List::removeFirst()
{
	if (isEmpty())
		throw "the List is empty, no Elements to remove\n";
	Link *p = head;
	head = head->next;
	p->next = NULL;
	delete p;
}
void List::insert(int key)
{
	if (isEmpty() || head->value > key)
		add(key);
	else
	{
		ptr = head;
		Link* tmp = new Link(key);
		while (ptr->next != NULL)
		{
			if (ptr->next->value > key)
				break;
			ptr = ptr->next;
		}
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
}
List List::operator=(const List & l)
{
	if (!isEmpty())
		clear();
	if (l.head == NULL)
		head = NULL;
	else
	{
		Link *p, *q;
		head = new Link(l.head->value, NULL);
		p = l.head;
		q = head;
		while (p->next != NULL)
		{
			q->next = new Link(p->next->value, NULL);
			p = p->next;
			q = q->next;
		}
	}
	return *this;
}
ostream & operator<<(ostream & out, List & l)
{
	l.ptr = l.head;
	while (l.ptr)
	{
		cout << l.ptr->value;
		cout << " ";
		l.ptr = l.ptr->next;
	}
	return out;
}
istream & operator >> (istream & in, List & l)
{
	int k1, k2;
	cin >> k1;
	if (l.isEmpty())
		l.add(k1);
	cin >> k2;
	while (k2 > k1)
	{
		l.addLast(k2);
		k1 = k2;
		cin >> k2;
	}
	return in;
}