// Кофемашина
#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    int totalWater;
    cout << "Введите сколько мл воды необходимо залить в автомат";
    cin >> totalWater;
    int totalMilk;
    cout << "Введите сколько мл молока необходимо залить в автомат";
    cin >> totalMilk;

    int totalCupsAmericano;
    int totalCupsLatte;

    for (int answer; totalMilk > 0 && totalWater > 0;) {
        cout << "Выберите напиток (1 — американо, 2 — латте): ";
        cin >> answer;

        if (answer == 1) {
            totalWater -= 300;
            ++totalCupsAmericano;
        } else if (answer == 2) {
            totalWater -= 30;
            totalMilk -= 270;
            ++totalCupsLatte;
        } else {
            cout << "ОШИБКА. Невверный код напитка";
        }
    }

    cout << "***Отчёт*** \n"
        << "Ингредиентов осталось:\n"
        << "\t Вода: " << totalWater << " мл\n"
        << "\t Молоко: " << totalMilk << " мл\n"
        << "Кружек американо приготовлено:: " << totalCupsAmericano << " мл\n"
        << "Кружек латте приготовлено:: " << totalCupsLatte << " мл\n";
}