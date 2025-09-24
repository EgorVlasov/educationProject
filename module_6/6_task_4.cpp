#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "введите номер билета: ";
    int x;
    cin >> x;
    int digitCount = 0;
    {
        int y = x;
        while (y > 0){
            y /= 10;
            ++digitCount;
        }
    }
        
    if (digitCount % 2 == 0){
        //можно и через цикл посчитать делитель, но так проще
        int divider = pow(10, (digitCount / 2));

        int digitLeftPart = x / divider;
        int digitRightPart = x - digitLeftPart * divider;

        int digitLeftPartSum = 0;
        while (digitLeftPart >= 1) {
            int digitLeftPartLastDigit = digitLeftPart % 10;
            digitLeftPart /= 10;
            digitLeftPartSum += digitLeftPartLastDigit;
        }

        int digitRightPartSum = 0;
        while (digitRightPart >= 1) {
            int digitRightPartLastDigit = digitRightPart % 10;
            digitRightPart /= 10;
            digitRightPartSum += digitRightPartLastDigit;
        }

        if (digitLeftPartSum == digitRightPartSum){
            cout << "поздравляю! вы добыли счастливый билет";
        } else {
            cout << "в это раз не повезло, билет не счтастливый";
        }
    } else {
        cout << "номер билета должен иметь четное кол-во цифр";
    }
}