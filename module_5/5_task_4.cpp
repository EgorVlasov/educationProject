#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "=== Банкомат — 2 ===\n";

    int sum;
    cout << "введите сумму, котую хотите снять: ";
    cin >> sum;

    if (sum >= 100 && sum <= 150000){
        if (sum % 100 == 0){
            cout << "получите наличные купюры на сумму " << sum << "\n";
            int remains = sum;
            if (remains >= 5000){
                int billsNumber = remains / 5000;
                cout << "5 000 в количестве: " << billsNumber << "\n";
                remains %= 5000;
            }
            if (remains >= 2000){
                int billsNumber = remains / 2000;
                cout << "2 000 в количестве: " << billsNumber << "\n";
                remains %= 2000;
            }
            if (remains >= 1000) {
                int billsNumber = remains / 1000;
                cout << "1 000 в количестве: " << billsNumber << "\n";
                remains %= 1000;
            }
            if (remains >= 500) {
                int billsNumber = remains / 500;
                cout << "500 в количестве: " << billsNumber << "\n";
                remains %= 500;
            }
            if (remains >= 200) {
                int billsNumber = remains / 200;
                cout << "200 в количестве: " << billsNumber << "\n";
                remains %= 200;
            }
            if (remains == 100) {
                int billsNumber = remains / 100;
                cout << "100 в количестве: " << billsNumber << "\n";
            }
        } else{
        cout << "Неверная сумма. Банкомат может выдавать только купюры 100, 200, 500, 1 000, 2 000 и 5 000 руб\n"
             << "мы не сможем вам выдать " << sum % 100 << " руб остатка";
        }
    } else{
        cout << "За раз нельзя снять больше 150 000 руб и меньше 100 руб";
    }
}