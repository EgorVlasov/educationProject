#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

const string path = "/Users/evlasov/Documents/educationProject/module_20/block_5/add_files/";
const string fileName = "wallet.bin";
const int denominations[] = {5000, 2000, 1000, 500, 200, 100};

bool has_input_error()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (cin.fail() || cin.peek() != '\n')
    {
        cerr << "Input error. Try again" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void atm_cash_inventory_initialization()
{
    cout << "Wallet initialization..." << endl;
    ofstream atmCashInventory(path + fileName, ios::binary);
    for (int i = 0; i < 6; i++)
    {
        atmCashInventory << denominations[i] << " " << 0 << endl;
    }
    cout << "SUCCESS" << endl;
    cout << "'" << fileName << "' was created. " << endl;
}

void prepare_atm_cash_inventory_cache(int atmCashInventoryСache[][2], int &totalBalanceCache)
{
    cout << "Peparing the cash..." << endl;
    ifstream atmCashInventory(path + fileName, ios::binary);
    string bufLine;
    for (int i = 0; getline(atmCashInventory, bufLine) && i < 6; i++)
    {
        stringstream ssBuffer(bufLine);
        string bufField;
        ssBuffer >> bufField;
        atmCashInventoryСache[i][0] = stoi(bufField);
        ssBuffer >> bufField;
        atmCashInventoryСache[i][1] = stoi(bufField);
        totalBalanceCache += atmCashInventoryСache[i][0] * atmCashInventoryСache[i][1];
    }
    atmCashInventory.close();
    cout << "SUCCESS" << endl;
}

void update_atm_cash_inventory(int atmCashInventoryСache[][2], bool &isFatalError)
{
    ofstream atmCashInventory(path + fileName, ios::binary);
    if (!atmCashInventory.is_open())
    {
        cerr << "Fatal error. Can't update '" << fileName << "'" << endl;
        cerr << "Operation oborted. Program will be closed.'" << fileName << "'" << endl;
        isFatalError = true;
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            atmCashInventory << atmCashInventoryСache[i][0] << " " << atmCashInventoryСache[i][1] << endl;
        }
        atmCashInventory.close();
    }
}

bool is_cache_consistent_with_cash_inventory(int atmCashInventoryСache[][2])
{
    ifstream atmCashInventory(path + fileName, ios::binary);
    string bufLine;
    int totalBalance = 0;
    int totalBalanceCache = 0;
    for (int i = 0; getline(atmCashInventory, bufLine) && i < 6; i++)
    {
        stringstream ssBuffer(bufLine);
        string bufField;
        ssBuffer >> bufField;
        int denomination = stoi(bufField);
        ssBuffer >> bufField;
        int cnt = stoi(bufField);
        totalBalance += denomination * cnt;
    }
    atmCashInventory.close();

    for (int i = 0; i < 6; i++)
    {
        totalBalanceCache += atmCashInventoryСache[i][0] * atmCashInventoryСache[i][1];
    }
    if (totalBalance != totalBalanceCache)
    {
        return false;
    }
    return true;
}

void show_atm_status(int atmCashInventoryСache[][2], const int &totalBalanceCache)
{
    string bufLine;
    cout << "=== ATM wallet status ===" << endl;
    cout << left << setw(25) << "Denomination of banknotes" << " | " << left << setw(10) << "Count" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << left << setw(25) << atmCashInventoryСache[i][0] << " | " << left << setw(10) << atmCashInventoryСache[i][1] << endl;
    }
    cout << "===================== " << endl;
    cout << "Total balance: " << totalBalanceCache << endl;
}

int get_value()
{
    int value = 0;
    do
    {
        cout << "Please input the value:" << endl;
        cin >> value;
    } while (has_input_error());
    return value;
}

bool is_amount_composable(int amount)
{
    if (amount % 100 != 0)
    {
        cerr << "This ATM can only dispense multiples of 100 rub. Please enter a different amount." << endl;
        return false;
    }
    return true;
}

void withdraw(int amount, int atmCashInventoryСache[][2], int banknotes[][2])
{
    for (int i = 0; i < 6 && amount > 0; i++)
    {
        int needed = amount / atmCashInventoryСache[i][0];
        int available = atmCashInventoryСache[i][1];
        int toUse = min(needed, available);
        atmCashInventoryСache[i][1] -= toUse;
        banknotes[i][0] = atmCashInventoryСache[i][0];
        banknotes[i][1] = toUse;
        amount -= toUse * atmCashInventoryСache[i][0];
    }
}

void cash_out(int atmCashInventoryСache[][2], int &totalBalanceCache, bool &isFatalError)
{
    int cashOutAmount = 0;
    int banknotes[6][2] = {0};
    do
    {
        cashOutAmount = get_value();
    } while (cashOutAmount > totalBalanceCache || !is_amount_composable(cashOutAmount));
    withdraw(cashOutAmount, atmCashInventoryСache, banknotes);
    totalBalanceCache -= cashOutAmount;
    update_atm_cash_inventory(atmCashInventoryСache, isFatalError);
    if (!isFatalError)
    {
        cout << "Please take your cash" << endl;
        for (int i = 0; i < 6; i++)
        {
            if (banknotes[i][1] != 0)
            {
                cout << banknotes[i][0] << " rub - " << banknotes[i][1] << endl;
            }
        }
        show_atm_status(atmCashInventoryСache, totalBalanceCache);
    }
}

void cash_in(int atmCashInventoryСache[][2], int &totalBalanceCache, bool &isFatalError)
{
    int cashInAmount = 0;
    for (int i = 0; i < 6; i++)
    {
        if (atmCashInventoryСache[i][1] == 0)
        {
            cout << "Enter the number of banknotes with a denomination of " << atmCashInventoryСache[i][0] << " rub" << endl;
            int banknotesCnt = get_value();
            atmCashInventoryСache[i][1] = banknotesCnt;
            cashInAmount += banknotesCnt * atmCashInventoryСache[i][0];
        }
    }
    totalBalanceCache += cashInAmount;
    update_atm_cash_inventory(atmCashInventoryСache, isFatalError);
    if (!isFatalError)
    {
        cout << "Collection complete" << endl;
        cout << "Balance increased for " << cashInAmount << " rub" << endl;
        show_atm_status(atmCashInventoryСache, totalBalanceCache);
    }
}

bool is_valid_command(char command)
{
    if (command != '+' && command != '-' && command != '0')
    {
        cerr << "Invalide operation code." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

char get_user_command()
{
    char command;
    do
    {
        cout << "=== ATM MENU ===" << endl;
        cout << "'+' - cash in" << endl;
        cout << "'-' - cash out" << endl;
        cout << "'0' - exit" << endl;
        cin >> command;
    } while (has_input_error() || !is_valid_command(command));
    return command;
}

int main()
{
    ifstream atmCashInventory(path + fileName, ios::binary);
    int atmCashInventoryСache[6][2] = {0};
    int totalBalanceCache = 0;
    bool isFatalError = false;

    if (!atmCashInventory.is_open())
    {
        cerr << "File '" << fileName << "' not found." << endl;
        ofstream atmCashInventory(path + fileName, ios::binary);
        if (!atmCashInventory.is_open())
        {
            cerr << "Fatal error. Can't create file '" << fileName << "'" << endl;
            return 1;
        }
        atm_cash_inventory_initialization();
        atmCashInventory.close();
    }

    prepare_atm_cash_inventory_cache(atmCashInventoryСache, totalBalanceCache);
    atmCashInventory.close();
    cout << "ATM is ready for work" << endl;

    while (!isFatalError)
    {
        if (totalBalanceCache == 0)
        {
            cout << "ATM empty. Collection required to continue." << endl;
            cash_in(atmCashInventoryСache, totalBalanceCache, isFatalError);
            cout << "ATM is ready for work" << endl;
        }
        switch (get_user_command())
        {
        case '+':
            cash_in(atmCashInventoryСache, totalBalanceCache, isFatalError);
            break;
        case '-':
            cash_out(atmCashInventoryСache, totalBalanceCache, isFatalError);
            break;
        case '0':
            if (!is_cache_consistent_with_cash_inventory(atmCashInventoryСache))
            {
                update_atm_cash_inventory(atmCashInventoryСache, isFatalError);
            }
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
    if (isFatalError)
    {
        return 1;
    }
}