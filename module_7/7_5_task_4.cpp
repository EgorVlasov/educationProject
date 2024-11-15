// Красный Марс
#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    int width;
    int hight;

    cout << "введите ширину и высоту: ";
    cin >> width >> hight;
    if(width > 1 && hight > 1) {
        for(int hightCounter = 1; hightCounter <= hight; hightCounter++) {
            cout << "|";
            for(int widthCounter = 2; widthCounter < width; widthCounter++) {
                if(hightCounter == 1 || hightCounter == hight) {
                    cout << "-";
                } else {
                    cout << " ";
                }
            }
            cout << "|\n";
        }
    } else {
        cout << "ширина и высота не могут быть < 2\n";
    }
}