#pragma once
# include "data_structures/PaStack.hpp"

class String
{
private:
    PaStack <string> _changes;
    PaStack <string> _undone;
    string _value = "";
public:
    string get_value(void)
    {
        return _value;
    }

    void set_value(string val)
    {
        _changes.push(_value);
        _value = val;
    }

    void undo(void)
    {
        if (_changes.size() > 0)
        {
            _undone.push(_value);
            _value = _changes.top();
            _changes.pop();
        }
    }

    void redo(void)
    {
        if (!_undone.size())
            return ;
        _changes.push(_value);
        _value = _undone.top();
        _undone.pop();
    }
};
