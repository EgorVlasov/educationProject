#include <iostream>
#include <locale.h>
#include <string>
#include <ctime>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");
    
    cout << "=== Грустное совершеннолетие ===\n";
    cout << "\n";

    int clientBirthDay;
    int clientBirthMonth;
    int clientBirthYear;
    cout << "Чтобы узнать можно ли вам сегодня выпить, введите дату (число, месяц, год через пробел) вашего рождения: ";
    cin >> clientBirthDay >> clientBirthMonth >> clientBirthYear;

    time_t t;
    time(&t);
    tm* currentDate = localtime(&t);
    int currentYear = currentDate -> tm_year + 1900;

    if (clientBirthYear > 1900 && clientBirthYear < currentYear){
        if (clientBirthMonth >= 1 && clientBirthMonth <= 12) {

            int daysInMonth;
            
            if (clientBirthMonth == 1 || clientBirthMonth == 3 || clientBirthMonth == 5 || clientBirthMonth == 7 || clientBirthMonth == 8 || clientBirthMonth == 10 || clientBirthMonth == 12) {
                daysInMonth = 31;
            } else if (clientBirthMonth == 4 || clientBirthMonth == 6 || clientBirthMonth == 9 || clientBirthMonth == 11) {
                daysInMonth = 30;
            } else if (clientBirthYear % 400 == 0 || (clientBirthYear % 4 == 0 && clientBirthYear % 100 != 0)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }

            if (clientBirthDay > 0 && clientBirthDay <= daysInMonth) {

                if (currentYear - clientBirthYear > 18) {
                    std::cout << "Бармен, наливай!";
                } else if (currentYear - clientBirthYear == 18) {

                    int currentMonth = currentDate -> tm_mon + 1;

                    if (clientBirthMonth > currentMonth) { 
                        std::cout << "Бармен, наливай!";
                    } else if (clientBirthMonth == currentMonth) {

                        int currentDay = currentDate -> tm_mday;

                        if (clientBirthDay > currentDay) {
                            std::cout << "Бармен, наливай!";
                        } else if (clientBirthDay == currentDay) {
                            std::cout << "Не сегодня, друг! Приходи завтра.";
                        } else {
                            std::cout << "Вы слишком молоды для выпивки!";
                        }

                    } else {
                        std::cout << "Вы слишком молоды для выпивки!";
                    }

                } else {
                    std::cout << "Вы слишком молоды для выпивки!";
                }
            } else {
                std::cout << "неврный день. В " 
                        << clientBirthMonth 
                        << " месяце " 
                        << clientBirthYear 
                        << " года, всего " 
                        << daysInMonth 
                        << " дней(день). Введите значение от 1 до " 
                        << daysInMonth;
            }
        } else {
            std::cout << "неврный месяц. Введите значение от 1 до 12";
        }
    } else {
        std::cout << "неврный год. Вы не могли родиться раньше 1900 года (столько не живут) и вы не похожи на путешественника во времени, чтобы прилететь из будущего.";
    }
}