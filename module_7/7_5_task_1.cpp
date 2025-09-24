// Запасы продовольствия
#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    int totalBuckwheat = 100;
    cout << "Всего гречки было на начало подсчёта: " << totalBuckwheat << "кг\n";
    for (int month = 1; totalBuckwheat > 0; month++) {
        totalBuckwheat -= 4;
        cout << "После " << month << " месяца у вас в запасе останется " << totalBuckwheat << " кг гречки\n";
    }
}