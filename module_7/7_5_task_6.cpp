// Важные объявления
#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    int headerLength;
    int exclamationsCount;

    cout << "введите общую длинну колонтитула: ";
    cin >> headerLength;
    cout << "введите количество восклицательных знаков: ";
    cin >> exclamationsCount;
    if((headerLength - exclamationsCount) > 1) {
        for(int charactersCounter = 0; charactersCounter <= (headerLength - exclamationsCount); charactersCounter++) {
            if(charactersCounter == ((headerLength - exclamationsCount) / 2)) {
                for(int counter = 1; counter <= exclamationsCount; counter++) {
                    cout << "!";
                }
            } else {
                cout << "~";
            }
        }
    } else {
        cout << "общая длинна колонтитула должна быть больше минимум на 2 знака, чем количество восклицательных знаков.";
    }
}