#include <iostream>
#include "kbd.h"
#include "ram.h"

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

int get_user_command()
{
    unsigned int command = 0;
    const int maxValue = 5;
    do
    {
        cout << "=== MENU ===" << endl;
        cout << "1 - save data from RAM to the disk" << endl;
        cout << "2 - load data from the disk to RAM" << endl;
        cout << "3 - print data from RAM" << endl;
        cout << "4 - compute the data" << endl;
        cout << "5 - Enter new data" << endl;
        cout << "0 - exit" << endl;
        cin >> command;
    } while (has_input_error() || !is_valid_command(command, maxValue));
    return command;
}

void input_data(Ram &object)
{
    if (object.dataIsInitialized)
    {
        cout << "data has been already initialized. Rewrite data? (1 - yes / 0 - no)" << endl;
        bool rewriteData = 0;
        do
        {
            cin >> rewriteData;
        } while (has_input_error());

        if (!rewriteData)
        {
            cout << "Canceled" << endl;
            return;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        do
        {
            cout << "input data[" << i << "]" << endl;
            cin >> object.data[i];
        } while (has_input_error());
    }
    object.dataIsInitialized = true;
    cout << "Done! data saved in RAM" << endl;
}