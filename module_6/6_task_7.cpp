#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "Введите числитель: ";
    int x;
    cin >> x;

    cout << "Введите знаменатель: ";
    int y;
    cin >> y;

    int devider = 1;

    while(x % devider != 0 && y % devider != 0){
        ++devider;
    }

    while(x % devider == 0 && y % devider == 0){
        x /= devider;
        y /= devider;
    }

    cout << x << "/" << y;

}