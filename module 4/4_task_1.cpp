#include<iostream>
int main(){
    int x;
    int y;
    std::cout << "input X ";
    std::cin >> x;
    std::cout << "input Y ";
    std::cin >> y;
    std::cout << "==============checking==============\n";
    if (x < y){
        std::cout << "the smallest number X = " << x;
    } else if (x > y){
        std::cout << "the smallest number Y = " << y;
    }else{
        std::cout << "X = Y = " << y << " = " << x;
    }
}
