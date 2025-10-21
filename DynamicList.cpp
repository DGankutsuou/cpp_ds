#include "data_structures/DynamicList.hpp"

int main(void)
{
    DynamicList <int> list(5);

    list.update_item(0, 21);
    list.update_item(1, 42);
    list.update_item(2, 1337);
    list.update_item(3, 2019);
    list.update_item(4, 2005);
    list.del_item(1);
    list.del_first();
    list.del_last();
    list.del_val(1337);
    list.reverse();
    list.print();
    list.resize(5);
    list.update_item(0, 21);
    list.update_item(1, 42);
    list.update_item(2, 1337);
    list.update_item(3, 2019);
    list.update_item(4, 2005);
    list.reverse();
    list.insert_at(2, 25);
    list.print();
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