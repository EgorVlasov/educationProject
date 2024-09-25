#include <iostream>

int main(){
    int a = 42;
    int b = 153;
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    int c;
    c = a;
    a = b;
    b = c;

    std::cout << "new_a: " << a << "\n";
    std::cout << "new_b: " << b << "\n"; 

    a = b + a;
    b = a - b;
    a = a - b;

    std::cout << "new_new_a: " << a << "\n";
    std::cout << "new_new_b: " << b << "\n"; 

}