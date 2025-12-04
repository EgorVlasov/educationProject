
#include "ram.h"
#include "cpu.h"
#include "disc.h"
#include "gpu.h"
#include "kbd.h"

int main()
{
    Ram newObject;
    while (true)
    {
        switch (get_user_command())
        {
        case 0:
            return 0;
        case 1:
            save(newObject);
            break;
        case 2:
            load(newObject);
            break;
        case 3:
            print_data_from_ram(newObject);
            break;
        case 4:
            compute(newObject);
            break;
        case 5:
            input_data(newObject);
            break;
        default:
            return 0;
        }
    }
}