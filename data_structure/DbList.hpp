#pragma once
# include <iostream>
using namespace std;

template <typename T>
class DbList
{
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
		if (head == NULL)
		{
			head = new Node;
			head->value = value;
		}
		else if (head->previous == NULL)
		{
			head->previous = new Node;
			head->previous->value = value;
			head->previous->next = head;
			head = head->previous;
		}
		else
		{
			head->previous->next = new Node;
			head->previous->next->value = value;
			head->previous->next->next = head;
			head->previous->next->previous = head->previous;
		}
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
	}

	void dblistadd_after(Node *node, T value)
	{
		if (head == NULL)
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
	}

	void dblist_delone(Node *node)
	{
		if (!node)
			return ;
		Node *lst = head;
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
		Node *lst = head;
		if (lst != NULL && lst->next == NULL)
		{
			delete head;
			head = NULL;
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
		Node *lst = head;
		Node *tmp;
		while (lst)
		{
			tmp = lst->next;
			delete lst;
			lst = tmp;
		}
		head = NULL;
	}
};
