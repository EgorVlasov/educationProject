//Задание 1. Многоквартирный дом
#include <iostream>
#include <string>



int main() {
    string names[10];

    cout << "Enter names: \n";
    for(int i = 0; i < 10; ++i){
        cout << "Flat# " << i + 1 << ": ";
        cin >> names[i];
    }

    for(int i = 0; i < 3; i++){
        int flatNumber;
        cout << "Enter the flat number (1 -10): \n";
        cin >> flatNumber;
        if(flatNumber > 0 && flatNumber < 11){
            cout << "in this flat lives " << names[flatNumber - 1] << "\n";
        } else{
            cout << "Wrong flat number\n";
            --i;
        }
    }
}   