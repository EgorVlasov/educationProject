#include <iostream>

int main(){
    int dayNumber;
    std::cout << "input number of day of the week to see 'buisiness-lanch' menu:\n"
              << "Mon - 1\n"
              << "Tue - 2\n"
              << "Wed - 3\n"
              << "Thu - 4\n"
              << "Fri - 5\n"
              << "Sat - 6\n"
              << "Sun - 7\n";
    std::cin >> dayNumber;
    if (dayNumber == 1 ){
        std::cout << "Menu for Monday:\n"
                  << "Borsch\n"
                  << "Сutlet with mashed potatoes\n"
                  << "Tea\n"
                  << "Cheescake\n";
    } else if (dayNumber == 2){
        std::cout << "Menu for Tuesday:\n"
                  << "Borsch since Monday\n"
                  << "Сutlet with mashed potatoes from since Monday\n"
                  << "today's tea\n"
                  << "Cheescake since Monday\n";
    } else if (dayNumber == 3){
        std::cout << "Menu for Wednesday:\n"
                  << "Chiken soup\n"
                  << "Fish and chips\n"
                  << "Coffee\n"
                  << "Donut\n";
    } else if (dayNumber == 4){
        std::cout << "Menu for Thuesday:\n"
                  << "Chiken soup since Wednesday\n"
                  << "Fish and chips since Wednesday\n"
                  << "today's сoffee\n"
                  << "Donut since Wednesday\n";
    } else if (dayNumber == 5){
        std::cout << "Thuesday - Sanitary day. The cafe is closed\n";
    } else if (dayNumber == 6 || dayNumber == 7){
        std::cout << "we have no 'buisiness-lanch' on hollydays \n";
    } else {
        std::cout << "incorrect day number!!! \n";
    }
}