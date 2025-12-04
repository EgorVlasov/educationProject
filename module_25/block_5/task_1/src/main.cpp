#include <iostream>
#include "operationtools.h"
#include "userinterface.h"

using namespace std;

const int maxUserCommandValue = 4;

int main()
{
    OperationStatus newOperation;

    while (true)
    {
        switch (get_user_command(maxUserCommandValue))
        {
        case 0:
            if (newOperation.isSutured && !newOperation.isCuted)
            {
                return 0;
            }
            else
            {
                cerr << "Error. You can't finish operation" << endl;
            }
        case 1:
            scalpel(newOperation);
            break;
        case 2:
            hemostat(newOperation);
            break;
        case 3:
            tweezers(newOperation);
            break;
        case 4:
            suture(newOperation);
            break;

        default:
            return 0;
            break;
        }
    }
}