#pragma once
# include <iostream>
using namespace std;

template <typename T>
class DbList
{
protected:
	int _size = 0;
public:
	class Node
	{
	public:
		T		value;
		Node	*previous = NULL;
		Node	*next = NULL;
	};

	Node	*head = NULL;

	DbList(void){}
	~DbList(){}

	void dblistadd_front(T value)
	{
		Node *node = new Node;
		node->value = value;
		node->previous = NULL;
		node->next = head;
		if (head != NULL)
			head->previous = node;
		head = node;
		_size++;
	}

	Node *find(T value)
	{
		Node *lst = head;
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
		Node *lst = head;
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
		if (head == NULL)
		{
			head = new Node;
			head->value = value;
			return ;
		}
		Node *lst = head;
		while (lst->next)
			lst = lst->next;
		lst->next = new Node;
		lst->next->value = value;
		lst->next->previous = lst;
		_size++;
	}

	void dblistadd_after(Node *node, T value)
	{
		if (head == NULL || node == NULL)
			return ;
		Node *lst = head;
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
		_size++;
	}

	void dblist_delone(Node *node)
	{
		if (!node || !head)
			return ;
		Node *lst = head;
		while (lst != NULL && lst != node)
			lst = lst->next;
		if (lst == NULL)
			return ;
		if (node == head)
			head = node->next;
		if (node->next != NULL)
			node->next->previous = node->previous;
		if (node->previous != NULL)
			node->previous->next = node->next;
		delete node;
		_size--;
	}

	void dblist_dellast(void)
	{
		if (head == NULL)
			return ;
		Node *lst = head;
		if (lst != NULL && lst->next == NULL)
		{
			delete head;
			head = NULL;
			_size--;
			return ;
		}
		while (lst->next != NULL && lst->next->next != NULL)
			lst = lst->next;
		delete lst->next;
		lst->next = NULL;
		_size--;
	}

	void dblist_delfirst(void)
	{
		// dblist_delone(head);
		if (head == NULL)
			return ;
		Node *tmp = head;
		head = head->next;
		if (head != NULL)
			head->previous = NULL;
		delete tmp;
		_size--;
	}

	void dblist_clear(void)
	{
		Node *lst = head;
		Node *tmp;
		while (lst)
		{
			tmp = lst->next;
			delete lst;
			_size--;
			lst = tmp;
		}
		head = NULL;
	}

	int dblist_size(void)
	{
		return (_size);
	}
};
