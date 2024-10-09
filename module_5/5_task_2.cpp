#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "====Задание 3. Майские — усложнение====\n\n";

    int firstDateMonthIsWeekDayNumber;
    cout << "С какого дня недели начинается месяц? Введите число от 1 до 7: ";
    cin >> firstDateMonthIsWeekDayNumber;

    string mainMessage = "это рабочий день";

    if (firstDateMonthIsWeekDayNumber > 0 && firstDateMonthIsWeekDayNumber < 8){
        int currentDate;
        cout << "Какое сегодня число? введите число от 1 до 31: ";
        cin >> currentDate;
        if (currentDate < 0 || curentDate > 31) {
            mainMessage = "вы ввели неверное число";
        } else if ((currentDate >= 1  && currentDate <= 5)  || (currentDate >= 8 && currentDate <= 10)) {
            mainMessage = "это выходной'";
            //если месяц начинается с 1го дня недели, то текущее число, кратное 7 = воскр.
            //суббота = (текущее число + 1) кратное 7
            //если месяц начинается НЕ с 1го дня недели, то воскр = (текущее число + номер дня недели с которого начался месяц) кратное 7
            //суббота = (текущее число + номер дня недели с которого начался месяц +1) кратное 7
            //тк нумерация дня недели у нас идет не с 0, а с 1, а в случае если месяц начинается 1го дня недели, нам сдвигать ничего не нужно, то 1 нужно вычесть
        } else if ((currentDate + firstDateMonthIsWeekDayNumber - 1) % 7 == 0 || (currentDate + firstDateMonthIsWeekDayNumber) % 7 == 0) {
            mainMessage = "это выходной'";
        }
    } else {
        mainMessage = "вы ввели неверный день недели";

    }

    cout << mainMessage;
}