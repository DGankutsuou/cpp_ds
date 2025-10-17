#pragma once
# include <iostream>
using namespace std;

template <typename T>
class DbList
{
private:
	class	Node;
	Node	*_head = NULL;
public:
	class Node
	{
	public:
		T		value;
		Node	*previous = NULL;
		Node	*next = NULL;
	}
	DbList(void);
	~DbList();

	void dblistadd_front(T value)
	{
		if (_head == NULL)
		{
			_head = new Node;
			_head->value = T;
		}
		else if (_head->previous == NULL)
		{
			_head->previous = new Node;
			_head->previous->value = T;
			_head->previous->next = _head;
			_head = _head->previous;
		}
		else
		{
			_head->previous->next = new Node;
			_head->previous->next->value = T;
			_head->previous->next->next = _head;
			_head->previous->next->previous = _head->previous;
		}
	}

	Node *find(T value)
	{
		Node *lst = _head;
		while (lst)
		{
			if (lst->value == value)
				return lst;
			lst = lst->next;
		}
		return NULL;
	}
};

DbList<void>::DbList(void)
{
}

DbList<void>::~DbList()
{
}
