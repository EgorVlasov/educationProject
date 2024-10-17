#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "введите число: ";
    int x;
    cin >> x;

    int counter = 0;
    if (x == 0) counter = 1;
    while (x != 0) {
        x /= 10;
        ++counter;
    }
    
    cout << "в числе " << counter << " знак(ов)";
}