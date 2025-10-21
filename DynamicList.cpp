#include "data_structures/DynamicList.hpp"

int main(void)
{
    DynamicList <int> list(10);

    list.update_item(0, 21);
    list.update_item(1, 42);
    list.update_item(2, 1337);
    list.print();
    cout << "the size: " << list.size() << endl;
    cout << "at 1: " << list.at(1) << endl;
    return (0);
}