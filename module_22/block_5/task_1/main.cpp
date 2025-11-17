#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> phoneDirectory;
multimap<string, string> reversPhoneDirectory;

bool is_input_phone_correct(const string &inputPhone)
{
    if (inputPhone.length() != 11)
    {
        cerr << "Error. Incorrect phone number length" << endl;
        return false;
    }

    if (inputPhone.substr(0, 2) != "79")
    {
        cerr << "Error. Incorrect phone number format" << endl;
        return false;
    }

    for (char c : inputPhone)
    {
        if (!isdigit(c))
        {
            cerr << "Error. Phone number should contain only digits" << endl;
            return false;
        }
    }

    return true;
}

bool is_input_name_correct(string &inputName)
{
    if (inputName.length() > 15)
    {
        cerr << "Error. To many symbols" << endl;
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
    for (size_t j = 0; j < inputName.length(); j++)
    {
        if (!isalpha(inputName[j]) && inputName[j] != '-')
        {
            cerr << "Error. Invalid name. String shoud contain only latters (A-Z, a-z) or symbol '—'" << endl;
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

void input_phone(string &phone)
{
    do
    {
        cout << "Input phone: " << endl;
        cin >> phone;
    } while (has_input_error() || !is_input_phone_correct(phone));
}
void input_name(string &name)
{
    do
    {
        cout << "Input name: " << endl;
        cin >> name;
    } while (has_input_error() || !is_input_name_correct(name));
}

void add_to_phoneDirectory(string &phone, string &name)
{
    input_phone(phone);
    input_name(name);

    auto result_1 = phoneDirectory.insert({phone, name});

    if (result_1.second)
    {
        reversPhoneDirectory.insert({name, phone});
        cout << "Phone number added" << endl;
    }
    else
    {
        cerr << "Phone number already exist" << endl;
        cout << phoneDirectory.find(phone)->first << " - " << phoneDirectory.find(phone)->second << endl;
    }
}

int main()
{
    string phone;
    string name;
    unsigned userCommand = 0;
    while (true)
    {
        cout << "Input command:" << endl
             << "1 - add new record" << endl
             << "2 - find name by phone number" << endl
             << "3 - find phone number by name" << endl
             << "0 - exit" << endl;
        {
            cin >> userCommand;
            if (userCommand > 3)
            {
                cerr << "Ivalind command" << endl;
            }
        }
        while (has_input_error() || userCommand > 3)
            ;

        switch (userCommand)
        {
        case 1:
        {
            add_to_phoneDirectory(phone, name);
            break;
        }
        case 2:
        {
            input_phone(phone);
            auto result = phoneDirectory.find(phone);
            if (result != phoneDirectory.end())
            {
                cout << result->first << " - " << result->second << endl;
            }
            else
            {
                cout << "There are no records matching the query '" << phone << "'" << endl;
            }
            break;
        }
        case 3:
        {
            input_name(name);
            auto range = reversPhoneDirectory.equal_range(name);
            int cnt = 0;
            for (auto it = range.first; it != range.second; ++it)
            {
                cout << it->first << " - " << it->second << endl;
                cnt++;
            }
            if (cnt == 0)
            {
                cout << "There are no records matching the query '" << name << "'" << endl;
            }
            break;
        }
        case 0:
            return 0;

        default:
            return 0;
        }
    }
}