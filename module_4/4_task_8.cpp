#include <iostream>

int main (){
    int salary1;
    int salary2;
    int salary3;
    int maxSalary;
    int minSalary;
    std::cout << "input employee's salary 1: ";
    std::cin >> salary1;
    std::cout << "input employee's salary 2: ";
    std::cin >> salary2;
    std::cout << "input employee's salary 3: ";
    std::cin >> salary3;
    std::cout << "=============processing=============\n";
    if (salary1 > 0 && salary2 > 0 && salary3 > 0){
        maxSalary = salary3;
        minSalary = salary1;
        if (salary1 > salary2) {
            maxSalary = salary1;
            minSalary = salary2;
            if (salary1 < salary3) maxSalary = salary3;
            if (salary2 > salary3) minSalary = salary3;
        }
        if (salary2 > salary3){
            maxSalary = salary2;
            if (salary1 > salary3) minSalary = salary3;
        }
        std::cout << "hightest salary: " << maxSalary << " RUB\n";
        std::cout << "lowest salary: " << minSalary << " RUB\n";
        std::cout << "the difference between the highest salary and the lowest: " << maxSalary - minSalary << " RUB\n";
        std::cout << "arithmetic average salary: " << (salary1 + salary2 + salary3)/3 << " RUB\n";  
    } else {
        std::cout << "Workers of the world UNITE! You should be paid money for your work!";
    }
}