#include <iostream>
#include "data_structure/DbList.hpp"
using namespace std;

int main(void)
{
    DbList <int> list;
    list.dblistadd_front(1337);
    list.dblistadd_front(42);
    list.dblistadd_front(21);
    list.dblistadd_back(2005);
    list.dblistadd_back(2);
    DbList<int>::Node *node = list.find(42);
    DbList<int>::Node *node2 = list.find(2005);
    list.dblistadd_after(node2, 25);
    if (node)
        cout << node->next->value << endl;
    if (node2)
        cout << node2->previous->value << endl;
    cout << "size: " << list.dblist_size() << endl;
    list.dblist_print();
    list.dblist_delone(node);
    list.dblist_print();
    list.dblist_dellast();
    list.dblist_print();
    list.dblist_clear();
    list.dblist_print();
    list.dblistadd_back(1337);
    list.dblistadd_back(42);
    list.dblistadd_back(21);
    list.dblist_print();
    list.dblist_delfirst();
    list.dblist_print();
    return (0);
}
