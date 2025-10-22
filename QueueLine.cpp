#include "QueueLine.hpp"

int main(void)
{
    QueueLine VIPLine("V0", 1);

    VIPLine.issue_ticket();
    VIPLine.issue_ticket();
    VIPLine.issue_ticket();
    VIPLine.issue_ticket();
    VIPLine.issue_ticket();

    VIPLine.print_info();
    return 0;
}
