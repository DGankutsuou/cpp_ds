#include "data_structures/PaStack.hpp"

int main(void)
{
    PaStack <string> stack;

    stack.push("Ayman");
    stack.push("Jesus");
    stack.push("Othman");
    stack.push("Boxee");
    stack.push("Dadda");

    stack.print();
    cout << "stack back: " << stack.back() << endl;
    cout << "stack front: " << stack.front() << endl;
    stack.pop();
    stack.pop();
    stack.print();
    cout << "stack size: " << stack.size() << endl;
    stack.add_after(0, "Ilyass");
    stack.add_back("Yassine");
    stack.add_front("Hicham");
    stack.reverse();
    stack.print();
    stack.update_item(3, "Ayman");
    cout << "at 3: " << stack.at(3) << endl;
    return (0);
}