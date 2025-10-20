#include <iostream>
#include "data_structures/Dblst.hpp"
using namespace std;

int main(void)
{
    Dblst <int> list;
    list.add_front(1337);
    list.add_front(42);
    list.add_front(21);
    list.add_back(2005);
    list.add_back(2);
    Dblst<int>::Node *node = list.find(42);
    Dblst<int>::Node *node2 = list.find(2005);
    list.add_after(node2, 24);
    list.update_item(4, 25);
    list.add_after(1, 2019);
    cout << "at index 3: " << list.get_node(3)->value << endl;
    cout << "at index 2: " << list.at(2) << endl;
    if (node)
        cout << node->next->value << endl;
    if (node2)
        cout << node2->previous->value << endl;
    cout << "size: " << list.size() << endl;
    list.print();
    list.reverse();
    list.print();
    list.delone(node);
    list.print();
    list.dellast();
    list.print();
    list.clear();
    list.print();
    list.add_back(1337);
    list.add_back(42);
    list.add_back(21);
    list.print();
    list.delfirst();
    list.print();
    if (list.is_empty())
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl;
    return (0);
}
