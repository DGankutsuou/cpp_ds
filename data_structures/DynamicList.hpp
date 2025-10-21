#pragma once
# include "Dblst.hpp"
# include <iostream>
using namespace std;

template <typename T>
class DynamicList
{
protected:
    T *_array{NULL};
    int _size = 0;
public:
    DynamicList(int s)
    {
        if (s < 0)
            s = 0;
        else
        {
            _size = s;
            _array = new T[s];
        }
    }

    ~DynamicList()
    {
        delete[] _array;
        _array = NULL;
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

    bool is_empty(void)
    {
        return (!_size);
    }

    void resize(int size)
    {
        if(size <= 0)
        {
            delete[] _array;
            _array = NULL;
            _size = 0;
        }
        else
        {
            T *new_arr = new T[size];
            for (int i = 0; i < size && i < _size; i++)
            {
                new_arr[i] = _array[i];
            }
            delete[] _array;
            _array = new_arr;
            _size = size;
        }
    }

    void clear(void)
    {
        delete[] _array;
        _array = NULL;
        _size = 0;
    }

    void reverse(void)
    {
        T *new_arr = new T[_size];
        for (int i = 0; i < _size; i++)
        {
            new_arr[_size - 1 - i] = _array[i];
        }
        delete[] _array;  
        _array = new_arr; 
    }

    bool del_item(int index)
    {
        if (index >= _size || index < 0 || _size == 0)
            return false;
        T *new_arr = new T[_size - 1];
        for (int i = 0; i < index; i++)
        {
            new_arr [i] = _array[i];
        }
        for (int i = index + 1; i < _size; i++)
        {
            new_arr [i - 1] = _array[i];
        }
        delete[] _array;
        _array = new_arr;
        _size--;
        return (true);
    }

    bool del_first(void)
    {
        return (del_item(0));
    }

    bool del_last(void)
    {
        return (del_item(_size - 1));
    }

    int find(T value)
    {
        for (int i = 0; i < _size; i++)
        {
            if (_array[i] == value)
                return (i);
        }
        return (-1);
    }

    bool del_val(T val)
    {
        return (del_item(find(val)));
    }

    bool insert_at(int index, T value)
    {
        if (index < 0 || index >= _size)
            return false;
        T *new_arr = new T[_size + 1];
        for (int i = 0; i < index; i++)
        {
            new_arr[i] = _array[i];
        }
        new_arr[index] = value;
        for (int i = index; i < _size; i++)
        {
            new_arr[i + 1] = _array[i];
        }
        delete[] _array;
        _array = new_arr;
        ++_size;
        return true;
    }
};
