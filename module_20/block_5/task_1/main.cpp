#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const string path = "/Users/evlasov/Documents/educationProject/build/bin/add_files/";
const string fileName = "file.txt";

bool input_validation_errors()
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

bool check_name_input(string inputName)
{
    if (inputName.length() > 30)
    {
        cerr << "Error. To many symbols" << endl;
        return false;
    }
    stringstream ssBuffer(inputName);
    string nameBuf;
    while (ssBuffer >> nameBuf)
    {
        if (nameBuf.length() < 1)
        {
            cerr << "Error. Invalid name" << endl;
            return false;
        }
        for (size_t j = 0; j < nameBuf.length(); j++)
        {
            if (((nameBuf[j] < 65 || nameBuf[j] > 90) && (nameBuf[j] < 97 || nameBuf[j] > 122)) && nameBuf[j] != 45)
            {
                cerr << "Error. Invalid name. String shoud comtain only latters (A-Z, a-z) or symbol '-'" << endl;
                return false;
            }
        }
    }
    return true;
}
bool check_leap_year(int &year)
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
bool check_data_input(string inputDate)
{
    if (inputDate.length() > 10 || inputDate.length() < 8)
    {
        cerr << "Error. Incorrect data." << endl;
        cerr << "Correct date format: XX.XX.XXXX" << endl;
        return false;
    }
    stringstream ssBuffer(inputDate);
    int fieldNum = 0;
    string field;
    int day;
    int month;
    int year;
    while (getline(ssBuffer, field, '.'))
    {
        switch (fieldNum)
        {
        case 0:
            try
            {
                day = stoi(field);
            }
            catch (...)
            {
                cerr << "ERROR DURING CONVERSION DAY TO INT" << endl;
                cerr << "Error. Incorrect data." << endl;
                return false;
            }
            if (day < 0 || day > 31)
            {
                cerr << "Error. Incorrect data." << endl;
                cerr << year << "There cannot be more than 31 days in a month. Exception of February, which has no more than 28 days (29 in a leap year)." << endl;
                return false;
            }
            break;
        case 1:
            try
            {
                month = stoi(field);
            }
            catch (...)
            {
                cerr << "ERROR DURING CONVERSION MONTH TO INT" << endl;
                cerr << "Error. Incorrect data." << endl;
                return false;
            }
            if (month < 0 || month > 12)
            {
                cerr << "Error. Incorrect data." << endl;
                cerr << "Only 12 months in the year." << endl;
                return false;
            }
            else if (month == 2 && day > 29)
            {
                cerr << "Error. Incorrect data." << endl;
                cerr << year << "February cannot have more than 28 days (29 in a leap year)." << endl;
                return false;
            }
            break;
        case 2:
            try
            {
                year = stoi(field);
            }
            catch (...)
            {
                cerr << "ERROR DURING CONVERSION YEAR TO INT" << endl;
                cerr << "Error. Incorrect data." << endl;
                return false;
            }
            if (year < 0 || year > 2026)
            {
                cerr << "Error. Incorrect data." << endl;
                cerr << "The date cannot be from the future" << endl;
                return false;
            }
            else if (!check_leap_year(year) && month == 2 && day > 28)
            {
                cerr << "Error. Incorrect data." << endl;
                cerr << year << " is not a leap year, February cannot have more than 28 days." << endl;
                return false;
            }
            break;
        case 3:
            cerr << "Error. Incorrect data." << endl;
            cerr << "Correct date format: XX.XX.XXXX" << endl;
            return false;
        }
        fieldNum++;
    }
    if (fieldNum < 3)
    {
        cerr << "Error. Incorrect data." << endl;
        cerr << "Correct date format: XX.XX.XXXX" << endl;
        return false;
    }
    return true;
}

int main()
{
    ofstream inputFile(path + fileName, ios::app);
    if (!inputFile.is_open())
    {
        cerr << "Error. Can't open the file " << path + fileName << endl;
        return 0;
    }

    string name;
    double payment;
    string date;
    string buffer;
    bool porgramStatus = 1;
    while (porgramStatus)
    {
        do
        {
            cout << "Input name (A-Z, a-z, '-'), max 30 symbols. Ex: Ivan Ivanov" << endl;
            getline(cin, name);
        } while (input_validation_errors() || !check_name_input(name));
        inputFile << name << ",";

        do
        {
            cout << "Input payment sum" << endl;
            cin >> payment;
        } while (input_validation_errors());
        inputFile << payment << ",";

        do
        {
            cout << "Input payment data" << endl;
            getline(cin, date);
        } while (input_validation_errors() || !check_data_input(date));
        inputFile << date << endl;

        do
        {
            cout << "Continue? 1 - yes, 0 - no" << endl;
            cin >> porgramStatus;
        } while (input_validation_errors());
    }
    inputFile.close();
    return 1;
}
