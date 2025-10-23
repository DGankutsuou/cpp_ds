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
    VIPLine.print_tickets_ltr();
    VIPLine.print_tickets_rtl();
    VIPLine.print_all_tickets();
    VIPLine.serve_next();
    VIPLine.serve_next();
    VIPLine.print_info();
    VIPLine.print_tickets_ltr();
    VIPLine.print_tickets_rtl();
    VIPLine.print_all_tickets();
    return 0;
}
