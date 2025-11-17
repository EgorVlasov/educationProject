#include <iostream>
#include <string>
#include <map>
#include <limits>

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

bool is_input_name_correct(string &inputName)
{
    if (inputName.length() > 15)
    {
        cerr << "Error. Too many symbols" << endl;
        return false;
    }
    if (inputName.length() < 2)
    {
        cerr << "Error. Incorrect name" << endl;
        return false;
    }
    if (inputName.front() == '-' || inputName.back() == '-')
    {
        cerr << "Error. Hyphen cannot be first or last symbol" << endl;
        return false;
    }
    int nameLength = inputName.length();
    for (size_t j = 0; j < nameLength; j++)
    {
        if (!isalpha(inputName[j]) && inputName[j] != '-')
        {
            cerr << "Error. Invalid name. String should contain only letters (A-Z, a-z) or symbol '—'" << endl;
            return false;
        }
        if ((j == 0 || j == nameLength - 1) && inputName[j] == '-')
        {
            cerr << "Error. Hyphen cannot be first or last symbol" << endl;
            return false;
        }
        if (inputName[j] == '-' && inputName[j + 1] == '-')
        {
            cerr << "Error. Double hyphen not allowed" << endl;
            return false;
        }

        if (j == 0 && islower(inputName[j]))
        {
            inputName[j] = toupper(inputName[j]);
        }
    }
    return true;
}

int main()
{
    multimap<string, string> clientsQueue;
    string name;
    while (true)
    {
        do
        {
            cout << "Input client name to add him to queue or 'Next' to call client from the queue" << endl;
            cout << "Input 'Exit' to exit" << endl;
            cin >> name;
        } while (has_input_error() || !is_input_name_correct(name));

        if (name == "Next")
        {
            auto nextClient = clientsQueue.begin();
            if (!clientsQueue.empty())
            {
                cout << nextClient->first << endl;
                clientsQueue.erase(nextClient);
            }
            else
            {
                cout << "No clients in queue" << endl;
            }
        }
        else if (name == "Exit")
        {
            return 0;
        }
        else
        {
            clientsQueue.insert({name, ""});
            cout << "client added" << endl;
        }
    }
}