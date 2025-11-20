#include <iostream>

#define DAY_1 ("Monday")
#define DAY_2 ("Tuesday")
#define DAY_3 ("Wednesday")
#define DAY_4 ("Thursday")
#define DAY_5 ("Friday")
#define DAY_6 ("Saturday")
#define DAY_7 ("Sunday")
#define GET_DAY_NAME(num)                    \
    ((num) == 1 ? DAY_1 : (num) == 2 ? DAY_2 \
                      : (num) == 3   ? DAY_3 \
                      : (num) == 4   ? DAY_4 \
                      : (num) == 5   ? DAY_5 \
                      : (num) == 6   ? DAY_6 \
                      : (num) == 7   ? DAY_7 \
                                     : "Неверный номер")

int main()
{
    int dayNum = 0;
    std::cout << "Input day number: " << std::endl;
    std::cin >> dayNum;

    std::cout << GET_DAY_NAME(dayNum) << std::endl;
}