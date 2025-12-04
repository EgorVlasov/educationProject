#include <iostream>
#include <fstream>
#include "disc.h"
#include "ram.h"

using namespace std;

void save(const Ram object)
{
    if (object.dataIsInitialized)
    {
        ofstream file("/Users/evlasov/Documents/educationProject/module_25/block_5/task_2/add_files/data.bin", ios::binary);
        if (!file.is_open())
        {
            cerr << "Fatal error. Can't save the data" << endl;
            return;
        }
        file.write(reinterpret_cast<const char *>(object.data), sizeof(object.data));
        file.close();
        cout << "Data has been saved to the disc" << endl;
    }
    else
    {
        cerr << "Data not initialized" << endl;
    }
}

void load(Ram &object)
{
    if (object.dataIsInitialized)
    {
        cout << "data has been already loaded" << endl;
        return;
    }
    ifstream file("/Users/evlasov/Documents/educationProject/module_25/block_5/task_2/add_files/data.bin", ios::binary);
    if (!file.is_open())
    {
        cerr << "Error. No data on the disc" << endl;
        return;
    }
    file.read(reinterpret_cast<char *>(object.data), sizeof(object.data));
    file.close();
    object.dataIsInitialized = true;
    cout << "Data has been loaded to RAM" << endl;
}