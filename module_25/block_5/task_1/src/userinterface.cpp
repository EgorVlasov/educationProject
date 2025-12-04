#include <iostream>
#include "userinterface.h"

using namespace std;

bool has_input_error()
{
    if (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Input error. Try again" << endl;
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}

bool is_valid_command(int command, int maxValue)
{
    if (command < 0 || command > maxValue)
    {
        cerr << "Invalide operation code." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

int get_user_command(int maxValue)
{
    unsigned int command = 0;
    do
    {
        cout << "=== MENU ===" << endl;
        cout << "1 - use scalpel" << endl;
        cout << "2 - hemostat" << endl;
        cout << "3 - tweezers" << endl;
        cout << "4 - suture" << endl;
        cout << "0 - finish" << endl;
        cin >> command;
    } while (has_input_error() || !is_valid_command(command, maxValue));
    return command;
}

float get_coordinate()
{
    float x = 0;
    do
    {
        cin >> x;
    } while (has_input_error());
    return x;
}