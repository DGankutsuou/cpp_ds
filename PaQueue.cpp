#include "data_structures/PaQueue.hpp"

int main(void)
{
    PaQueue <string> queue;

    queue.push("Ayman");
    queue.push("Jesus");
    queue.push("Othman");
    queue.push("Boxee");
    queue.push("Dadda");

    queue.print();
    cout << "queue back: " << queue.back() << endl;
    cout << "queue front: " << queue.front() << endl;
    queue.pop();
    queue.pop();
    queue.print();
    cout << "queue size: " << queue.size() << endl;
    queue.add_after(0, "Ilyass");
    queue.add_back("Yassine");
    queue.add_front("Hicham");
    queue.reverse();
    queue.print();
    queue.update_item(3, "Ayman");
    cout << "at 3: " << queue.at(3) << endl;
    return (0);
}