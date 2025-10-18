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
			return ;
		}
		Node *lst = _head;
		while (lst->next)
			lst = lst->next;
		lst->next = new Node;
		lst->next->value = value;
		lst->next->previous = lst;
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
		lst->next->next = saver;
		lst->next->previous = lst;
		if (saver)
			saver->previous = lst->next;
	}

	void dblist_delone(Node *node)
	{
		if (!node)
			return ;
		Node *lst = _head;
		while (lst != NULL && lst->next != node)
			lst = lst->next;
		if (lst == NULL)
			return ;
		Node *saver = lst->next->next;
		delete lst->next;
		if (saver)
			saver->previous = lst;
		lst->next = saver;
	}

	void dblist_dellast(void)
	{
		Node *lst = _head;
		if (lst != NULL && lst->next == NULL)
		{
			delete _head;
			_head = NULL;
			return ;
		}
		while (lst != NULL && lst->next->next != NULL)
			lst = lst->next;
		if (lst == NULL)
			return ;
		delete lst->next;
		lst->next = NULL;
	}

	void dblist_clear(void)
	{
		Node *lst = _head;
		Node *tmp;
		while (lst)
		{
			tmp = lst->next;
			delete lst;
			lst = tmp;
		}
		_head = NULL;
	}
};
