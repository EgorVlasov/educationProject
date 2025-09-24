#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    cout << "Который час? (без минут и секунд) ";
    int hourNow;
    cin >> hourNow;

    int counter = 1;
    if(hourNow > 0 && hourNow < 25){
        while(hourNow >= counter) {
            cout << "ку-ку\n";
            ++ counter;
        }
    } else if(hourNow == 0){
        cout << "ку-ку х12 раз. В принципе можно и через цикл.";
    } else{
        cout << "время не может быть отрицательным, а в сутках не может быть больше 24ч";
    }


}