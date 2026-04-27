#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <stack>
#include "queue.h"
using namespace std;
class QueueStack : public Queue
{
protected:
	stack<int> data;
public:
	QueueStack()
	{

	}
	~QueueStack()
	{

	}
	void clear() override
	{
		if (!this->isEmpty())
			this->data.pop();
	}
	int dequeue() override
	{
		stack<int> tmp;
		while (!this->isEmpty())
		{
			tmp.push(data.top());
			data.pop();
		}
		int deq = tmp.top();
		tmp.pop();
		while (!tmp.empty())
		{
			data.push(tmp.top());
			tmp.pop();
		}
		return deq;
	}
	void enqueue(int value) override
	{
		data.push(value);
	}
	int front() override
	{
		stack<int> tmp;
		while (!this->isEmpty())
		{
			tmp.push(data.top());
			data.pop();
		}
		int fro = tmp.top();
		while (!tmp.empty())
		{
			data.push(tmp.top());
			tmp.pop();
		}
		return fro;
	}
	bool isEmpty() const override
	{
		if (data.empty())
			return true;
		return false;
	}
};
