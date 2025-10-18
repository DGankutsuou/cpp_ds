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
    // list.dblistadd_back(2005);
    DbList<int>::Node *node = list.find(42);
    DbList<int>::Node *node2 = list.find(1337);
    if (node)
        cout << node->next->value << endl;
    if (node2)
        cout << node2->previous->value << endl;
    list.dblist_print();
    return (0);
}
