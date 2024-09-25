#include<iostream>
int main(){
    int x;
    int y;
    int z;
    std::cout << "input 1st number ";
    std::cin >> x;
    std::cout << "input 2nd number ";
    std::cin >> y;
    std::cout << "input sum ";
    std::cin >> z;
    std::cout << "==============checking==============\n";
    if (x + y == z){
        std::cout << "Right!";
    } else{
        std::cout << "You made a mistake";
    }
}