#pragma once
# include "Dblst.hpp"
# include "PaQueue.hpp"
# include <iostream>
using namespace std;

template <typename T>
class PaStack : public PaQueue <T>
{
public:
    void push(T value)
    {
        PaQueue<T>::add_front(value);
    }

    T top(void)
    {
        return (PaQueue<T>::at(0));
    }

    T bottom(void)
    {
        return (PaQueue<T>::at(PaQueue<T>::size() - 1));
    }
};
