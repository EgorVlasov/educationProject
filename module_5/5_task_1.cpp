#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL,".UTF8");
    
    int altitude;
    cout << "введите высоту полета: ";
    cin >> altitude;

    int speed;
    cout << "введите скорость полета: ";
    cin >> speed;

    if ((speed >=750 && speed <= 850) && (altitude >=9000 && altitude <= 9500)) {
        cout << "верный эшелон";
    } else {
        cout << "неверный эшелон";
    }
}