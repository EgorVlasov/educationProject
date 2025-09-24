#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "сумма вашего вклада: ";
    int debit;
    cin >> debit;
    
    cout << "процентная ставка: ";
    int interestRate;
    cin >> interestRate;

    if (interestRate <= 100 && interestRate > 0){

        cout << "желаемая сумма: ";
        int desiredDebit;
        cin >> desiredDebit;

        if (desiredDebit > debit) {
            int year;
            while (debit < desiredDebit){
            debit += debit*interestRate/100;
            ++year;
            cout << debit << "\n";
            }
            cout << "вам потребуется " << year << " года (лет)";

        } else {
            cout << "вам нет смысла вкладывать деньги, если желаемая сумма меньше или равна вашему вкладу";
        }

    } else {
        cout << "процентная ставка не может быть выше 100%, так же она не может равняться 0 или быть отрицательной";
    }


}