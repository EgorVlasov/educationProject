// Убийца Steam
#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    float startAmplitude, minAmplitude;
    int swingCount = 0;
    bool inputValidation;

    cout << "Введите начальную амплитуду колебания (см): ";
    do{
        inputValidation = true;
        cin >> startAmplitude;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(startAmplitude <= 0){
            cerr << "Ошибка ввода данных. Амплитуда не может быть меньше или равно 0. Введите значение еще раз.\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    cout << "Введите конечную амплитуду колебания (см): ";
    do{
        inputValidation = true;
        cin >> minAmplitude;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(minAmplitude <= 0 || minAmplitude >= startAmplitude){
            cerr << "Ошибка ввода данных. Амплитуда не может быть меньше или равно 0 или быть больше либо равной начальной амплитуде. Введите значение еще раз.\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    do{
        ++swingCount;
        // ТЧ - 8.4% = ТЧ * (1 - 8,4 / 100) = ТЧ * 0,916
        startAmplitude *= 0.916f;
        cout << "колебание " << swingCount << "\n"
            << "текущая амплидута колебания: " << startAmplitude << "\n";
    } while(startAmplitude > minAmplitude);

    cout << "маятник совершил " << swingCount << " колебаний\n";

    return 0;
}