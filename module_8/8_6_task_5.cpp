// Убийца Steam
#include <iostream>
#include <locale.h>
#include <thread>
#include <cmath>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    int AvrRate, totalRate, distance;
    bool inputValidation;

    cout << "Привет, Сэм! Сколько километров ты сегодня пробежал?: ";
    do{
        inputValidation = true;
        cin >> distance;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(distance <= 0){
            cerr << "Ошибка ввода данных. Расстояние не может быть меньше или равно 0. Введите значение еще раз.\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    for(int distanceCounter, rate; distanceCounter < distance; distanceCounter++){
        cout << "какой у тебя был темп на километре " << distanceCounter << "?";
        do{
            inputValidation = true;
            cin >> rate;
            if (cin.fail() || cin.peek() != '\n'){
                cerr << "Ошибка ввода данных. введите значение еще раз\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if(distance <= 0){
                cerr << "Ошибка ввода данных. Темп не может быть меньше или равен 0. Введите значение еще раз.\n";
            } else{
                inputValidation = false;
            }
        } while(inputValidation);

        totalRate += rate;
    } 

    AvrRate = round(totalRate / distance);
    cout << "Твой средний темп за тренировку: " << AvrRate / 60 << " минуты " << AvrRate % 60 << "секунд.\n"


    return 0;
}
