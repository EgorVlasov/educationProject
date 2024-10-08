#include <iostream>

int main() {
    int mansCount;
    int barbersCount;

    std::cout << "************** barbershop-calculator **************\n";
    std::cout << "Input how many men live in the city: ";
    std::cin >> mansCount;
    std::cout << "Input how many barbers work: ";
    std::cin >> barbersCount;
// при условии, что один барбер работает 8 часов в день и на одного клиента тратит 1 час, т.е. 240 клиентов \ мес
    int requiredBarbersCount = mansCount / 240;
    if (mansCount % 240 > 0){
        requiredBarbersCount +=1;
    }
    if (requiredBarbersCount > barbersCount) {
        std::cout << "need more barbers!!!\n"
                  << "requiredBarbersCount: " << requiredBarbersCount << "\n"
                  << "barbersCount: " << barbersCount << "\n";
    } else if (requiredBarbersCount == barbersCount) {
        std::cout << "There are just as many barbers as you need!!!\n"
                  << "requiredBarbersCount: " << requiredBarbersCount << "\n"
                  << "barbersCount: " << barbersCount << "\n";
    } else if (barbersCount >= requiredBarbersCount * 2) {
        std::cout << "You have twice as many barbers working as you need!!!\n"
                  << "requiredBarbersCount: " << requiredBarbersCount << "\n"
                  << "barbersCount: " << barbersCount << "\n";
    } else {
        std::cout << "There are enough barbers!!!\n"
                  << "requiredBarbersCount: " << requiredBarbersCount << "\n"
                  << "barbersCount: " << barbersCount << "\n";
    }
}
