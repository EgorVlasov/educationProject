// Ёлочка* (дополнительное задание)
#include <iostream>
#include <locale.h>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    int lineCnt;
    cout << "введите количество строк: ";
    cin >> lineCnt;
    if(lineCnt > 0) {
        for(int totalSymbols = (lineCnt * 2 - 1), sharpCnt = 1, lineCounter = 0; lineCounter <= lineCnt; lineCounter++) {
            for(int spaceCnt = (totalSymbols - sharpCnt) / 2, spaceCounter = 0; spaceCounter <= spaceCnt; spaceCounter++){
                cout << " ";
            }
            for(int sharpCounter = 0; sharpCounter < sharpCnt; sharpCounter++) {
            cout << "#"; 
            }
            cout << "\n"; 
            sharpCnt += 2;
        }
    } else {
        cout << "ОШИБКА. Количество строк должно быть больше 0"; 
    }
}