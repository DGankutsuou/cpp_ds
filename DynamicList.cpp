#include "data_structures/DynamicList.hpp"

int main(void)
{
    DynamicList <int> list(10);

    list.update_item(0, 21);
    list.update_item(1, 42);
    list.update_item(2, 1337);
    list.reverse();
    list.print();
    list.reverse();
    cout << "the size: " << list.size() << endl;
    cout << "at 1: " << list.at(1) << endl;
    list.resize(2);
    list.print();
    cout << "the size: " << list.size() << endl;
    cout << "at 1: " << list.at(1) << endl;
    list.clear();
    cout << "the size: " << list.size() << endl;
    return (0);
}