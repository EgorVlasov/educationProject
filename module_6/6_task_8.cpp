#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");
    int currentMaxX = 63;
    int currentMinX = 0;
    int currentX = currentMaxX / 2;
    int answer;

    cout << "ЗАГАДАЙТЕ ЧИСЛО ОТ 0 ДО 63\n"
         << "данное число > " << currentX << " ? (1 = да, любая цифра = нет)\n";
    cin >> answer;

    if(answer == 1){
        currentMinX = currentX;
    } else {
        currentMaxX = currentX;
    }
    bool check = true;
    while (check) {
        if(answer == 1){
            currentMinX = currentX;
                if ((currentMaxX - currentMinX)  > 1){
                    currentX += (currentMaxX + 1 - currentMinX) / 2;
                } else {
                    currentX += (currentMaxX - currentMinX);
                }
        } else {
            currentMaxX = currentX;
                if ((currentMaxX - currentMinX)  > 1){
                    currentX -= (currentMaxX + 1 - currentMinX) / 2;
                } else {
                    currentX -= (currentMaxX - currentMinX);
                }
        }
        check = currentX + 1 < currentMaxX && currentX > currentMinX;
        cout << "данное число > " << currentX << " ? (1 - да, 0 - нет)\n";
        cin >> answer;
    }
    if (answer == 1){
        currentX += 1;
    }
    cout << "ваше число = " << currentX << "\n";

}