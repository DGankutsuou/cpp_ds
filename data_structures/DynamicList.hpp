#pragma once
# include "Dblst.hpp"
# include <iostream>
using namespace std;

template <typename T>
class DynamicList
{
protected:
    T *_array;
    int _size = 0;
public:
    DynamicList(int s)
    {
        if (s < 0)
            s = 0;
        _size = s;
        _array = new T[s];
    }

    ~DynamicList()
    {
        delete[] _array;
    }

    void print(void)
    {
        for (int i = 0; i < _size; i++)
        {
            cout << _array[i];
            if (i < _size - 1)
                cout << " , ";
        }
        cout << endl;
    }

    int size(void)
    {
        return (_size);
    }

    T at(int index)
    {
        if (index < 0 || index >= _size)
            return (T)0;
        return _array[index];
    }

    void update_item(int index, T value)
    {
        if (index < 0 || index >= _size)
            return ;
        _array[index] = value;
    }
};
