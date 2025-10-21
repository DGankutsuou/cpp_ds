#include "String.hpp"

int main(void)
{
    String str;

    cout << "value 1: " << str.get_value() << endl;
    str.set_value("Ayman");
    cout << "value 2: " << str.get_value() << endl;
    str.set_value("Hicham");
    cout << "value 3: " << str.get_value() << endl;
    str.set_value("Salah");
    cout << "value 4: " << str.get_value() << endl;
    str.undo();
    cout << "value 5: " << str.get_value() << endl;
    str.undo();
    cout << "value 6: " << str.get_value() << endl;
    str.undo();
    cout << "value 7: " << str.get_value() << endl;
    str.undo();
    cout << "value 8: " << str.get_value() << endl;
    str.redo();
    cout << "value 9: " << str.get_value() << endl;
    str.redo();
    cout << "value 10: " << str.get_value() << endl;
    str.redo();
    cout << "value 11: " << str.get_value() << endl;
    str.redo();
    cout << "value 12: " << str.get_value() << endl;

    return 0;
}