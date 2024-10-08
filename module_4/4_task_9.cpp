#include <iostream>

int main() {
    float profit;
    std::cout << "Your profit: ";
    std::cin >> profit;

    if (profit >= 50000) {
        float tax = (profit-50000) * 30 / 100 + 9300;
        std::cout << "Tax (30%) = " << tax << "\n";
    } else if (profit >= 10000) {
        float tax = (profit-10000) * 20 / 100 + 1300;
        std::cout << "Tax (20%) = " << tax << "\n";
    } else if (profit > 0) {
        float tax = profit * 13 / 100;
        std::cout << "Tax (13%) = " << tax << "\n";
    } else if (profit == 0) {
        std::cout << "Are you sure? No profit? Can we check?\n";
    } else {
        std::cout << "no negative number\n";
    }
}
