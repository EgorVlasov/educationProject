#include<iostream>
int main(){
    int x;
    std::cout << "input number: ";
    std::cin >> x;
    int remainder = x % 2;
    std::cout << "==============checking==============\n";
    if (remainder==0){
        std::cout << x << " is the even number";
    }else{
        std::cout << x << " is the odd number";
    }
}