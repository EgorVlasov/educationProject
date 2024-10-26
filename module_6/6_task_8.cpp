#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");
    int maxX = 63;
    int minX = 0;
    int x = maxX / 2;
    int answer;

    cout << "ЗАГАДАЙТЕ ЧИСЛО ОТ 0 ДО 63\n"
         << "данное число > " << x << " ? (1 = да, любая цифра = нет)\n";
    cin >> answer;

    if(answer == 1){
        minX = x;
    } else {
        maxX = x;
    }
    bool check = true;
    while (check) {
        if(answer == 1){
            minX = x;
                if ((maxX - minX)  > 1){
                    x += (maxX + 1 - minX) / 2;
                } else {
                    x += (maxX - minX);
                }
        } else {
            maxX = x;
                if ((maxX - minX)  > 1){
                    x -= (maxX + 1 - minX) / 2;
                } else {
                    x -= (maxX - minX);
                }
        }
        check = x + 1 < maxX && x > minX;
        cout << "данное число > " << x << " ? (1 - да, 0 - нет)\n";
        cin >> answer;
    }
    if (answer == 1){
        x += 1;
    }
    cout << "ваше число = " << x << "\n";

}