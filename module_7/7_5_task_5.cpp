// Координатные оси
#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");
    int maxY = 20;
    int maxX = 50;

    for (int y = 0; y <= maxY; y++) {
        for (int x = 0; x <= maxX; x++) {
            if (y == (maxY / 2) && x == (maxX / 2)) {
                cout << "+";
            }
            if (y == (maxY / 2)) {
                if(x == maxX) {
                    cout << ">";
                } else {
                    cout << "-";
                }
            } else if (x == (maxX / 2)) {
                if(y == 0) {
                    cout << "^";
                } else {
                    cout << "|";
                }
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}