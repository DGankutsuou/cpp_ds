#pragma once
# include "DynamicList.hpp"
# include <iostream>
using namespace std;

template <typename T>
class PaDLQueue
{
protected:
    DynamicList <T> _list;
public:
    void push(T value)
    {
        _list.insert_back(value);
    }

    void pop(void)
    {
        _list.del_first();
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

    T at(int index)
    {
        return _list.at(index);
    }

    void clear(void)
    {
        _list.clear();
    }

    void reverse(void)
    {
        _list.reverse();
    }

    void update_item(int index, T value)
    {
        _list.update_item(index, value);
    }

    void add_after(int index, T value)
    {
        _list.insert_after(index, value);
    }

    void add_front(T value)
    {
        _list.insert_front(value);
    }

    void add_back(T value)
    {
        _list.insert_back(value);
    }
};
