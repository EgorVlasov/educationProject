// Космический симулятор
#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    int m, f, t;
    bool cinCheck;

    cout << "введите значение массы корабля: ";
    do{
        cinCheck = true;
        cin >> m;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(m <= 0 ){
            cerr << "Ошибка ввода данных. Значение массы не может быть меньше или ровняться нулюнулю. Введите значение еще раз.\n";
        } else{
            cinCheck = false;
        }
    } while(cinCheck);

    cout << "введите значение силы тяги двигателя корабля: ";
    do{
        cinCheck = true;
        cin >> f;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(f <= 0 ){
            cerr << "Ошибка ввода данных. Сила тяги не может быть меньше или ровняться нулю. Введите значение еще раз.\n";
        } 
        else{
            cinCheck = false;
        }
    } while(cinCheck);

    cout << "введите время полета: ";
    do{
        cin >> t;
        cinCheck = true;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(t <= 0 ){
            cerr << "Ошибка ввода данных. Значение времени не может быть меньше или ровняться нулю. Введите значение еще раз.\n";
        } else{
            cinCheck = false;
        }      
    } while(cinCheck);

    float a = f / m; // ускорение
    float s = a * pow(t, 2) / 2; // расстояние

    cout << "корабль с мощностью двигателя " 
        << f << " Н и массой "   
        << m << " кг движется с постоянным ускорением " 
        << a << " м/с^2, за "  
        << t << " с пройдет расстояние " 
        << s << " м\n";

    return 0;
}