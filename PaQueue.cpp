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
    return (0);
}