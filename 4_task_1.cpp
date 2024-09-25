#include<iostream>
int main(){
    int x;
    int y;
    std::cout << "input X";
    std::cin >> x;
    std::cout >> "input Y";
    std::cin >> y;
    if (x < y){
        std::cout << "the smallest number Х" << x;
    } if else (x > y){
        std::cout << "the smallest number Y" << y;
    }else{
        std::cout << "X = Y" << y << "=" << x;
    }
}
