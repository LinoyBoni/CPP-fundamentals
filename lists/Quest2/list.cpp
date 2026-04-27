/*
implementaion class list
C++ course
exercise 5.2
name:linoy boni
*/
#include"list.h"
List::Link::Link(int val, Link* nxt)
	: value(val), next(nxt)
{}
List::Link::Link(const Link& source)
	: value(source.value), next(source.next)
{}
List::List() : head(NULL)
{
	// no further initialization
}
List::List(const List &l)
{
	Link *src, *trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}
List::~List()
{
	clear();
}
void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link * p = head; p != NULL; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}
bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null

	return head == NULL;

}
void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}
int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}
bool  List::search(const int &val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}
/*
------------operators------------------
*/
istream& operator>>(istream& s, List& l)
{
	int val, nextVal;
	cin >> val;
	cin >> nextVal;
	if (l.head)
		l.head->value = val;
	else
		l.head = new List::Link(val, NULL);
	List::Link* n = l.head;
	while (val < nextVal)//ëì òåã æä ÷èï
	{
		if (n->next)
			n->next->value = nextVal;
		else
			n->next = new List::Link(nextVal, NULL);
		val = nextVal;
		cin >> nextVal; //îàôùø ÷ìéèä áöåøä îîåéðú 
		n = n->next;
	}
	return s;
}
ostream& operator<<(ostream& s, List& l)
{
	for (List::Link* p = l.head; p != NULL; p = p->next)
		s << p->value << " ";
	return s;
}
List& List::operator=(const List l)
{
	Link *src, *trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this;
}
//-----------------------------quest 2-----------------
void List::insert(int key)
{
	if (!head || key < head->value)
		(*this).add(key);
	else
	{
		List::Link* p = head;
		while (p->next && p->next->value < key)
			p = p->next;
		if (p->next)
			p->next = new Link(key, p->next);
		else
			p->next = new Link(key, NULL);
	}
}
void List::remove(int key)
{
	try
	{
		if (head->value == key)
			(*this).removeFirst();
		else
		{
			bool flag = false;
			for (Link* p = head; p->next != NULL; p = p->next)
			{
				if (key == p->next->value)
				{
					Link* del = p->next;
					p->next = p->next->next;
					delete del;
					flag = true;
					break;
				}
			}
			if (!flag)
				throw "value not found";//äåãòú çøéâä
		}
	}
	catch (char* str)
	{
		cout << str;
	}
}