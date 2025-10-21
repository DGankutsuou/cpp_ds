#pragma once
# include "Dblst.hpp"
# include "PaDLQueue.hpp"
# include <iostream>
using namespace std;

template <typename T>
class PaDLStack : public PaDLQueue <T>
{
public:
    void push(T value)
    {
        PaDLQueue<T>::add_front(value);
    }

    T top(void)
    {
        return (PaDLQueue<T>::at(0));
    }

    T bottom(void)
    {
        return (PaDLQueue<T>::at(PaDLQueue<T>::size() - 1));
    }
};
