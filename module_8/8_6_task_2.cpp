// Immolate Improved!
#include <iostream>
#include <locale.h>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    float health, magicResistance, magicDamange;
    bool inputValidation;
    cout << "введите уровень здоровья вашего персонажа от 0 до 1 (уровень здоровья не может ровняться 0): ";
     do{
        inputValidation = true;            
        cin >> health;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(health <= 0 || health > 1 ){
            cerr << "Ошибка ввода данных. Значение здоровья персонажа не может быть меньше или ровняться нулюнулю, а так же превышать единицу. Введите значение еще раз.\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    cout << "введите значение сопротивления магии от 0 до 1: ";
    do{
        inputValidation = true;
        cin >> magicResistance;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(magicResistance < 0 || magicResistance > 1){
            cerr << "Ошибка ввода данных. Сопротивление магии не может быть меньше нуля или больше единицы. Введите значение еще раз.\n";
        } 
        else{
            inputValidation = false;
        }
    } while(inputValidation);

    do{
        cout << "введите значение магического урона от 0 до 1 (магический урон не может ровняться 0): ";
        do{
            cin >> magicDamange;
            inputValidation = true;
            if (cin.fail() || cin.peek() != '\n'){
                cerr << "Ошибка ввода данных. введите значение еще раз\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if(magicDamange <= 0 || magicDamange > 1){
                cerr << "Ошибка ввода данных. Значение магического урона не может быть меньше или ровняться нулю. Введите значение еще раз.\n";
            } else{
                inputValidation = false;
            }      
        } while(inputValidation);

        float damageReceived = magicDamange * magicResistance;
        if(magicResistance == 0){
            damageReceived = magicDamange;
        }
        cout << "текущий уровень здоровья: " << health << "\n"
            << "нанесенный урон: " << magicDamange << "\n"
            << "сопротивление магии: " << magicResistance << "\n"
            << "полученный урон: " << damageReceived << "\n";
        health -= damageReceived;
        if(health < 0){
            health = 0;
        }
        cout << "Остаток здоровья: " << health << "\n";  
    } while(health > 0);

    cout << "ваш герой мертв \n";

    return 0;

}