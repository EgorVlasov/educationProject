#include <iostream>

int main (){
    int salary1;
    int salary2;
    int salary3;
    int hightestSalary;
    int lowestSalary;
    std::cout << "input employee's salaty 1: ";
    std::cin >> salary1;
    std::cout << "input employee's salaty 2: ";
    std::cin >> salary2;
    std::cout << "input employee's salaty 2: ";
    std::cin >> salary3;
    std::cout << "=============processing=============\n";
    if (salary1 > 0 && salary2 > 0 && salary3 > 0){
        hightestSalary = salary3;
        lowestSalary = salary1;
        if (salary1 > salary2 && salary1 > salary3) {
            hightestSalary = salary1;
            lowestSalary = salary2;
            if (salary2 > salary3) {
                lowestSalary = salary3;
            }
        } else if (salary2 > salary1 && salary2 > salary3) {
            hightestSalary = salary2;
            if (salary1 > salary3) {
                lowestSalary = salary3;
            }
        }
        std::cout << "hightest salary: " << hightestSalary << " RUB\n";
        std::cout << "lowest salary: " << lowestSalary << " RUB\n";
        std::cout << "the difference between the highest salary and the lowest: " << hightestSalary - lowestSalary << " RUB\n";
        std::cout << "arithmetic average salary: " << (salary1 + salary2 + salary3)/3 << " RUB\n";  
    } else {
        std::cout << "Workers of the world UNITE! You should be paid money for your work!";
    }





    
}