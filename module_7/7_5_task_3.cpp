// Красный Марс
#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");
    int sideY = 15;
    int sideX = 20;
    int currentPositionY = sideY / 2;
    int currentPositionX = sideX / 2;
    
    for(char move;;){
        cout << "Марсоход находится на позиции:\n"
        << "Y = " 
        << currentPositionY 
        << "\n"
        << "X = " 
        << currentPositionX
        << "\n"
        << "Управление марсоходом: W - на север, S - на юг, A - на запад, В - на восток.\n"
        << "Введите команду: ";
        cin >> move;

        if((move == 'w' || move == 'W') && currentPositionY < sideY){
            currentPositionY += 1;
        } else if((move == 's' || move == 'S') && currentPositionY > 0){
            currentPositionY -= 1;
        } else if((move == 'd' || move == 'D') && currentPositionX < sideX){
            currentPositionX += 1;
        } else if((move == 'a' || move == 'A') && currentPositionX > 0){
            currentPositionX -= 1;
        }

    }
}