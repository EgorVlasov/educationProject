#include <iostream>
#include <string>
#include <map>

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

bool is_input_str_correct(const string &inputStr)
{
    if (inputStr.length() > 30)
    {
        cerr << "Error. Too many symbols" << endl;
        return false;
    }
    if (inputStr.length() < 2)
    {
        cerr << "Error. Word is too short" << endl;
        return false;
    }
    for (size_t j = 0; j < inputStr.length(); j++)
    {
        if (!isalpha(inputStr[j]))
        {
            cerr << "Error.String should contain only letters (A-Z, a-z)" << endl;
            return false;
        }
    }
    return true;
}

bool is_anagram(const string &str_1, const string &str_2)
{
    if (str_1.length() != str_2.length())
    {
        return false;
    }

    multimap<char, char> sortCharArr;
    for (char c : str_1)
    {
        sortCharArr.insert({tolower(c), ' '});
    }

    for (char c : str_2)
    {
        auto it = sortCharArr.find(tolower(c));
        if (it == sortCharArr.end())
        {
            return false;
        }
        sortCharArr.erase(it);
    }
    return true;
}

int main()
{
    string str_1;
    string str_2;
    while (true)
    {
        do
        {
            cout << "Input first word" << endl;
            cout << "'Exit' to exit" << endl;
            cin >> str_1;
        } while (has_input_error() || !is_input_str_correct(str_1));

        if (str_1 == "exit" || str_1 == "Exit")
        {
            return 0;
        }

        do
        {
            cout << "Input second word" << endl;
            cin >> str_2;
        } while (has_input_error() || !is_input_str_correct(str_2));

        if (is_anagram(str_1, str_2))
        {
            cout << "'" << str_2 << "' is anagram of '" << str_1 << "'" << endl;
        }
        else
        {
            cout << "'" << str_2 << "' is NOT anagram of '" << str_1 << "'" << endl;
        }
    }
}