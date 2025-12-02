#include <iostream>
#include <string>
#include <strstream>
#include <iomanip>
#include <ctime>
#include <map>

using namespace std;

struct Birthdays
{
    string friendName;
    unsigned day = 0;
    unsigned int month = 0;
    unsigned int year = 0;
};

multimap<int, Birthdays> friendsList;

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

bool is_year_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_input_date_correct(Birthdays &date)
{
    if (date.day == 0 || date.day > 31)
    {
        cerr << "Error. Incorrect date." << endl;
        cerr << "There cannot be more than 31 days in a month. Exception of February, which has no more than 28 days (29 in a leap year)." << endl;
        return false;
    }
    if (date.month == 0 || date.month > 12)
    {
        cerr << "Error. Incorrect date." << endl;
        cerr << "Only 12 months in the year." << endl;
        return false;
    }
    else if (date.month == 2 && date.day > 29)
    {
        cerr << "Error. Incorrect date." << endl;
        cerr << "February cannot have more than 28 days (29 in a leap year)." << endl;
        return false;
    }
    if (date.year == 0 || date.year > 2026)
    {
        cerr << "Error. Incorrect date." << endl;
        cerr << "The year cannot be from the future or be equal 0" << endl;
        return false;
    }
    else if (!is_year_leap(date.year) && date.month == 2 && date.day > 28)
    {
        cerr << "Error. Incorrect date." << endl;
        cerr << date.year << " is not a leap year, February cannot have more than 28 days." << endl;
        return false;
    }

    return true;
}

void showBirthdayListforToday()
{
    if (friendsList.empty())
    {
        cout << "Your berthday list is empty" << endl;
        return;
    }
    time_t now = time(nullptr);
    tm today = *localtime(&now);
    int y = today.tm_year + 1900;
    int m = today.tm_mon + 1;
    int d = today.tm_mday;

    int key = m * 100 + d;
    auto range = friendsList.equal_range(key);

    cout << put_time(&today, "%A, %B %d, %Y") << endl;
    cout << "Birthday list for today:" << endl;
    cout << endl;

    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->second.friendName << " "
             << it->second.day << "."
             << it->second.month << "."
             << it->second.year
             << "(" << y - it->second.year << ")" << endl;
        cout << endl;
    }
    if (range.first == range.second)
    {
        cout << "No birthdays today" << endl;
        if (range.second != friendsList.end())
        {
            cout << "Next nearest birthday:" << endl;
            cout << range.second->second.friendName << " "
                 << range.second->second.day << "."
                 << range.second->second.month << "."
                 << range.second->second.year
                 << "(" << y - range.second->second.year << ")" << endl;
            cout << endl;
        }
        else
        {
            cout << "No nearest birthdays" << endl;
        }
    }
}

void addNewBirthdayDate(Birthdays &birthday)
{
    do
    {
        cout << "Input name: (30 symbols max)" << endl;
        getline(cin, birthday.friendName);
        if (birthday.friendName == "stop")
        {
            return;
        }
        if (birthday.friendName.length() > 30)
        {
            cerr << "Error. To many symbols" << endl;
        }
    } while (has_input_error() || birthday.friendName.length() > 30);

    do
    {
        cout << "Input birthday date: (Y M D)" << endl;
        cin >> birthday.year >> birthday.month >> birthday.day;
    } while (has_input_error() || !is_input_date_correct(birthday));

    int newKey = birthday.month * 100 + birthday.day;
    friendsList.emplace(newKey, birthday);
}

int main()
{
    Birthdays birthday;

    do
    {
        addNewBirthdayDate(birthday);
    } while (birthday.friendName != "stop");

    showBirthdayListforToday();

    return 0;
}
