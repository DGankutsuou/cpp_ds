#pragma once
# include <iostream>
# include <string>
# include <queue>
using namespace std;

class QueueLine
{
private:
    int _time = 0;
    string _prefix = "";
    int _served = 0;
    int _waiting = 0;
    class Ticket
    {
    public:
        string number = "";
        int time = 0;
    };
    queue <Ticket> _line;
public:
    QueueLine(string prefix, int time)
    {
        if (time > 0)
            _time = time;
        _prefix = prefix;
    }

    void issue_ticket(void)
    {
        Ticket ticket;
        ticket.number = _prefix + to_string(_line.size() + 1);
        ticket.time = _line.size() * _time;
        _line.push(ticket);
        _waiting++;
    }

    void print_info(void)
    {
        cout << "\n__________________________________________\n";
        cout << "               Queue Info";
        cout << "\n__________________________________________\n";
        cout << "Prefix: " << _prefix << "\n";
        cout << "Total Tickets: " << _line.size() << "\n";
        cout << "Served Clients: " << _served << "\n";
        cout << "Waiting Clients: " << _waiting << "\n";
        cout << "__________________________________________\n" << endl;
    }

    void print_tickets_ltr(void)
    {
        queue <Ticket> tmp;
        tmp = _line;
        while (tmp.size())
        {
            cout << tmp.front().number;
            tmp.pop();
            if (tmp.size())
                cout << " --> ";
        }
        cout << endl;
    }

    void print_tickets_rtl(void)
    {
        queue <Ticket> tmp;
        tmp = _line;
        while (tmp.size())
        {
            cout << tmp.front().number;
            tmp.pop();
            if (tmp.size())
                cout << " --> ";
        }
        cout << endl;
    }
};
