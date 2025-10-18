#pragma once
# include <iostream>
using namespace std;

template <typename T>
class DbList
{
public:
	class	Node;
private:
	Node	*_head = NULL;
public:
	class Node
	{
	public:
		T		value;
		Node	*previous = NULL;
		Node	*next = NULL;
	};
	DbList(void){}
	~DbList(){}

	void dblistadd_front(T value)
	{
		if (_head == NULL)
		{
			_head = new Node;
			_head->value = value;
		}
		else if (_head->previous == NULL)
		{
			_head->previous = new Node;
			_head->previous->value = value;
			_head->previous->next = _head;
			_head = _head->previous;
		}
		else
		{
			_head->previous->next = new Node;
			_head->previous->next->value = value;
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

	void dblist_print(void)
	{
		Node *lst = _head;
		while (lst)
		{
			cout << lst->value;
			if (lst->next)
				cout << " - ";
			lst = lst->next;
		}
		cout << endl;
	}

	void dblistadd_back(T value)
	{
		if (_head == NULL)
		{
			_head = new Node;
			_head->value = value;
		}
		Node *lst = _head;
		while (lst->next)
			lst = lst->next;
		lst->next = new Node;
		lst->next->value = value;
	}

	void dblistadd_after(Node *node, T value)
	{
		if (_head == NULL)
			return ;
		Node *lst = _head;
		while (lst != node && lst != NULL)
			lst = lst->next;
		if (lst == NULL)
			return ;
		Node *saver = lst->next;
		lst->next = new Node;
		lst->next->value = value;
	}
};
