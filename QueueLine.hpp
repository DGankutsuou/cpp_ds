#pragma once
# include "Date.hpp"
# include <iostream>
# include <string>
# include <queue>
# include <stack>
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
    private:
        string _date;
        int _time = 0;
        int _waiting = 0;
        string _number = "";
    public:

        Ticket(void)
        {
            _date = Date::get_system_date_and_time();
        }

        void set_time(int time)
        {
            _time = time;
        }

        void set_waiting(int waiting)
        {
            _waiting = waiting;
        }

        void set_number(string number)
        {
            _number = number;
        }

        string get_number(void)
        {
            return _number;
        }

        void print_info(void)
        {
            cout << "\n_________________________________\n\n";
            cout << "               " << _number << "\n\n";
            cout << "      " << _date << "\n";
            cout << "       " << "Waiting Clients: " << _waiting << "\n";
            cout << "         " << "Serve time in\n";
            cout << "           " << _time << " Minutes\n";
            cout << "_________________________________\n"
                 << endl;
        }
    };

    queue<Ticket> _line;

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
        ticket.set_number(_prefix + to_string(_line.size() + 1));
        ticket.set_time(_line.size() * _time);
        ticket.set_waiting(_line.size());
        _line.push(ticket);
        _waiting++;
    }

    void print_info(void)
    {
        cout << "\n__________________________________________\n";
        cout << "               Queue Info";
        cout << "\n__________________________________________\n";
        cout << "Prefix: " << _prefix << "\n";
        cout << "Total Tickets: " << _waiting + _served << "\n";
        cout << "Served Clients: " << _served << "\n";
        cout << "Waiting Clients: " << _waiting << "\n";
        cout << "__________________________________________\n"
             << endl;
    }

    void print_tickets_ltr(void)
    {
        queue<Ticket> tmp;
        tmp = _line;
        while (tmp.size())
        {
            cout << tmp.front().get_number();
            tmp.pop();
            if (tmp.size())
                cout << " --> ";
        }
        cout << endl;
    }

    void print_tickets_rtl(void)
    {
        queue <Ticket>  tmp;
        int             len;
        stack <string>  stc;
        
        tmp = _line;
        len = tmp.size();
        while (tmp.size())
        {
            stc.push(tmp.front().get_number());
            tmp.pop();
        }
        for (int i = 0; i < len; i++)
        {
            cout << stc.top();
            if (i < len - 1)
                cout << " <-- ";
        }
        cout << endl;
    }

    void print_all_tickets(void)
    {
        queue<Ticket> tmp;
        tmp = _line;
        cout << "\n_________________________________\n\n";
        cout << "              Tickets" << endl;
        while (tmp.size())
        {
            tmp.front().print_info();
            tmp.pop();
        }
    }

    bool serve_next(void)
    {
        if (!_line.size())
            return false;
        _waiting--;
        _served++;
        _line.pop();
        return true;
    }
};
