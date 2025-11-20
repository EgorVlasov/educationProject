#include <iostream>
// #define SPRING ("Spring")
#define SUMMER ("Summer")
// #define AUTUMN ("Autumn")
// #define WINTER ("Winter")

int main()
{
#if defined(SPRING)
    std::cout << SPRING << std::endl;
#elif defined(SUMMER)
    std::cout << SUMMER << std::endl;
#elif defined(AUTUMN)
    std::cout << AUTUMN << std::endl;
#elif defined(WINTER)
    std::cout << WINTER << std::endl;
#endif

    return 0;
}