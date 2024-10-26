#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "введите порядковый номер числа Фибоначчи: ";
    int x;
    cin >> x;
    int counter = 0;
    int number = 1;
    int previousNumber = 0;
    if (x > 0){
        while (x > counter) {
            int newNumber = number + previousNumber;
            previousNumber = number;
            if (counter < 1) previousNumber -= 1;
            number = newNumber;
            ++ counter;
            cout << counter << ". " << number << "\n";
            if (number >= 1836311903) break;
        }
        if (x == counter){
            cout << "число Фибоначчи под порядковым номером " << x << " = " << number;
        } else {
            cout << "ошибка. слишком большое число";
        }
    } else {
        cout << "число не может равняться 0 или быть отрицательным";
    }
    
}