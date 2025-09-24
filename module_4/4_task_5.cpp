#include <iostream>

int main(){
    int x;
    int y;
    std::cout << "input X: ";
    std::cin >> x;
    std::cout << "input Y: ";
    std::cin >> y;
    int remainder = x % y;
    int result = x/y;
    if(remainder == 0){
        std::cout << x << " is divisible by " << y << " without remainder.\n";
        std::cout << "result = " << result;
    }else{
        std::cout << x << " is divisible by " << y << " with remainder.\n" ;
        std::cout << "result = " << result << "\n";
        std::cout << "remainder = " << remainder << "\n";

    }
}