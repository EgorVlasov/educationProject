#include <iostream>

int main () {
    int experience;
    std::cout << "Enter the number of experience points:";
    std::cin >> experience;
    std::cout << "=========Processing=========\n";
    if (experience < 0 ) {
        std::cout << "incorrect input data. experience can't be < 0 ";
    } else if (experience >= 0 && experience < 1000){
        std::cout << "Your level: 1";
    } else if (experience >= 1000 && experience < 2500 ){
        std::cout << "Your level: 2";
    } else if (experience >= 2500 && experience < 5000 ){
        std::cout << "Your level: 3";
    } else {
        std::cout << "Your level: 4 (max)";
    }
}