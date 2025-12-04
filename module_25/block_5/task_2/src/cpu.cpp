#include <iostream>
#include "cpu.h"
#include "ram.h"
#include "gpu.h"

using namespace std;

void compute(Ram &object)
{
    int computedData = 0;
    if (object.dataIsInitialized)
    {
        for (int i = 0; i < 8; i++)
        {
            computedData += object.data[i];
        }
    }
    print_computed_data(computedData, object.dataIsInitialized);
}