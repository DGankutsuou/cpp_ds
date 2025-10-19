#pragma once
# include <iostream>
using namespace std;

template <typename T>
class Dblst
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

	Dblst(void){}
	~Dblst(){}

	void add_front(T value)
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

	void print(void)
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

	void add_back(T value)
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

	void add_after(Node *node, T value)
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

	void delone(Node *node)
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

	void dellast(void)
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

	void delfirst(void)
	{
		// delone(head);
		if (head == NULL)
			return ;
		Node *tmp = head;
		head = head->next;
		if (head != NULL)
			head->previous = NULL;
		delete tmp;
		_size--;
	}

	void clear(void)
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

	int size(void)
	{
		return (_size);
	}

	bool is_empty(void)
	{
		return (!_size);
	}

	void reverse(void)
	{
		if (head == NULL || head->next == NULL)
			return ;
		Node *lst = head;
		Node *tmp;
		while (lst)
		{
			tmp = lst->previous;
			lst->previous = lst->next;
			lst->next = tmp;
			lst = lst->previous;
		}
		if (tmp != NULL)
			head = tmp->previous;
	}

	Node *get_node(int index)
	{
		if (index >= _size || index < 0)
			return NULL;
		Node *lst = head;
		int i = 0;
		while (lst)
		{
			if (i == index)
				return lst;
			lst = lst->next;
			i++;
		}
		return NULL;
	}

	T at(int index)
	{
		if (index >= _size || index < 0)
			return (T)0;
		Node *lst = head;
		int i = 0;
		while (lst)
		{
			if (i == index)
				return lst->value;
			lst = lst->next;
			i++;
		}
		return (T)0;
	}

	bool update_item(int index, T value)
	{
		Node *node = get_node(index);
		if (node != nullptr)
		{
			node->value = value;
			return true;
		}
		return false;
	}

	bool add_after(int index, T value)
	{
		Node *node = get_node(index);
		if (node != nullptr)
		{
			add_after(node, value);
			return true;
		}
		return false;
	}
};
