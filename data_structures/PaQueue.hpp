#pragma once
# include "Dblst.hpp"
# include <iostream>
using namespace std;

template <typename T>
class PaQueue
{
protected:
    Dblst <T> _list;
public:
    void push(T value)
    {
        _list.add_back(value);
    }

    void pop(void)
    {
        _list.delfirst();
    }

    void print(void)
    {
        _list.print();
    }

    int size(void)
    {
        return (_list.size());
    }

    T front(void)
    {
        return (_list.at(0));
    }

    T back(void)
    {
        return (_list.at(_list.size() - 1));
    }
};
