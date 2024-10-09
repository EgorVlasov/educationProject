#include <iostream>
#include <setlocale.h>
#include <string>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "===Банкомат — 2===";

    int sum;
    cout << "введите сумму, котую хотите снять: ";
    cin >> sum;

    if (sum <= 150000){

    }else{
        cout << "За раз нельзя снять больше 150 000 рублей";
    }
}