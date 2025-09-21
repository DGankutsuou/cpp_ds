#pragma once
# include <iostream>
using namespace std;

template <typename T>
class DbList
{
private:
	class	Node;
	Node	*_head;
public:
	class Node
	{
	public:
		T		value;
		Node	*previous;
		Node	*next;
	}
	DbList(void);
	~DbList();
};

DbList<void>::DbList(void)
{
}

DbList<void>::~DbList()
{
}

