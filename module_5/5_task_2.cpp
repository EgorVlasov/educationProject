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
        int curentDate;
        cout << "Какое сегодня число? введите число от 1 до 31: ";
        cin >> curentDate;
        if (curentDate < 0 || curentDate > 31) {
            mainMessage = "вы ввели неверное число";
        } else if ((curentDate >= 1  && curentDate <= 5)  || (curentDate >= 8 && curentDate <= 10)) {
            mainMessage = "это выходной'";
            //если месяц начинается с 1го дня недели, то текущее число, кратное 7 = воскр.
            //суббота = (текущее число + 1) кратное 7
            //если месяц начинается НЕ с 1го дня недели, то воскр = (текущее число + номер дня недели с которого начался месяц) кратное 7
            //суббота = (текущее число + номер дня недели с которого начался месяц +1) кратное 7
            //тк нумерация дня недели у нас идет не с 0, а с 1, а если месяц начинается 1го дня недели, то нам сдвигать ничего не нужно, потому 1 нужно вычесть
        } else if ((curentDate + firstDateMonthIsWeekDayNumber - 1) % 7 == 0 || (curentDate + firstDateMonthIsWeekDayNumber) % 7 == 0) {
            mainMessage = "это выходной'";
        }
    } else {
        mainMessage = "вы ввели неверный день недели";
        
    }

    cout << mainMessage;
}