//Задание 1. Шифр Цезаря
#include <iostream>
#include <string>

using namespace std;

int main () {
    int number;
    
    cout << "Enter the number [1 - 3999]:\n";
    bool inputValidation;
    do{
        inputValidation = true;
        cin >> number;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(number < 1 || number > 3999){
            cerr << "Input error. Try again\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);