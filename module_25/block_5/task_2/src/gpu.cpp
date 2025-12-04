#include <iostream>
#include "ram.h"
#include "gpu.h"

using namespace std;

void print_data_from_ram(const Ram &object)
{
    if (object.dataIsInitialized)
    {
        cout << "data{" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << object.data[i] << (i != 7 ? ",\n" : "\n");
        }
        cout << "}" << endl;
    }
    else
    {
        cerr << "No data in RAM" << endl;
    }
}

void print_computed_data(const int &computedData, const bool dataIsInitialized)
{
    if (dataIsInitialized)
    {
        cout << "computed data: " << computedData << endl;
    }
    else
    {
        cerr << "Data not initialized" << endl;
    }
}