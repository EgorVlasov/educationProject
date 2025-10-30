#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Employees
{
    string name;
    double payment = 0;
    string date;
};

const string path = "/Users/evlasov/Documents/educationProject/module_21/block_5/add_files/";
const string fileName = "sheet.bin";

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
bool is_year_leap(int &year)
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
bool is_input_data_correct(string &inputDate)
{
    if (inputDate.length() > 10 || inputDate.length() < 8)
    {
        cerr << "Error. Incorrect date." << endl;
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
                cerr << "Error. Incorrect date." << endl;
                return false;
            }
            if (day < 0 || day > 31)
            {
                cerr << "Error. Incorrect date." << endl;
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
                cerr << "Error. Incorrect date." << endl;
                return false;
            }
            if (month < 0 || month > 12)
            {
                cerr << "Error. Incorrect date." << endl;
                cerr << "Only 12 months in the year." << endl;
                return false;
            }
            else if (month == 2 && day > 29)
            {
                cerr << "Error. Incorrect date." << endl;
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
                cerr << "Error. Incorrect date." << endl;
                return false;
            }
            if (year < 0 || year > 2026)
            {
                cerr << "Error. Incorrect date." << endl;
                cerr << "The date cannot be from the future" << endl;
                return false;
            }
            else if (!is_year_leap(year) && month == 2 && day > 28)
            {
                cerr << "Error. Incorrect date." << endl;
                cerr << year << " is not a leap year, February cannot have more than 28 days." << endl;
                return false;
            }
            break;
        case 3:
            cerr << "Error. Incorrect date." << endl;
            cerr << "Correct date format: XX.XX.XXXX" << endl;
            return false;
        }
        fieldNum++;
    }
    if (fieldNum < 3)
    {
        cerr << "Error. Incorrect date." << endl;
        cerr << "Correct date format: XX.XX.XXXX" << endl;
        return false;
    }
    return true;
}

void input_data(Employees &employee)
{
    do
    {
        cout << "Input name (A-Z, a-z, '-'), max 30 symbols. Ex: Ivan Ivanov" << endl;
        getline(cin, employee.name);
    } while (has_input_error() || !is_input_name_correct(employee.name));

    do
    {
        cout << "Input payment sum" << endl;
        cin >> employee.payment;
    } while (has_input_error());

    do
    {
        cout << "Input payment data" << endl;
        getline(cin, employee.date);
    } while (has_input_error() || !is_input_data_correct(employee.date));
}

void add_to_sheet(const Employees &employee, bool &isFatalError)
{
    ofstream sheetFile(path + fileName, ios::binary | ios::app);
    if (!sheetFile.is_open())
    {
        cerr << "Fatal error. Can't open the sheet." << endl;
        cerr << "Program will be closed." << path + fileName << endl;
        isFatalError = true;
        return;
    }
    size_t len = employee.name.length();
    sheetFile.write(reinterpret_cast<const char *>(&len), sizeof(len));
    sheetFile.write(employee.name.c_str(), len);
    sheetFile.write(reinterpret_cast<const char *>(&employee.payment), sizeof(employee.payment));
    len = employee.date.length();
    sheetFile.write(reinterpret_cast<const char *>(&len), sizeof(len));
    sheetFile.write(employee.date.c_str(), len);
    sheetFile.close();

    cout << "Data was added." << endl;
}

void get_from_sheet(Employees &employee, bool &isFatalError)
{
    ifstream sheetFile(path + fileName, ios::binary);
    if (!sheetFile.is_open())
    {
        cerr << "Fatal error. Can't open the sheet." << endl;
        cerr << "Program will be closed." << path + fileName << endl;
        isFatalError = true;
        return;
    }
    while (sheetFile.peek() != EOF)
    {
        size_t len;
        if (sheetFile.read(reinterpret_cast<char *>(&len), sizeof(len)))
        {
            employee.name.resize(len);
            if (!sheetFile.read(employee.name.data(), len))
            {
                cerr << "Error. Can't read field 'name'" << endl;
                employee.name = "ERROR";
            }
        }
        else
        {
            cerr << "Error. Can't read field 'name'" << endl;
            employee.name = "ERROR";
        }

        cout << employee.name << " ";

        if (!sheetFile.read(reinterpret_cast<char *>(&employee.payment), sizeof(employee.payment)))
        {
            cerr << "Error. Can't read field 'payment'" << endl;
            employee.payment = 0;
        }

        cout << employee.payment << " ";

        if (sheetFile.read(reinterpret_cast<char *>(&len), sizeof(len)))
        {
            employee.date.resize(len);
            if (!sheetFile.read(employee.date.data(), len))
            {
                cerr << "Error. Can't read field 'date'" << endl;
                employee.date = "ERROR";
            }
        }
        else
        {
            cerr << "Error. Can't read field 'date'" << endl;
            employee.date = "ERROR";
        }

        cout << employee.date << endl;
    }
    sheetFile.close();
}

bool is_valid_command(int command)
{
    if (command != 1 && command != 2 && command != 0)
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
    do
    {
        cout << "=== MENU ===" << endl;
        cout << "'1' - show list" << endl;
        cout << "'2' - add to list" << endl;
        cout << "'0' - exit" << endl;
        cin >> command;
    } while (has_input_error() || !is_valid_command(command));
    return command;
}

int main()
{
    bool isFatalError = 0;
    ifstream sheetFile(path + fileName);
    if (!sheetFile.is_open())
    {
        cerr << "Error. Can't open the file." << path + fileName << endl;
        cerr << "Trying to create a new sheet..." << path + fileName << endl;
        ofstream sheetFile(path + fileName);
        if (!sheetFile.is_open())
        {
            cerr << "Fatal error. Can't creat a new sheet." << path + fileName << endl;
            cerr << "Program will be closed." << path + fileName << endl;
            return 1;
        }
        cout << "SUCCESS" << endl;
        sheetFile.close();
    }
    sheetFile.close();
    while (!isFatalError)
    {
        Employees employee;

        switch (get_user_command())
        {
        case 1:
            get_from_sheet(employee, isFatalError);
            break;
        case 2:
            input_data(employee);
            add_to_sheet(employee, isFatalError);
            break;
        case 0:
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
    return 0;
}
